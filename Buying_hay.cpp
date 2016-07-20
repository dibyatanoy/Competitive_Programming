#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

long int dp[2500][1000];
int costs[1000],amounts[1000];
int need,number;

long int min(long int a,long int b){
	if(a<b) return a;
	return b;
}

long int call(int i,int rem){

	if(i<1) return 2000000000;
	if(dp[i][rem]!=-1) return dp[i][rem];
	long int profit1,profit2;

	if(rem>0){
		profit1=min(call(i,rem-amounts[i]),call(i-1,rem-amounts[i]));
		if(profit1<2000000000) profit1+=costs[i];		//Important: If answer is invalid, don't take it;
		else profit1=costs[i];

		profit2=call(i-1,rem);
		
		dp[i][rem]=min(profit1,profit2);
		return dp[i][rem];
	}

	return 2000000000;

}

int main(){
	
	long int ans;

	while(scanf("%d%d",&number,&need)==2){
		
		for(int j=1;j<=number;j++){
			scanf("%d %d",&amounts[j],&costs[j]);
		}

		memset(dp,-1,sizeof(dp));

		ans=call(number,need);

		printf("%ld\n",ans);

	}


	return 0;
}

/** Seems to be working !!! My first DP variant of 0-1 knapsack.**/
/** BTW,this problem is from USACO and appeared in BAPS programming camp 2013 contest-3 **/