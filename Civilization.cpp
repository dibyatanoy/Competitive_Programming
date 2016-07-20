#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#define pb push_back
#define MP make_pair
#define CLR(x) memset(x,0,sizeof(x));
#define all(v) v.begin(),v.end()
#define PII pair <int,int >
#define ll long long
#define MAXX 320000
#define INF 100000000
#define Fr first
#define Sc second

using namespace std;
int N,M,Q;
int par[MAXX];
int dia[MAXX],centre[MAXX];
bool vis[MAXX],vis2[MAXX];
int dist[MAXX],p[MAXX];
vector <int> edges[MAXX];

int get(int u){
    return (par[u]==u)? u:par[u]=get(par[u]);
}

int dfs(int u,int abs_p){

    vis[u]=1;
    dist[u]=u;
    par[u]=abs_p;
    int mx=0;
    int i,j;

    for(i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(!vis[v]){

            int tmp=dfs(v,abs_p);
            if(tmp+1>mx){
                mx=tmp+1;
                dist[u]=v;
            }
        }
    }
    return mx;
}

int dfs2(int u){

    vis2[u]=1;
    dist[u]=u;
    int mx=0;
    int i,j;

    for(i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(!vis2[v]){

            int tmp=dfs2(v);
            if(tmp+1>mx){
                mx=tmp+1;
                dist[u]=v;
            }
        }
    }
    return mx;
}

int main(){

    int i,j,k;

    scanf("%d %d %d",&N,&M,&Q);

    for(i=0;i<M;i++){
        int x,y;
        scanf("%d %d",&x,&y);

        edges[x].pb(y);
        edges[y].pb(x);
    }

    CLR(vis);CLR(vis2);
    for(i=0;i<MAXX;i++) par[i]=i;

    for(i=1;i<=N;i++){
        if(!vis[i]){
            dfs(i,i);
            int c=dist[i];
            dia[i]=dfs2(dist[i]);

            int rad=dia[i]/2;
            while(rad--){
                c=dist[c];
            }
            centre[i]=c;
        }
    }

    /*for(i=1;i<=N;i++){
        printf("%d %d %d\n",par[i],dia[i],centre[i]);
    }*/

    //printf("Here!!  ");
    for(i=1;i<=Q;i++){
        int type,u,v;

        scanf("%d",&type);

        if(type==1){
            scanf("%d",&u);
            //printf("%d\n",get(u));

            printf("%d\n",dia[get(u)]);
        }else{
            scanf("%d%d",&u,&v);
            int p1=get(u);int p2=get(v);
            if(p1!=p2){
                int d1=dia[p1];
                int d2=dia[p2];
                int r1=d1/2;int r2=d2/2;

                if(d1-r1==d2-r2){
                    dia[p1]=max(d1,max(d2,d1-r1+d2-r2+1));
                    par[p2]=p1;

                }else{
                    if(d1>d2){
                        dia[p1]=max(d1,max(d2,d1-r1+d2-r2+1));
                        par[p2]=p1;
                    }else{
                        dia[p2]=max(d1,max(d2,d1-r1+d2-r2+1));
                        par[p1]=p2;
                    }
                }
            }
        }
    }

    return 0;
}
