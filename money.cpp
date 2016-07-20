/*
ID: dibyapo2
TASK: money
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
int coins[26];
long long int dp[10010];
int V,N;

int call(){
	memset(dp,0,sizeof(dp));

	dp[0]=1;
	int i,j;
	for(j=0;j<V;j++){
		for(i=coins[j];i<=N;i++) dp[i]+=dp[i-coins[j]];
	}
	return 0;
}

int main(){

	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d %d",&V,&N);

	int i;

	for(i=0;i<V;i++){
		scanf("%d",&coins[i]);
	}
	call();

	printf("%lld\n",dp[N]);

	return 0;
}
/** AC!!! **/