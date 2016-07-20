#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define MAXX 45000

using namespace std;

long long int dp[MAXX+2];
int wt[102];
int n,k,sum;

int main(){

    int kases,i,j;
    long long bt;
    bool st=0;

    scanf("%d",&kases);

    while(kases--){
        scanf("%d",&n);
        sum=0;
        memset(dp,0,sizeof(dp));

        for(i=0;i<n;i++){
            scanf("%d",&wt[i]);
            sum+=wt[i];
        }
        dp[0]=1LL<<0;

        for(i=0;i<n;i++){
            for(j=sum;j>=0;j--){
                if(dp[j]) dp[j+wt[i]]|=(dp[j]<<1);
            }
        }
        bt=1LL<<(n/2);
        int half=sum/2;
        int ans;

        for(i=half,j=half;i>=0,j<=sum;i--,j++){
            if(dp[i] & bt){
                ans=i;
                break;
            }
            if(dp[j] & bt){
                ans=j;
                break;
            }
        }

        if(st==0) printf("%d %d\n",min(ans,sum-ans),max(ans,sum-ans));
        else printf("\n%d %d\n",min(ans,sum-ans),max(ans,sum-ans));
        st=1;

    }

    return 0;
}
