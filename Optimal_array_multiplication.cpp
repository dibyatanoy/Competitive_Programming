#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int matrices,costs[15];
int dp[15][15],s[15][15];

int prt_optimal(int i,int j){
	if(i==j) printf("A%d",i);
	else{
		printf("(");
		prt_optimal(i,s[i][j]);
		printf(" x ");
		prt_optimal(s[i][j]+1,j);
		printf(")");
	}
	return 0;
}

int MCM(int length){
	int q,i;
	int n=length-1;
	for(i=1;i<=n;i++){
		dp[i][i]=0;
	}
	for(int l=2;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j=i+l-1;
			dp[i][j]=2000000000;
			for(int k=i;k<=j-1;k++){
				q=dp[i][k]+dp[k+1][j]+costs[i-1]*costs[k]*costs[j];
				if(q<dp[i][j]){
					//printf("Updating: dp[%d][%d]=%d ",i,j,q);
					dp[i][j]=q;
					//ret=q;
					s[i][j]=k;
				}
			}
		}
	}
	prt_optimal(1,length-1);
	return dp[1][length-1];
}

int main(){

	scanf("%d",&matrices);
	int testcase=0,i,k=0;

	while(matrices!=0){
		int started=0;
		k=0;
		memset(s,-1,sizeof(s));
		memset(dp,-1,sizeof(dp));
		for(i=1;i<=matrices;i++){
			int row,col;
			scanf("%d%d",&row,&col);
			if(!started){costs[k++]=row;started=1;}
			costs[k++]=col;

		}
		printf("Case %d: ",++testcase);
		MCM(k);
		printf("\n");
		scanf("%d",&matrices);
	}


	return 0;
}

/** AC!!! **/