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
#define MAXX 100005
#define INF 10000000000000000LL
#define Fr first
#define Sc second

using namespace std;
int N;
ll s[MAXX],v[MAXX],dist[MAXX];
bool vis[MAXX];
vector <int> edges[MAXX];           //dp[i]=min_over_all_j(dp[j]-dist[j]*v[i]+dist[i]*v[i]+s[i])
vector <ll> cost[MAXX];             // gradient: -dist[j]; y-intercept: dp[j]; x-query: v[i]

ll b[MAXX]; //a: x-query value, b:gradient
ll dp[MAXX];        //dp: y-intercept
vector < pair<int,ll> >dq;

ll finds(int x){
    int lo=0, hi=dq.size()-1;

    while(lo<=hi){
        if(lo==hi) return dq[lo].Fr;
        else if(hi==lo+1){
            if(dq[hi].Sc>x) return dq[lo].Fr;
            else return dq[hi].Fr;
        }

        int mid=(lo+hi)/2;

        if(dq[mid].Sc>x){
            hi=mid;
        }else lo=mid;
    }
}

void dfs(int u){

    int i,j;
    vis[u]=1;
    stack< pair<int,ll> >removed;

    int pos=finds(v[u]);
    //cout<<u<<" pos is "<<pos<<endl;
    dp[u]=dp[pos]+b[pos]*v[u]+dist[u]*v[u]+s[u];
    b[u]=-dist[u];

    int s1,s2;
    int idx=u;

    while((int)dq.size()>=2){
        s2=dq[dq.size()-1].Fr;
        s1=dq[dq.size()-2].Fr;

        double x1= (double)(dp[idx]-dp[s1])/(double)(b[s1]-b[idx]);
        double x2= (double)(dp[s2]-dp[s1])/(double)(b[s1]-b[s2]);

        if(x1>x2) break;
        else {
            removed.push(dq[dq.size()-1]);
            dq.erase(dq.end()-1);
        }
    }

    s2=dq[dq.size()-1].Fr;
    ll x2=(ll)ceil((double)(dp[idx]-dp[s2])/(double)(b[s2]-b[idx]));

    dq.pb(MP(idx,x2));

    int sz=edges[u].size();
    for(i=0;i<sz;i++){
        int now=edges[u][i];
        if(!vis[now]){
            dist[now]=dist[u]+cost[u][i];
            dfs(now);
        }
    }

    dq.erase(dq.end()-1);
    while(!removed.empty()){
        dq.pb(removed.top());
        removed.pop();
    }

    return;
}

int main(){

    int i,j,k;

    scanf("%d",&N);

    for(i=0;i<N-1;i++){
        int u,v;
        ll c;
        scanf("%d %d %lld",&u,&v,&c);
        edges[u].pb(v);cost[u].pb(c);
        edges[v].pb(u);cost[v].pb(c);
    }

    for(i=2;i<=N;i++) scanf("%lld %lld",&s[i],&v[i]);

    dq.pb(MP(1,-INF));
    dp[1]=0;
    dist[1]=0;
    b[1]=0;
    vis[1]=1;

    int sz=edges[1].size();
    for(i=0;i<sz;i++){
        int now=edges[1][i];
        if(!vis[now]){
            dist[now]=dist[1]+cost[1][i];
            dfs(now);
        }
    }

    printf("%lld",dp[2]);
    for(i=3;i<=N;i++) printf(" %lld",dp[i]);
    printf("\n");

    return 0;
}
