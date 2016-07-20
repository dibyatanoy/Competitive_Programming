#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

int N,cap;
double dp[24000][105];
bool taken[24000][105];
int stones[105];

using namespace std;

double max(double a,double b){

	if(a>b) return a;
	return b;
}

double call(int used,int i,int people){
	if(used==cap&&abs(people-N/2)<2) return 0;
	if(i==N&&abs(people-N/2)<2) return 0;
	if(taken[used][i]&&abs(people-N/2)<2) return dp[used][i];
	
	double gain1=0,gain2=0;
	if(used+stones[i]<=cap) gain1=call(used+stones[i],i+1,people+1)+stones[i];
	gain2=call(used,i+1,people);

	dp[used][i]=max(gain1,gain2);
	taken[used][i]=1;
	return dp[used][i];
	return -30000;
}

int main(){

	int sum,testcases,k;

	scanf("%d",&testcases);

	for(k=0;k<testcases;k++){
	
		sum=0;
		scanf("%d",&N);

	memset(taken,0,sizeof(taken));

	for(int i=0;i<N;i++){
		scanf("%d",&stones[i]);
		sum+=stones[i];
	}
	double ans;
	cap=(int)sum/2;
	ans=call(0,0,0);

	printf("%.lf %.lf\n\n",ans,(double)(sum-ans));
	}
	
	
	return 0;
}
