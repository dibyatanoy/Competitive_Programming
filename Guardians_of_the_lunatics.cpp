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
long long int dp[8020][820],csum[8020],C[8020];
int L,G;

int calc(int g,int pos,int srchL,int srchR){

    dp[pos][g]=INF;
    int ret=srchL;
    for(int i=srchL;i<=srchR;i++){
        long long int t=dp[i][g-1]+(csum[pos]-csum[i])*(ll)(pos-i);
        if(t<dp[pos][g]){
            dp[pos][g]=t;
            ret=i;
        }
    }
    return ret;
}

void solve(int g,int L,int R,int srchL,int srchR){
    if(L>R) return;

    if(L==R){
        calc(g,L,srchL,srchR);
        return;
    }

    srchR=min(srchR,R-1);
    if(srchL==srchR){
        for(int i=L;i<=R;i++) calc(g,i,srchL,srchR);

        return;
    }
    int M=(L+R)/2;
    int optM=calc(g,M,srchL,srchR);
    solve(g,L,M-1,srchL,optM);
    solve(g,M+1,R,optM,srchR);

    return;

}

int main(){

    int i,j,k;

    scanf("%d %d",&L,&G);
    csum[0]=0;

    for(i=1;i<=L;i++) {scanf("%lld",&C[i]);csum[i]=csum[i-1]+C[i];}
    if(G>=L){
        printf("%lld\n",csum[L]);
        return 0;
    }

    for(i=1;i<=L;i++){
        dp[i][1]=(csum[i]-csum[0])*(ll)(i);
    }
    for(i=2;i<=G;i++){
        solve(i,1,L,i-1,L);
    }

    printf("%lld\n",dp[L][G]);

    return 0;
}

/** AC!!! **/
/** My first D&Q optimization problem **/
