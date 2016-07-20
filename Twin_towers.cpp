#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


int len1,len2,dp[102][102],i,str1[102],str2[102],N,M;

int max(int a,int b){
	if(a>b) return a;
	return b;
}

int LCS(int i,int j){
	if(i==N) return 0;
	if(j==M) return 0;
	if(dp[i][j]!=-1) return dp[i][j];

	if(str1[i]==str2[j]) dp[i][j]=LCS(i+1,j+1)+1;
	else dp[i][j]=max(LCS(i+1,j),LCS(i,j+1));

	return dp[i][j];
}

int main(){

	int j=0;
	scanf("%d%d",&N,&M);

	while(N!=0&&M!=0){
		for(i=0;i<N;i++) scanf("%d",&str1[i]);
		for(i=0;i<M;i++) scanf("%d",&str2[i]);

		memset(dp,-1,sizeof(dp));

		int ans=LCS(0,0);

		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",++j,ans);

		scanf("%d%d",&N,&M);
	}

	return 0;
}

/** AC!!! **/