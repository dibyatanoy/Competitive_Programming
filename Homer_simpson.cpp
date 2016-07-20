#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[10002],val[2],cap;

int call(){
	int i,j;
	dp[val[0]]=1;
	dp[val[1]]=1;
	for(i=0;i<2;i++){
		for(j=val[i]+1;j<=cap;j++){
			if(dp[j-val[i]]!=0&&dp[j-val[i]]+1>dp[j]) dp[j]=dp[j-val[i]]+1;
		}
	}
	return 0;
}

int main(){

	while(scanf("%d %d %d",&val[0],&val[1],&cap)==3){
		memset(dp,0,sizeof(dp));

		call();
	//for(int i=0;i<=cap;i++) printf("%d ",dp[i]);
		for(int k=cap;k>=0;k--){
			if(dp[k]>0){
				if(k==cap) printf("%d\n",dp[k]);
				else printf("%d %d\n",dp[k],cap-k);
				break;
			}
			if(k==0) printf("0 %d\n",cap);
		}
	}
	return 0;
}

/** AC!!! **/