#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define MAXX 120000
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))

using namespace std;

vector <int> edges[MAXX];
bool vis[MAXX];
int N;

void dfs(int src){

    vis[src]=1;
    int i,j;

    for(i=0;i<edges[src].size();i++){
        if(!vis[edges[src][i]]){
            dfs(edges[src][i]);
        }
    }

    return;
}

int main(){

    int i,j,k,kases,cmp;

    scanf("%d",&kases);

    while(kases--){

        for(i=0;i<MAXX;i++) edges[i].clear();
        cmp=0;

        scanf("%d",&N);

        for(i=1;i<=N;i++){
            int tmp;
            scanf("%d",&tmp);

            edges[i].pb(tmp);
        }
        CLR(vis);

        for(i=1;i<=N;i++){
            if(!vis[i]){
                cmp++;
                dfs(i);
            }
        }
        printf("%d\n",cmp-1);

    }


    return 0;
}


/** AC!!! **/
