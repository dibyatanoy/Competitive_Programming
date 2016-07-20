#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MX 60050
#define INF 1e7
 
using namespace std;
 
int wt[MX];
 
typedef struct node{
    int u,w;
    bool operator <(const node&p)const{
        return w>p.w;
    }
};
priority_queue <node> Q;
 
vector <node> edges[MX];
int m,n,short_2=INF,K;
bool taken[MX];
 
int dijkstra(int s,int e){
    wt[s]=0;
    node u,v;
    u.u=s;u.w=0;
    Q.push(u);
    while(!Q.empty()){
        u=Q.top();
        Q.pop();
        for(int i=0;i<edges[u.u].size();i++){
            v.u=edges[u.u][i].u;
            v.w=u.w+edges[u.u][i].w;
            if(wt[v.u]>v.w){
                wt[v.u]=v.w;
                Q.push(v);
                //Q.push(v);
            }

        }
 
    }
    return 0;
}
 
int main(){
 
    int i,j,testcases,s,e;
        scanf("%d %d",&n,&K);
        for(j=0;j<=n;j++) edges[j].clear();
        for(j=0;j<=n;j++) wt[j]=INF;
        for(int k=0;k<n-1;k++){
            int a,b,latency;
            scanf("%d %d %d",&a,&b,&latency);
            node x,y;
            x.u=a;
            x.w=latency;
 
            y.u=b;
            y.w=latency;
 
            edges[x.u].push_back(y);
            edges[y.u].push_back(x);
        }
		memset(taken,0,sizeof(taken));
		int ans=0;
        for(i=1;i<=n;i++){
			for(int j=0;j<=n;j++) wt[j]=INF;
			dijkstra(i,n);
			for(int a=1;a<=n;a++){
				if(!taken[a]&&a!=i&&wt[a]<=K) ans++;
			}
			taken[i]=1;
		}
 
        printf("%d\n",ans);
        //else printf("Case #%d: unreachable\n",i);
 
    
    return 0;
}