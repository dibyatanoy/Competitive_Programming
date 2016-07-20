#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define MAXX 102
#define INF 1e8
#define CLEAR(x) memset((x),0,sizeof((x))
#define pb push_back
#define ll long long int
#define ALL(v) v.begin(),v.end()

using namespace std;

long long int dp[MAXX][2];
bool vis[MAXX][2];
int N,K,d;

long long int call(int sum,int taken){
    if(sum>N) return 0;
    if(sum==N && taken) return 1;
    if(sum==N && !taken) return 0;
    if(vis[sum][taken]) return dp[sum][taken];

    long long int ret=0;
    int i;

    for(i=1;i<d;i++) ret=(ret+call(sum+i,taken))%1000000007;
    for(i=d;i<=K;i++) ret=(ret+call(sum+i,1))%1000000007;

    vis[sum][taken]=1;
    return dp[sum][taken]=ret;
}

int main(){

    int i,j;

    cin>>N>>K>>d;

    memset(vis,0,sizeof(vis));

    cout<<call(0,0)<<endl;

    return 0;
}
