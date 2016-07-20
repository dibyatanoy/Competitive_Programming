#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

int N;
double dp[502][502];
bool taken[502][502];

using namespace std;

double call(int used,int i){
	if(used==N) return 1;
	if(used+i>N) return 0;
	if(taken[used][i]) return dp[used][i];

	double gain1,gain2;
	gain1=call(used+i,i+1);
	gain2=call(used,i+1);

	dp[used][i]=gain1+gain2;
	taken[used][i]=1;
	return dp[used][i];
}

int main(){

	scanf("%d",&N);
	memset(dp,-1,sizeof(dp));
	memset(taken,0,sizeof(taken));
	double ans=call(0,1);

	printf("%.lf\n",ans-1);

	return 0;
}

/** AC!!! **/