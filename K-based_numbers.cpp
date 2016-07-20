#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

double dp[25][25];
bool taken[25][25];
int N,K;

int call(int digit,int last){
	if(digit==N) return 1;
	if(taken[digit][last]) return dp[digit][last];

	double gain1=0,gain2=0;

	gain1=(K-1)*call(digit+1,1);
	if(last!=0) gain2=call(digit+1,0);

	dp[digit][last]=gain1+gain2;

	return dp[digit][last];
}

int main(){

	scanf("%d%d",&N,&K);
	memset(taken,0,sizeof(taken));

	double ans=call(1,1)*(K-1);

	printf("%.lf\n",ans);

	return 0;
}
/* AC!!! */