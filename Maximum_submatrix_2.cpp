#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#define maxim(a,b) (a>b)? a:b

using namespace std;
int N,M;
char grid[5002][5002];
int dp[5002][5002];

int main(){


	int i,j,k;
	int curr_col[5002];
	memset(dp,0,sizeof(dp));

	scanf("%d %d",&N,&M);

	for(i=0;i<N;i++) scanf("%s",grid[i]);

	int ans=0;

	for(j=M-1;j>=0;j--){
		
		for(i=0;i<N;i++){
			if(j==M-1) dp[i][j]=grid[i][j]-'0';
			else dp[i][j]=(grid[i][j]-'0')*(dp[i][j+1]+1);
			curr_col[i]=dp[i][j];
		}
		sort(curr_col,curr_col+N);
		int sz=N;
		for(i=0;i<sz;i++){
			ans=maxim(ans,curr_col[i]*(sz-i));
		}
	}
	printf("%d\n",ans);

	return 0;
}