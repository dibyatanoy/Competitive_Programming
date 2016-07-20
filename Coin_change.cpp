#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int amount,coins[5]={1,5,10,25,50};
double dp[30003];

int max(int a,int b){
	if(a>b) return a;
	return b;
}

int change(){

	dp[0]=1;

	for(int i=0;i<5;i++){
		for(int k=coins[i];k<30003;k++){
			dp[k]+=dp[k-coins[i]];
			//dp[i][k]=dp[i][k-1];
			//if(i>=coins[k]) dp[i][k]+=max(dp[i-coins[k]][k],dp[i-coins[k]][k-1]);
		}
	}
	
/*	if(need==0) return 1;
	if(index>=5) return 0;

	if(dp[need][index]!=-1) return dp[need][index];

	int ways1=0,ways2=0;

	ways1=change(need,index+1);

	if(need>=coins[index]){
		ways2=max(change(need-coins[index],index),change(need-coins[index],index+1));*/
	return 0;

	

	//dp[need][index]=ways1+ways2;
	//	return dp[need][index];
}

int main(){

	memset(dp,0,sizeof(dp));
	

	change();
	while(scanf("%d",&amount)==1){
		
		if(dp[amount]==1) printf("There is only 1 way to produce %d cents change.\n",amount);
		else printf("There are %.lf ways to produce %d cents change.\n",dp[amount],amount);
	}
	

	return 0;
}

/** AC!!! **/