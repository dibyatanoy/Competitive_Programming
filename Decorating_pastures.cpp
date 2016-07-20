#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXX 50004

using namespace std;
int col[MAXX],par[MAXX],N,M;
bool vis[MAXX];
vector <int>edges[MAXX];

int bfs(int src){
    int cnt[2];
    cnt[1]=0;
    queue<int>Q;
    col[src]=0;cnt[0]=1;
    vis[src]=1;
    Q.push(src);

    while(!Q.empty()){

        int u=Q.front();Q.pop();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(!vis[v]){
                par[v]=u;
                col[v]=1-col[u];
                cnt[col[v]]++;
                vis[v]=1;
                Q.push(v);
            }else if(col[u]==col[v]) return -1;
        }
    }
    return max(cnt[0],cnt[1]);
}

int main(){

    int i,j,k;

    freopen("decorate.in","r",stdin);
    freopen("decorate.out","w",stdout);
    cin>>N>>M;
    for(i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    memset(par,-1,sizeof(par));
    memset(vis,0,sizeof(vis));

    int ans=0,curr;
    bool val=true;
    for(i=1;i<=N;i++){

        if(!vis[i]){
            curr=bfs(i);
            if(curr==-1){ans=-1;break;}
            else ans+=curr;
        }
    }
    cout<<ans<<endl;

    return 0;
}
