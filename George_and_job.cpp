#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#define CLR(x) memset((x),0,sizeof((x)))
#define all(v) v.begin(),v.end()
#define pb push_back
#define MP make_pair
#define PII pair <int,int >
#define MAXX 5005
#define INF 1e16
#define ll long long
#define MOD 1000000007
#define Fr first
#define Sc second

using namespace std;

int N,K,M;
long long int p[MAXX];
long long int dp[MAXX][MAXX],sum[MAXX];
bool vis[MAXX][MAXX];

int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}

long long int call(int pos,int left){
    if(left==0) return 0;
    if(pos>=N) return -INF;

    if(vis[pos][left]) return dp[pos][left];

    long long int ret;

    ret=max(call(pos+1,left),call(pos+M,left-1)+sum[pos+M-1]- ((pos==0)? 0:sum[pos-1]));

    vis[pos][left]=1;
    return dp[pos][left]=ret;
}

int main(){

    int i,j,k;

    scanf("%d %d %d",&N,&M,&K);

    for(i=0;i<N;i++){
        scanf("%I64d",&p[i]);
    }

    sum[0]=p[0];
    for(i=1;i<N;i++) sum[i]=sum[i-1]+(ll)p[i];

    CLR(vis);

    printf("%I64d\n",call(0,K));

    return 0;
}

/** AC!!! **/
