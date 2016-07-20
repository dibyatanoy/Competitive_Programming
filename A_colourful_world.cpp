#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long int dp[102][102];
int points[102][102];
vector <int> balls[102];

long int max(long int a,long int b){
	if(a>b) return a;
	return b;
}

long int call(int level,int prev){
	if(level>=N) return 0;
	if(dp[level][prev]!=-5000) return dp[level][prev];
	
	long int ans=-1002;
	for(int z=0;z<balls[level].size();z++){
		int ret=call(level+1,balls[level][z])+points[prev][balls[level][z]];
		ans=max(ans,ret);
	}
	ans=max(ans,call(level+1,prev));
	dp[level][prev]=ans;
	return dp[level][prev];
}

int main(){
	
	int testcase,k,i,j,m,Q;

	scanf("%d",&testcase);

	for(j=0;j<102;j++) points[0][j]=0;

	for(i=1;i<=testcase;i++){
		scanf("%d %d",&N,&k);
		/*memset(balls,0,sizeof(balls));*/
		for(j=0;j<N;j++){
			scanf("%d",&Q);
			for(m=0;m<Q;m++){
				int x;
				scanf("%d",&x);
				balls[j].push_back(x);
			}
		}
		for(j=1;j<=k;j++){
			for(m=1;m<=k;m++) scanf("%d",&points[j][m]);
		}

		for(j=0;j<102;j++){
			for(m=0;m<102;m++) dp[j][m]=-5000;
		}


		long int ans=call(0,0);

		printf("Case %d: %ld\n",i,ans);
	}

	return 0;
}