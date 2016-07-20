#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;


int max(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){
	int rect[102][102],sum[102][102],dp[102],N,ans=-127010;
	int i,j,row1,row2;
	scanf("%d",&N);

	for(i=0;i<N;i++){
		for(j=0;j<N;j++) scanf("%d",&rect[i][j]);
	}

	for(i=0;i<N;i++) sum[0][i]=0;

	for(i=0;i<=N;i++){
		for(j=1;j<=N;j++){
			sum[j][i]=sum[j-1][i]+rect[j-1][i];
		}
	}

	for(row1=1;row1<=N;row1++){
		for(row2=row1;row2<=N;row2++){
			dp[0]=sum[row2][0]-sum[row1-1][0];
			ans=max(ans,dp[0]);
			for(j=1;j<N;j++){
				dp[j]=max(dp[j-1]+sum[row2][j]-sum[row1-1][j],sum[row2][j]-sum[row1-1][j]);
				if(dp[j]>ans) ans=dp[j];
			}
		}
	}

	printf("%d\n",ans);


	return 0;
}

/** AC!!! **/