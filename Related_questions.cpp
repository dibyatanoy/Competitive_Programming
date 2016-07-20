#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#define pb push_back
#define all(v) v.begin(),v.end()
#define CLR(x) memset(x,0,sizeof(x))
#define MAXX 110000
#define ll long long

using namespace std;

int N;
vector <int> edges[MAXX];
int tm[MAXX];
bool vis[MAXX];
int par[MAXX];
double e_down[MAXX],s_down[MAXX],e_tot[MAXX];

void bfs(int src){

    queue<int>Q;
    int i;
    CLR(vis);
    e_tot[src]=e_down[src]+(double)tm[src];
    Q.push(src); vis[src]=1;

    while(!Q.empty()){

        int v=Q.front();Q.pop();

        for(i=0;i<edges[v].size();i++){
            int u=edges[v][i];

            if(!vis[u]){

                double tmp1=((e_tot[par[u]]-(double)tm[par[u]])*(double)(edges[par[u]].size())-e_down[u]-(double)tm[u])/((edges[par[u]].size()-1)? (double)(edges[par[u]].size()-1):1.0)+(double)tm[par[u]];
                double tmp2=s_down[u];

                e_tot[u]=(tmp1+tmp2)/(double)edges[u].size()+(double)tm[u];

                vis[u]=1;

                Q.push(u);
            }
        }
    }

    return;


}

double dfs_down(int src){

    vis[src]=1;
    s_down[src]=0.0;

    int i,j;

    for(i=0;i<edges[src].size();i++){

        int v=edges[src][i];

        if(!vis[v]){
            par[v]=src;

            s_down[src]+=dfs_down(v);
        }
    }

    if(src==1) e_down[src]=s_down[src]/((double)edges[src].size());

    else e_down[src]=s_down[src]/((edges[src].size()-1)? (double)(edges[src].size()-1) : 1.0);

    return e_down[src]+(double)tm[src];
}

int main(){

    int i,j,k;

    scanf("%d",&N);

    for(i=1;i<=N;i++) scanf("%d",&tm[i]);

    for(i=0;i<N-1;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        edges[x].pb(y);edges[y].pb(x);
    }


    CLR(vis);
    memset(par,-1,sizeof(par));

    dfs_down(1);
    bfs(1);

    double mn=100000000.00;
    int idx=-1;

    for(i=1;i<=N;i++){
        if(mn>e_tot[i]){
            mn=e_tot[i];
            idx=i;
        }
    }

    /*for(i=1;i<=N;i++){
        printf("%lf %lf %lf\n",s_down[i],e_down[i],e_tot[i]);
    }*/

    printf("%d\n",idx);


    return 0;
}

/**AC!!! **/
