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
#define ll long long
#define MAXX 105
#define INF 10000000000000000LL
#define Fr first
#define L 0
#define R 1
#define Sc second

using namespace std;
char adj_matrix[MAXX][MAXX];
int dfs_low[MAXX],dfs_num[MAXX],N,ans,dfsNum;
bool in_stack[MAXX],vis[MAXX];
stack <int> dfs_scc;

void tarjan_scc(int u){
    dfs_low[u]=dfsNum;
    dfs_num[u]=dfsNum++;

    //printf("At %d\n",u);

    vis[u]=1;
    dfs_scc.push(u);
    in_stack[u]=1;

    for(int i=0;i<N;i++){
        if(adj_matrix[u][i]=='Y'){
            if(!vis[i]) tarjan_scc(i);

        if(in_stack[i]){
            dfs_low[u]=min(dfs_low[u],dfs_low[i]);
        }
        }
    }
    //printf("For %d, %d and %d\n",dfs_low[u],dfs_num[u]);
    if(dfs_low[u]==dfs_num[u]){
        //printf("Found %d\n",u);
        while(!dfs_scc.empty() && dfs_scc.top()!=u){
           in_stack[dfs_scc.top()]=0;dfs_scc.pop();
        }
        in_stack[dfs_scc.top()]=0;dfs_scc.pop();
        ans++;
    }
    return;
}

int main(){

    int kases,i,j;

    scanf("%d",&kases);

    while(kases--){
        scanf("%d",&N);

        for(i=0;i<N;i++){
            scanf("%s",adj_matrix[i]);
        }
        CLR(in_stack);
        CLR(vis);

        ans=0;
        dfsNum=1;

        for(i=0;i<N;i++){

            if(!vis[i]) tarjan_scc(i);
        }

        printf("%d\n",ans);
    }

    return 0;
}

/** AC!!! **/
