#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXX 1002
#define pb push_back

using namespace std;

struct data{
    int edge_no,to;
};
struct data2{
    int i,j;
};

int n,m,dfs_num[MAXX],dfs_low[MAXX],dfs_cnt,par[MAXX];
bool bridge[1000002],vis[MAXX];
bool vis_edge[1000002];
vector<data2>bridge_vt;
vector <data> edges[MAXX];

void dfs(int u){
    dfs_num[u]=dfs_low[u]=dfs_cnt++;

    int i;
    for(i=0;i<edges[u].size();i++){
        int v=edges[u][i].to;
        if(!vis[v]){
            vis[v]=1;
            par[v]=u;
            dfs(v);
            if(dfs_low[v]>dfs_num[u]) {
                    //cout << "Here" << u << " " << v << endl;
                    bridge[edges[u][i].edge_no]=1;
                    data2 temp;temp.i=u;temp.j=v;
                    bridge_vt.pb(temp);
            }
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
        }else if(v!=par[u]) dfs_low[u]=min(dfs_num[v],dfs_low[u]);
    }
}

void dfs2(int u,int p){
    vis[u]=1;

    int i;
    for(i=0;i<edges[u].size();i++){
        int v=edges[u][i].to;
        if(!vis[v] && !bridge[edges[u][i].edge_no]){
            printf("%d %d\n",u,v);
            vis_edge[edges[u][i].edge_no]=1;
            dfs2(v,u);
        }else if(!vis_edge[edges[u][i].edge_no] && !bridge[edges[u][i].edge_no]) {printf("%d %d\n",u,v);vis_edge[edges[u][i].edge_no]=1;}
    }
}

int main(){

    int i,j,k,kase_no=1;
    //freopen("out.txt","w",stdout);

    while(scanf("%d %d",&n,&m)==2 && n!=0){
        int edge_cnt=0;
        for(i=0;i<=n;i++) edges[i].clear();
        for(i=0;i<m;i++){
            data temp;
            int x,y;
            cin >> x >> y;
            temp.edge_no=edge_cnt++;
            temp.to=y;edges[x].pb(temp);
            temp.to=x;edges[y].pb(temp);
        }
        memset(bridge,0,sizeof(bridge));
        memset(par,-1,sizeof(par));
        memset(vis,0,sizeof(vis));
        bridge_vt.clear();
        dfs_cnt=1;
        for(i=1;i<=n;i++){
            if(!vis[i]) dfs(i);
        }
        memset(vis,0,sizeof(vis));
        memset(vis_edge,0,sizeof(vis_edge));

        printf("%d\n",kase_no++);
        cout << endl;

        for(i=1;i<=n;i++){
            if(!vis[i]) dfs2(i,-1);
        }
        //for(i=0;i<m;i++) printf("%d ",bridge[i]);
        for(i=0;i<bridge_vt.size();i++){
            printf("%d %d\n",bridge_vt[i].i,bridge_vt[i].j);
            printf("%d %d\n",bridge_vt[i].j,bridge_vt[i].i);
        }

        cout << "#" << endl;

    }

}

/** AC!!! **/
