#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define MAXX 55
#define mod 1000000

using namespace std;
int dp[MAXX][MAXX][MAXX];
bool vis[MAXX][MAXX][MAXX];
int n,k;

int call(int pos,int l,int out){
    if(pos==N+1) return 1;
    if(vis[pos][l][out]) return dp[pos][l][out];

    int ways=0,places;

    if(l<k){
        ways+=call(pos+1,l+1,out)+()call(pos+1,l,out+1);
    }
}

int main(){

    int kases,i,j,p,q;
    int k1,k2;
    scanf("%d",&kases);

    for(i=1;i<=kases;i++){
        scanf("%d %d",&n,&k);
        k1=0;k2=0;
        memset(dp,0,sizeof(dp));

        for(j=1;j<=n;j++){
            dp[j][1]=1;
            for(p=1;p<j;p++){
                for(q=1;q<n;q++){
                    dp[j][q+1]+=dp[p][q];
                    dp[j][q+1]%=mod;

                }
            }
            k1=(k1+dp[j][k])%mod;
            k2=(k2+dp[j][k+1])%mod;
        }

        printf("Case %d: %d\n",i,k1-k2);
    }

    return 0;
}
