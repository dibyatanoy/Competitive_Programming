#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


int len1,len2,dp[102][102],i;
char str1[102],str2[102];
bool v[102];

int max(int a,int b){
	if(a>b) return a;
	return b;
}

int LCS(int N,int M,int i,int j){

	/*int a,b;

	for(a=0;a<N;a++) dp[0][a]=0;
	for(a=0;a<M;a++) dp[a][0]=0;
	memset(v,0,sizeof(v));

	for(a=1;a<=N;a++){
		for(b=1;b<=M;b++){
			if(str1[a-1]==str2[b-1] && !v[str1[a-1]]) dp[a][b]=1+dp[a-1][b-1];
			else dp[a][b]=max(dp[a][b-1],dp[a-1][b]);
		}
	}*/


	if(i==N) return 0;
	if(j==M) return 0;
	if(dp[i][j]!=-1) return dp[i][j];

	if(str1[i]==str2[j]) dp[i][j]=LCS(N,M,i+1,j+1)+1;
	else dp[i][j]=max(LCS(N,M,i+1,j),LCS(N,M,i,j+1));

	return dp[i][j];
}

int main(){

	int j=0;
	gets(str1);
	while(str1[0]!='#'){
		gets(str2);

		int N=strlen(str1);
		int M=strlen(str2);
		memset(dp,-1,sizeof(dp));
		int ans=LCS(N,M,0,0);

		printf("Case #%d: you can visit at most %d cities.\n",++j,ans);
		gets(str1);

	}

	return 0;
}

/** AC!!! **/