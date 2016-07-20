#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define INF 1e8

using namespace std;
int n,k,a[101],b[101];
int dp[102][110002];
bool vis[102][110002];

int call(int pos,int sum){
	if(pos==n){
		if(sum==0) return 0;
		else return -INF;
	}
	if(vis[pos][sum+99901]) return dp[pos][sum+99901];

	int gain1,gain2;

	gain1=a[pos]+call(pos+1,sum+a[pos]-k*b[pos]);
	gain2=call(pos+1,sum);


	if(gain1>gain2&&gain1>=0){
		dp[pos][sum+99901]=gain1;
	}else if(gain2>=0){
		dp[pos][sum+99901]=gain2;
	}else{
		//printf("pos=%d, gain1=%d, gain2=%d",pos,gain1,gain2);
		dp[pos][sum+99901]=-INF;
	}
	vis[pos][sum+99901]=1;
	return dp[pos][sum+99901];
}


int main(){

	scanf("%d %d",&n,&k);

	int i,j;

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	memset(vis,0,sizeof(vis));
	int ans=call(0,0);

	if(ans>0) printf("%d\n",ans);
	else printf("-1\n");

	return 0;
}