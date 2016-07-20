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
#define MAXX 130000
#define ll long long
#define pi 2*acos(0.0)

using namespace std;

vector <int> edges[MAXX];
vector <int> wt[MAXX];
int L[MAXX],P[MAXX],A[MAXX][18];
map < pair <int, int> , ll int> prev_dist;
int dist[MAXX];
int N,T,K;
bool vis[MAXX];
int query[MAXX*2];

void dfs(int u){

    int i,j;
    vis[u]=1;

    for(i=0;i<edges[u].size();i++){

        int v=edges[u][i];
        int c=wt[u][i];

        if(!vis[v]){
            dist[v]=dist[u]+c;
            P[v]=u;
            L[v]=L[u]+1;
            A[v][0]=u;
            dfs(v);
        }
    }

    return;
}

int lca(int p, int q)
{
    // ensure node p is at least as deep as node q
    if(L[p] < L[q])
	swap(p, q);

    // "binary search" for the ancestor of node p situated on the same level as q
    for(int i = 18; i >= 0; i--){
        if(L[p] - (1<<i) >= L[q])
            p = A[p][i];
    }

    if(p == q)
	return p;

    // "binary search" for the LCA
    for(int i = 18; i >= 0; i--){
        if(A[p][i] != -1 && A[p][i] != A[q][i])
        {
            p = A[p][i];
            q = A[q][i];
        }
    }
    return A[p][0];
}

int main(){

    int i,j,k;

    scanf("%d %d",&N,&T);

    for(i=0;i<N-1;i++){
        int u,v,c;
        scanf("%d %d %d",&u,&v,&c);

        edges[u].pb(v);wt[u].pb(c);
        edges[v].pb(u);wt[v].pb(c);
    }

    dist[0]=0;
    P[1]=-1;
    L[1]=1;
    dist[1]=0;
    A[1][0]=-1;
    CLR(vis);
    dfs(1);


    for(j = 1; j <= 18; j++){
        for(i = 1; i <=N; i++){
            if(A[i][j-1] != -1)
            A[i][j] = A[A[i][j-1]][j-1];
            else
            A[i][j] = -1;
        }
    }

    while(T--){

        scanf("%d",&k);
        ll int ans=0;


        for(j=0;j<k;j++){
            scanf("%d",&query[j]);
        }

        for(i=0;i<k;i++){
            for(j=i+1;j<k;j++){

                pair <int, int > curr_pair=make_pair(query[i],query[j]);
                pair <int, int> rev_pair=make_pair(query[j],query[i]);

                if(prev_dist.find(curr_pair)==prev_dist.end() && prev_dist.find(rev_pair)==prev_dist.end()){

                    ll int tmp=(ll)(dist[query[i]]+dist[query[j]]-2*dist[lca(query[i],query[j])]);
                    ans+=tmp;

                    //printf("Found d from %d to %d: %lld\n",query[i],query[j],tmp);
                    prev_dist[curr_pair]=tmp;
                }else{

                    if(prev_dist.find(curr_pair)!=prev_dist.end()) ans+=prev_dist[curr_pair];
                    else ans+=prev_dist[rev_pair];
                }
            }
        }

        printf("%lld\n",ans);


    }


    return 0;
}
