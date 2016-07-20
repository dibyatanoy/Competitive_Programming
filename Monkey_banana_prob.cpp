#include <stdio.h>

int find_max(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){

	int testcase,kase,i,j,k,N,grid[200][120],dp[200][120];

	scanf("%d",&testcase);

	for(kase=1;kase<=testcase;kase++){
		
		scanf("%d",&N);
		
		for(i=0;i<200;i++){
			for(j=0;j<120;j++)
				dp[i][j]=-1;
		}

		for(i=0;i<N;i++){
			for(j=0;j<i+1;j++)
				scanf("%d",&grid[i][j]);
			grid[i][j]=-1;
		}

		for(i=N,k=1;i<2*N-1;i++,k+=2){
			for(j=0;j<i-k;j++)
				scanf("%d",&grid[i][j]);
			grid[i][j]=-1;
		}

		for(i=0;i<2*N-1;i++){
			for(j=0;dp[i][j]!=-1;j++){
				printf("%d ",dp[i][j]);
			}
			printf("\n");
		}
		
		dp[0][0]=grid[0][0];
		
		for(i=1;i<2*N-1;i++){
			for(j=0;grid[i][j]!=-1;j++){
				if(j-1>0 && grid[i][j+1]!=-1){
					dp[i][j]=find_max(dp[i-1][j-1],dp[i-1][j]) + grid[i][j];
				}else if(grid[i][j+1]!=-1){
					dp[i][j]=dp[i-1][j]+grid[i][j];
				}else{
					dp[i][j]=dp[i-1][j-1]+grid[i][j];
				}
			}
		}

		printf("Case %d: %d",kase,dp[(2*N)-2][0]);

	}

	return 0;
}