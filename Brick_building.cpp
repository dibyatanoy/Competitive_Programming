#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

long long int fact(int x,int y){			//Simple dp: dp[1]=1,dp[2]=2,
											//dp[i]=dp[i-1]+dp[i-2] for i>=3
	long long int ret=1,i,k=x,j=y;
	for(i=x+y;i>1;i--){
		ret*=i;
		while(k&&(ret%k)==0){
			ret/=k;
			k--;
		}
		while(j&&(ret%j)==0){
			ret/=j;
			j--;
		}
	}
	return ret;
}

int main(){

	int x,y,i,n;
	long long int ans=0;
	while(scanf("%d",&n) && n!=0){

		ans=0;
		for(x=0,y=n;y>=0;x++,y=n-2*x){
			ans+=fact(x,y);
		}
		printf("%lld\n",ans);

	}

	return 0;
}