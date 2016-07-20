/*
ID: dibyapo2
PROG: subset
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

long long int dp[7802],N;

int main(){

	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);

	int i,j;
	scanf("%d",&N);
	memset(dp,0,sizeof(dp));
	int max=N*(N+1)/2;

	if((max%2)!=0){
		printf("0\n");
		return 0;
	}
	dp[0]=1;

	for(i=1;i<=N;i++){
		for(j=max;j>=i;j--) dp[j]+=dp[j-i];
	}

	printf("%lld\n",dp[max/2]/2);

	return 0;
}