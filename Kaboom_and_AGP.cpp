#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#define INF 1e8
#define MAXX 100004
#define pb push_back
#define MP make_pair
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a));
#define PII pair<int,int >

using namespace std;
struct data{
    int v,e_no;
};

vector <data> edges[MAXX];
int e_cnt=0;

int dist[MAXX];
bool vis[MAXX];
int N,E,ans=0;
bool taken[2*MAXX];

void dfs(int v,int p,int d){

    vis[v]=1;
    int i,j;
    dist[v]=d+1;

    for(i=0;i<edges[v].size();i++){
        int u=edges[v][i].v;


        if(u!=p && taken[edges[v][i].e_no]==0){
            taken[edges[v][i].e_no]=1;
            if(vis[u] && dist[v]-dist[u]==2) ans++;
            //printf("Calling %d %d %d\n",u,v,dist[v]+1);
            dfs(u,v,dist[v]);
            //dist[v]=min(dist[v],dist[u]+1);
        }/*else if(u!=p && !taken[edges[v][i].e_no]){
            taken[edges[v][i].e_no]=1;
            //if(v==3 && u==1) printf("! %d %d\n",dist[v],dist[u]);
            if(dist[v]-dist[u]<=2) {ans++;printf("%d %d\n",v,u);}
            dist[v]=min(dist[v],dist[u]+1);
        }*/
    }
    return;
}

int main(){


    int i,j;

    scanf("%d%d",&N,&E);

    for(i=0;i<E;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        data temp;

        temp.v=y;
        temp.e_no=e_cnt++;

        edges[x].pb(temp);
        temp.v=x;

        edges[y].pb(temp);

    }



    memset(dist,0,sizeof(dist));


    dfs(1,-1,-1);

    cout<<ans<<endl;

    return 0;
}
