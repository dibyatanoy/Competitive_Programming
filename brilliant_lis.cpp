#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){

	int i,j,k,n;

	int num[1001];
	int dp[1001],max_len=0,max_pos;
	int par[1001];

	
	scanf("%d",&n);

	for(i=0;i<n;i++){
		dp[i]=1;
	}

	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(i=0;i<n;i++){
		par[i]=i;
	}
	for(i=1;i<n;i++){
		j=i-1;
			if(num[j]<num[i]) {
				dp[i]=dp[j]+1;
				par[i]=j;
			}
		
	}
	for(j=n-1;j>=0;j--){
		if(dp[j]>=max_len){
			max_pos=j;
			max_len=dp[j];
		}
	}
	/*for(i=0;i<n;i++){
		printf("%d ",dp[i]);
	}
	printf("%d",max_len);*/
	int sum=0;
	for(i=max_pos;i>max_pos-max_len;i--) sum+=num[i];

	printf("%d ",abs(sum));


	return 0;
}