#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#define MAXX 4000
#define INF 100000000
#define pb push_back
#define MP make_pair
#define all(v) v.begin(),v.end()
#define Fr First
#define Sc Second
#define CLR(x) memset(x,0,sizeof(x))

using namespace std;

struct data{
    int u;
    int wt;

    bool operator <(const data &p) const{
        return wt>p.wt;
    }
};

struct data2{
    int pos,p;

    bool operator <(const data2 &x) const{
        return p<x.p;
    }
};


int N,M;
vector <data2> doges;
vector <data> edges[MAXX];
int p[MAXX],home[MAXX];
bool occ[MAXX];
int dist[MAXX];
bool conn[MAXX][MAXX];

int dijkstra(int src, int dest){
    priority_queue <data> pq;
    int i,j,k;

    for(i=0;i<MAXX;i++) dist[i]=INF;

    data tmp;
    tmp.u=src;tmp.wt=0;
    pq.push(tmp);
    dist[src]=0;

    while(!pq.empty()){

        data u=pq.top();pq.pop();

        if(u.u==dest) return dist[u.u];

        for(i=0;i<edges[u.u].size();i++){

            int v=edges[u.u][i].u;int wt=edges[u.u][i].wt;

            if(dist[v]>dist[u.u]+wt){
                tmp.u=v;
                tmp.wt=dist[u.u]+wt;
                dist[v]=dist[u.u]+wt;
                pq.push(tmp);
            }
        }

    }
    return -1;
}

int main(){

    int i,k;
    int j;

    scanf("%d %d",&N,&M);
    CLR(occ);
    CLR(conn);

    data2 doge;

    for(i=0;i<M;i++){
        scanf("%d %d",&home[i],&p[i]);
        occ[home[i]]=1;
        doge.pos=i;
        doge.p=p[i];
        doges.pb(doge);
    }

    sort(all(doges));

    data tmp;
    for(k=M-1;k>=0;k--){
        i=doges[k].pos;
        j=1;
        int nxt;


        while(home[i]+j*p[i]<N){
            nxt=home[i]+j*p[i];
            if(occ[nxt] && !conn[home[i]][nxt]){
                tmp.u=nxt;
                tmp.wt=j;
                edges[home[i]].pb(tmp);
                conn[home[i]][nxt]=1;
            }
            j++;
        }


        j=-1;

        while(home[i]+j*p[i]>=0){
            nxt=home[i]+j*p[i];

            if(occ[nxt] && !conn[home[i]][nxt]){
                tmp.u=nxt;
                tmp.wt=-j;
                edges[home[i]].pb(tmp);
                conn[home[i]][nxt]=1;
            }
            j--;
        }
    }

    int ans=dijkstra(home[0],home[1]);

    /*for(i=0;i<N;i++){
        for(j=0;j<edges[i].size();j++) printf("%d ",edges[i][j].u);
        printf("\n");
    }*/

    printf("%d\n",ans);
    return 0;

}
