#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))
#define all(v) v.begin(),v.end()
#define MAXX 1010
#define INF 1e17

using namespace std;

struct data{
    int x,path,flights;
    long long dist;

    bool operator <(const data &p)const{
        return (dist==p.dist)? flights>p.flights:dist>p.dist;
    }
};

int N,A,B,fl[MAXX][MAXX];
long long int dist[MAXX][MAXX];
vector <int> edges[MAXX],type[MAXX];
vector <long long int> cost[MAXX];

pair<long long int, int > dijkstra(){
    priority_queue <data> pq;
    int i,j,k;
    data tmp;
    tmp.x=A;tmp.path=0;tmp.dist=(long long)0;
    tmp.flights=0;

    dist[A][0]=0;
    pq.push(tmp);

    while(!pq.empty()){

        data v=pq.top();pq.pop();

        if(v.x==B) return make_pair(v.dist,v.flights);

        for(i=0;i<edges[v.x].size();i++){

            if(type[v.x][i]==v.path){

                if(dist[edges[v.x][i]][v.path]>v.dist){
                    dist[edges[v.x][i]][v.path]=v.dist;
                    fl[edges[v.x][i]][v.path]=v.flights+1;
                    tmp.x=edges[v.x][i];
                    tmp.path=v.path;
                    tmp.dist=dist[edges[v.x][i]][v.path];
                    tmp.flights=v.flights+1;

                    pq.push(tmp);
                }else if(dist[edges[v.x][i]][v.path]==v.dist && v.flights+1<fl[edges[v.x][i]][v.path]){
                    fl[edges[v.x][i]][v.path]=v.flights+1;
                    tmp.x=edges[v.x][i];
                    tmp.path=v.path;
                    tmp.dist=dist[edges[v.x][i]][v.path];
                    tmp.flights=v.flights+1;

                    pq.push(tmp);
                }

            }else{

                if(dist[edges[v.x][i]][type[v.x][i]]>v.dist+cost[v.x][i]){
                    dist[edges[v.x][i]][type[v.x][i]]=v.dist+cost[v.x][i];
                    fl[edges[v.x][i]][type[v.x][i]]=v.flights+1;
                    tmp.x=edges[v.x][i];
                    tmp.path=type[v.x][i];
                    tmp.dist=dist[edges[v.x][i]][tmp.path];
                    tmp.flights=v.flights+1;

                    pq.push(tmp);

                }else if(dist[edges[v.x][i]][type[v.x][i]]==v.dist+cost[v.x][i] && v.flights+1<fl[edges[v.x][i]][type[v.x][i]]){
                    dist[edges[v.x][i]][type[v.x][i]]=v.dist+cost[v.x][i];
                    fl[edges[v.x][i]][type[v.x][i]]=v.flights+1;
                    tmp.x=edges[v.x][i];
                    tmp.path=type[v.x][i];
                    tmp.dist=dist[edges[v.x][i]][tmp.path];
                    tmp.flights=v.flights+1;

                    pq.push(tmp);
                }
            }
        }
    }

    return make_pair(-1,-1);

}

int main(){

    int i,j,k;
    scanf("%d %d %d",&N,&A,&B);

    for(i=0;i<N;i++){
        long long int c;
        int cit;
        int a,b;

        scanf("%d %lld",&c,&cit);

        scanf("%d",&a);

        for(j=1;j<cit;j++){
            scanf("%d",&b);
            edges[a].pb(b);
            type[a].pb(i+1);
            cost[a].pb(c);
            a=b;
        }


    }
    for(i=0;i<MAXX;i++){
            for(j=0;j<MAXX;j++) {dist[i][j]=INF;fl[i][j]=INF;}
    }

    pair<long long int,int > ans=dijkstra();

    printf("%lld %d\n",ans.first,ans.second);


    return 0;
}
