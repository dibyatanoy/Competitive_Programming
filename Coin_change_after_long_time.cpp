#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXX 100

int dp[MAXX];
int coins[]={1,2,5,10,100};

int call(){
	dp[0]=1;
	for(int i=0;i<5;i++){
		for(int k=coins[i];k<MAXX;k++){
			dp[k]+=dp[k-coins[i]];
		}
	}
	return 0;
}

int main(){

	int val,i,j;

	scanf("%d",&i);

	call();

	for(int k=0;k<i;k++){
		scanf("%d",&val);
		printf("%d",dp[val]);
	}

	return 0;
}
