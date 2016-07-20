#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define CLR(x) memset((x),0,sizeof(x))
#define ll long long int
#define MAXX 10500

using namespace std;
vector <int > edges[MAXX];
int N,M;
bool vis[MAXX],in_stack[MAXX];
int dfs_num[MAXX],dfs_low[MAXX],cnt,sccCnt;
stack <int> st;

void SCC(int u){

    int i,j;

    dfs_low[u]=dfs_num[u]=cnt++;
    in_stack[u]=1;vis[u]=1;
    st.push(u);

    for(i=0;i<edges[u].size();i++){
        int v=edges[u][i];

        if(!vis[v]){
            SCC(v);
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
        }else if(in_stack[v]) dfs_low[u]=min(dfs_low[u],dfs_low[v]);

    }

    if(dfs_low[u]==dfs_num[u]){
        int w;
        while(st.top()!=u){
            w=st.top();
            st.pop();
            in_stack[w]=0;
        }
        w=st.top();
        st.pop();
        in_stack[w]=0;
        sccCnt++;
    }

    return;
}

int main(){

    int i,j,k;
    int kases,t;

    scanf("%d",&kases);

    for(t=1;t<=kases;t++){

        scanf("%d %d\n",&N,&M);
        for(i=0;i<MAXX;i++) edges[i].clear();

        for(i=0;i<M;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            edges[a].pb(b);
        }
        CLR(vis);CLR(in_stack);
        CLR(dfs_low);CLR(dfs_num);
        cnt=0;sccCnt=0;

        for(i=1;i<=N;i++){
            if(!vis[i]) SCC(i);
        }

        printf("Case %d: %d\n",t,sccCnt);
    }

    return 0;
}
