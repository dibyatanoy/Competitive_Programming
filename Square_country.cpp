#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

double dp[60003];
int cap,sqrnum[247];

int main(){
	int i,j;
	scanf("%d",&cap);
	for(i=0;i<=245;i++){sqrnum[i]=i*i;}
	for(i=0;i<60003;i++)  dp[i]=500000;
	dp[0]=0;

	for(i=1;i<=sqrnum[i];i++){
		for(j=0;j+sqrnum[i]<=cap;j++){
			if(dp[j+sqrnum[i]]>dp[j]+1) dp[j+sqrnum[i]]=dp[j]+1;
		}
	}
	

	printf("%.lf\n",dp[cap]);

	return 0;
}