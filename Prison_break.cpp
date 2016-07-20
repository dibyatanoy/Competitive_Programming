#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXX 104
#define pb push_back
#define INF 1e9

using namespace std;

struct data{
    int u,wt,fuel;
    bool operator <(const data &p)const{
        return wt>p.wt;
    }
};

vector <int > edges[MAXX],cost[MAXX];
long long int dist[MAXX][MAXX];
int n,m;
int f[MAXX];

long long int dijkstra(int src,int ed,int c){
    priority_queue<data>pq;
    int i;
    for(i=0;i<n;i++){
        for(int j=0;j<MAXX;j++) dist[i][j]=INF;
    }

    dist[src][0]=0;
    data temp;
    temp.u=src;temp.wt=0;temp.fuel=0;
    pq.push(temp);

    while(!pq.empty()){
        data u=pq.top();pq.pop();
        data temp2;

        if(u.u==ed){
            int ans=INF;
            for(i=0;i<=c;i++){
                ans=min((long long)ans,dist[u.u][i]);
            }
            return ans;
        }
        int sz=edges[u.u].size();
        for(i=0;i<sz;i++){
            int v=edges[u.u][i];
            if(u.fuel>=cost[u.u][i] && dist[v][u.fuel-cost[u.u][i]]>u.wt){
                temp2.u=v;
                temp2.wt=u.wt;
                temp2.fuel=u.fuel-cost[u.u][i];
                dist[v][temp2.fuel]=temp2.wt;
                pq.push(temp2);
            }
        }
        if(u.fuel<c && dist[u.u][u.fuel+1]>u.wt+f[u.u]){
            temp2.u=u.u;
            temp2.wt=u.wt+f[u.u];
            temp2.fuel=u.fuel+1;
            dist[u.u][u.fuel+1]=temp2.wt;
            pq.push(temp2);
        }
    }
    return INF;
}

int main(){

    int t,st,ed,q,i,j,c;
    scanf("%d",&t);

    for(i=0;i<t;i++){
        scanf("%d%d",&n,&m);
        memset(edges,0,sizeof(edges));
        memset(cost,0,sizeof(cost));
        for(j=0;j<n;j++) scanf("%d",&f[j]);

        for(j=0;j<m;j++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edges[u].push_back(v);cost[u].pb(w);
            edges[v].push_back(u);cost[v].pb(w);
        }
        scanf("%d",&q);
        printf("Case %d:\n",i+1);
        for(j=0;j<q;j++){
            scanf("%d%d%d",&c,&st,&ed);
            long long int ans=dijkstra(st,ed,c);
            if(ans==INF) printf("impossible\n");
            else printf("%lld\n",ans);
        }
    }

    return 0;
}

/** AC!!! **/
