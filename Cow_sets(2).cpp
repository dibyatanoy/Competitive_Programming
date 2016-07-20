#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N,A,B;
int id[1000];
int dp[50002][36];
bool taken[50002][36];

int call(int sum,int i){
	if(i==N){
		if((sum-20000)>=A&&(sum-20000)<=B) return 1;
		else return 0;
	}
	if(taken[sum][i]) return dp[sum][i];

	dp[sum][i]=call(sum+id[i],i+1)+call(sum,i+1);
	taken[sum][i]=1;

	return dp[sum][i];
}

int main(){

	scanf("%d %d %d",&N,&A,&B);
	for(int i=0;i<N;i++) scanf("%d",&id[i]);

	memset(dp,0,sizeof(dp));
	int ans=call(id[0]+20000,1)+call(20000,1);


	printf("%d\n",ans);
	return 0;
}