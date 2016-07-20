#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#define INF 1000000000
#define eps 1e-9
#define CLR(x) memset(x,0,sizeof(x))
#define pb push_back
#define all(x) x.begin(), x.end()
#define Fr first
#define Sc second
#define MAXX 150000
#define pi 2*acos(0.0)

using namespace std;
vector <int> edges[MAXX],edges_m[MAXX];
int par[MAXX],par_m[MAXX];
bool vis[MAXX],vis2[MAXX];
bool must_vis[MAXX];
int K,N,M,reached;
vector <int> must;
vector <int> ans;

void dfs1(int src, int last){

    int i,j,k;

    vis[src]=1;

    if(must_vis[src]) last=src;

    for(i=0;i<edges[src].size();i++){
        int v=edges[src][i];

        if(must_vis[v] && v!=last){
            edges_m[last].pb(v);
            par_m[v]=last;
        }
        if(!vis[v]){
            par[v]=src;
            dfs1(v,last);
        }
    }

    return;


}

int dfs2(int u, int curr){

    curr++;
    vis2[u]=1;

    ans.pb(u);

    if(curr==K) return 1;

    int i,j;
    bool cnt;


    for(i=0;i<edges_m[u].size();i++){

        int v=edges_m[u][i];

        if(v!=par_m[u] && !vis2[v]){
            cnt=dfs2(v,curr);

            if(cnt) return 1;
        }
    }

    ans.pop_back();
    vis2[u]=0;

    return 0;
}

int main(){

    int i,j,k,kases;
    int tmp;

    scanf("%d",&kases);

    while(kases--){
        scanf("%d %d %d",&N,&M,&K);

        for(i=0;i<MAXX;i++){
            edges[i].clear();edges_m[i].clear();
            ans.clear();
        }

        must.clear();
        CLR(vis);CLR(vis2);CLR(must_vis);



        for(i=0;i<K;i++){
            scanf("%d",&tmp);
            must.pb(tmp);
            must_vis[tmp]=1;
        }

        sort(all(must));

        for(i=0;i<M;i++){
            int u,v;

            scanf("%d %d",&u,&v);

            edges[u].pb(v);
        }

        CLR(par);CLR(par_m);


        for(i=0;i<K;i++){

            if(!vis[must[i]]) {

                par[must[i]]=0;par_m[must[i]]=-1;
                dfs1(must[i],0);

            }
        }

        bool done=0;
        reached=0;
        CLR(vis2);

        for(i=0;i<K;i++){
            sort(all(edges_m[must[i]]));
        }

        for(i=0;i<K;i++){
            printf("%d: ",must[i]);
            for(j=0;j<edges_m[must[i]].size();j++) printf(" %d",edges_m[must[i]][j]);

            printf("\n");
        }




        for(i=0;i<K;i++){
            if(par_m[must[i]]==-1){
                dfs2(must[i],0);
                done=1;
            }
        }
        if(!done) dfs2(must[0],0);

        //printf("! %d",ans.size());

        if(ans.size()<K) printf("-1\n");
        else{
            printf("%d",ans[0]);

            for(i=1;i<K;i++) printf(" %d",ans[i]);
            printf("\n");
        }
    }

    return 0;
}

/*
5
6 7 3
3 6 5
1 2
2 3
3 1
2 5
5 6
6 1
4 3
*/
