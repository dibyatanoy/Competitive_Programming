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
#include <utility>
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))
#define all(v) v.begin(),v.end()
#define INF 1e8
#define MAXX 1005

using namespace std;
int N,K;
long long int dp[20][20];
bool vis[20][20];
long long int fact[20];

long long int call(int pos, int rt){
    if(pos==K+1) return (rt<=0)? 1:fact[rt];
    if(vis[pos][rt]) return dp[pos][rt];

    long long int ret=0;

    if(rt){

        if(pos+2<=K+1) ret=rt*call(pos+1,rt)+(long long)(K-pos)*call(pos+2,rt);
        else ret=rt*call(pos+1,rt);
    }else{
        if(pos+2<=K+1) ret=(K-pos)*call(pos+2,rt);
        else ret=0LL;
    }
    vis[pos][rt]=1;
    return dp[pos][rt]=ret;
}

long long int call(int pos, int hand){
    if(pos==N){
        if(hand) return 0;
        else return 1;
    }

    long long int ret=0;

    if(pos<=K){
        ret=call()
    }
}

int main(){

    int i,j,k,p;

    scanf("%d",&p);

    fact[0]=1;
    for(i=1;i<20;i++) fact[i]=fact[i-1]*i;

    while(p--){
        CLR(vis);
        scanf("%d %d %d",&k,&N,&K);

        printf("%d %lld\n",k,call(1,N-K));
    }

    return 0;
}
