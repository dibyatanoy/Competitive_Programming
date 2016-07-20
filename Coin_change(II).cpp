#include <bits/stdc++.h>
#define MAXX 10005
#define MOD 100000007

using namespace std;

long long int dp[MAXX];
int coins[105];

int main(){

    int kases,i,j,k,n,p;

    scanf("%d",&kases);

    for(i=1;i<=kases;i++){

        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&k);
        for(j=0;j<n;j++) scanf("%d",&coins[j]);
        dp[0]=1LL;

        for(j=0;j<n;j++){
            for(p=coins[j];p<=k;p++) {dp[p]+=dp[p-coins[j]];dp[p]%=100000007;}
        }
        printf("Case %d: %d\n",i,dp[k]);
    }

    return 0;
}

/** AC!!! **/
