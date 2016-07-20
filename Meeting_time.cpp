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
#define MAXX 110
#define INF 10000000
#define off 100

using namespace std;

struct data{
    int a,b,diff,dist;

    bool operator <(const data &p)const{
        return dist>p.dist;
    }
};

int dist[MAXX][MAXX][2*MAXX];
int N,M;
vector <int> edges[MAXX],C[MAXX],D[MAXX];

int dijkstra(int src){
    priority_queue <data> pq;
    int i,j,k;
    data tmp;
    tmp.a=src;tmp.b=src;tmp.diff=100;tmp.dist=0;
    dist[src][src][tmp.diff]=0;
    pq.push(tmp);

    while(!pq.empty()){

        data v=pq.top();pq.pop();

        if(v.a==N && v.b==N && v.diff==100) return dist[N][N][100]/2;
        int nxt;

        for(i=0;i<edges[v.a].size();i++){
            nxt=edges[v.a][i];
            //printf("Here\n");
            if(v.diff+C[v.a][i]<=(100+off) && dist[nxt][v.b][v.diff+C[v.a][i]]>v.dist+C[v.a][i]){

                //printf("! %d %d %d\n",v.a,v.b,nxt);
                dist[nxt][v.b][v.diff+C[v.a][i]]=v.dist+C[v.a][i];

                tmp.a=nxt;
                tmp.b=v.b;
                tmp.dist=dist[nxt][v.b][v.diff+C[v.a][i]];
                tmp.diff=v.diff+C[v.a][i];

                pq.push(tmp);
            }

        }

        for(i=0;i<edges[v.b].size();i++){
            nxt=edges[v.b][i];

            if(v.diff-D[v.b][i]>=0 && dist[v.a][nxt][v.diff-D[v.b][i]]>v.dist+D[v.b][i]){

                //printf("* %d %d %d\n",v.a,v.b,nxt);

                dist[v.a][nxt][v.diff-D[v.b][i]]=v.dist+D[v.b][i];

                tmp.a=v.a;
                tmp.b=nxt;
                tmp.dist=dist[v.a][nxt][v.diff-D[v.b][i]];
                tmp.diff=v.diff-D[v.b][i];

                pq.push(tmp);
            }

        }
    }

    return -1;
}

int main(){

    int i,j,k;

    freopen("meeting.in","r",stdin);
    freopen("meeting.out","w",stdout);

    scanf("%d %d",&N,&M);

    for(i=0;i<M;i++){
        int x,y,c,d;
        scanf("%d %d %d %d",&x,&y,&c,&d);

        edges[x].pb(y);C[x].pb(c);D[x].pb(d);
    }

    for(i=0;i<MAXX;i++){
        for(j=0;j<MAXX;j++){
            for(k=0;k<2*MAXX;k++) dist[i][j][k]=INF;
        }
    }

    int ans=dijkstra(1);
    if(ans>=0) printf("%d\n",ans);
    else printf("Impossible\n");

    return 0;
}
