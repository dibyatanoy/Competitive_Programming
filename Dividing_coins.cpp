#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

int N,cap;
double dp[25200][102];
bool taken[25200][102];
int stones[102];

using namespace std;

double max(double a,double b){

	if(a>b) return a;
	return b;
}

double call(int used,int i){
	if(used==cap) return 0;
	if(i==N) return 0;
	if(taken[used][i]) return dp[used][i];

	double gain1=0,gain2=0;
	if(used+stones[i]<=cap) gain1=call(used+stones[i],i+1)+stones[i];
	gain2=call(used,i+1);

	dp[used][i]=max(gain1,gain2);
	taken[used][i]=1;
	return dp[used][i];
}

int main(){

	int sum=0,testcases;

	scanf("%d",&testcases);

	for(int a=0;a<testcases;a++){
	sum=0;

	scanf("%d",&N);
	memset(taken,0,sizeof(taken));

	for(int i=0;i<N;i++){
		scanf("%d",&stones[i]);
		sum+=stones[i];
	}
	double ans;
	cap=(int)sum/2;
	ans=call(0,0);

	printf("%.lf\n",fabs(sum-ans-ans));
	}

	return 0;
}

/** AC!!! **/
