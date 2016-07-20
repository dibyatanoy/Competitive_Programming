#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long int coins[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
double dp[6005];
double amount;

int max(int a,int b){
	if(a>b) return a;
	return b;
}

int change(){

	dp[0]=1;

	for(int i=0;i<11;i++){
		for(int k=coins[i]/5;k<6005;k++){
			
			dp[k]+=dp[k-coins[i]/5];
			
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
	while(scanf("%lf",&amount)==1&&amount!=0.00){
		int index=(int)(amount*20);

		printf("%6.2lf%17.lf\n", amount, dp[index]);
	}
	

	return 0;
}

/** AC!!! **/