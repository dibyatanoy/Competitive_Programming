#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int dp[1000010];
vector <int> coins;
int A,B,N;

int main(){

	int i,j,k;
	scanf("%d %d %d",&N,&A,&B);

	for(i=0;i<N;i++){
		int a;
		scanf("%d",&a);
		coins.push_back(a);
	}
	sort(coins.begin(),coins.end());
	memset(dp,0,sizeof(dp));
	dp[500000]=1;
	for(i=0;i<N;i++){
		for(j=coins[i]+500000;j<=A+500000;j++){
			dp[j]+=dp[j-coins[i]];
		}
	}
	int sum;
	for(i=B+500000;i<=A+500000;i++) sum+=dp[i];
	printf("%d\n",sum);

	return 0;
}