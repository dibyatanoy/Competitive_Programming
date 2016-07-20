#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


int len1,len2,dp[1002][1002],i,N,M;
char str1[1002],str2[1002];

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

	while(gets(str1)&&gets(str2)){
		
		memset(dp,-1,sizeof(dp));

		N=strlen(str1);
		M=strlen(str2);
		int ans=LCS(0,0);

		printf("%d\n",ans);

	}

	return 0;
}

/** AC!!! **/