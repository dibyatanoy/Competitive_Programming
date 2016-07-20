#include <stdio.h>

int dp[21][4],prices[21][4];
int i,j,n;

int min(int a,int b){
	if(a<b) return a;
	else return b;
}

int min_dp(){
	int min;
	if(dp[n-1][0]<dp[n-1][1]) min=dp[n-1][0];
	else min=dp[n-1][1];

	if(min>dp[n-1][2]) min=dp[n-1][2];
	

	return min;

}

void run_dp(){
	
	for(i=0;i<3;i++)
		dp[0][i]=prices[0][i];

	for(i=1;i<n;i++){
		for(j=0;j<3;j++){
			if(j==0)
				dp[i][j]=prices[i][j]+min(dp[i-1][1],dp[i-1][2]);
			else if(j==1)
				dp[i][j]=prices[i][j]+min(dp[i-1][0],dp[i-1][2]);
			else
				dp[i][j]=prices[i][j]+min(dp[i-1][0],dp[i-1][1]);
		}
	}

}

int main(){

	int testcase,kase,count1,count2,ans;

	scanf("%d",&testcase);

	for(kase=1;kase<=testcase;kase++){
		scanf("%d",&n);

		for(count1=0;count1<n;count1++){
			for(count2=0;count2<3;count2++)
				scanf("%d",&prices[count1][count2]);


		}

		run_dp();
		ans=min_dp();

		printf("Case %d: %d\n",kase,ans);
	}

	return 0;
}

//** AC!!! Another DP! **//