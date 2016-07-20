#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define pb push_back
#define MP make_pair
#define PIL pair<int,long long int >
#define Fr first
#define Sc second
#define MAXX 12000
#define ll long long int
#define INF 1000000000000000

using namespace std;

struct data{
    int u,v;
    ll cost;

    bool operator <(const data&p)const{
        return cost>p.cost;
    }
};
vector <PIL> edges[2][MAXX];
vector <data> edge_list(5*MAXX);
ll dist[2][MAXX];
int N,M,s,t;
ll p;

void dijkstra(bool t,int src){
    priority_queue <data> pq;
    int i,j;

    for(i=0;i<MAXX;i++) dist[t][i]=INF;
    dist[t][src]=0;
    data tmp;
    tmp.u=src;tmp.cost=0;
    pq.push(tmp);

    while(!pq.empty()){
        data u=pq.top();pq.pop();

        for(i=0;i<edges[t][u.u].size();i++){
            PIL v=edges[t][u.u][i];

            if(dist[t][v.Fr]>dist[t][u.u]+v.Sc){
                dist[t][v.Fr]=dist[t][u.u]+v.Sc;
                tmp.u=v.Fr;tmp.cost=dist[t][v.Fr];
                pq.push(tmp);
            }
        }
    }
    return;
}

int main(){

    int i,j,k;
    int tc,kases;

    scanf("%d",&tc);

    for(kases=1;kases<=tc;kases++){

        scanf("%d %d %d %d %lld",&N,&M,&s,&t,&p);

        for(i=0;i<2;i++){for(j=0;j<MAXX;j++) edges[i][j].clear();}
        edge_list.clear();

        for(i=0;i<M;i++){
            scanf("%d %d %lld",&edge_list[i].u,&edge_list[i].v,&edge_list[i].cost);

            //printf("!\n");
            edges[0][edge_list[i].u].pb(MP(edge_list[i].v,edge_list[i].cost));

            edges[1][edge_list[i].v].pb(MP(edge_list[i].u,edge_list[i].cost));
        }

        dijkstra(0,s);
        dijkstra(1,t);

        ll mx=-1;

        for(i=0;i<M;i++){
            if(dist[0][edge_list[i].u]+dist[1][edge_list[i].v]+edge_list[i].cost<=p){
                mx=max(mx,edge_list[i].cost);
            }
        }

        printf("Case %d: %lld\n",kases,mx);

    }

    return 0;
}
