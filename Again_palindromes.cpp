#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long int dp[62][62];
bool taken[62][62];
char str[62];

long int call(int i,int j){
	if(i==j) return 1;
	if(i>j) return 0;
	if(taken[i][j]) return dp[i][j];

	int common;
	common=call(i+1,j-1);
	dp[i][j]=call(i+1,j)+call(i,j-1)-common;
	if(str[i]==str[j]) dp[i][j]+=common+1;

	taken[i][j]=1;
	return dp[i][j];
}

int main(){

	int testcases,i,length;

	scanf("%d",&testcases);

	for(i=1;i<=testcases;i++){
		scanf("%s",str);
		length=strlen(str);
		memset(taken,0,sizeof(taken));

		printf("%ld\n",call(0,length-1));
	}

	return 0;
}