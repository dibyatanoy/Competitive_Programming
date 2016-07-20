#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

int N,cap;
double dp[25000][102];
bool taken[25000][102];
int stones[102];

using namespace std;

double max(double a,double b){

	if(a>b) return a;
	return b;
}

double call(int used,int i,int people){
	if(used==cap&&abs(people-N/2)<2) return 0;
	if(i==N&&abs(people-N/2)<2) return 0;
	if(abs(people-N/2)>1) return -30000;
	if(taken[used][i]) return dp[used][i];
	
	double gain1=0,gain2=0;
	if(used+stones[i]<=cap) gain1=call(used+stones[i],i+1,people+1)+stones[i];
	gain2=call(used,i+1,people);

	dp[used][i]=max(gain1,gain2);
	taken[used][i]=1;
	return dp[used][i];
}

int main(){

	int sum=0,testcases,k,l;

	scanf("%d",&testcases);

	for(k=0;k<testcases;k++){
	
	sum=0,l=0;
	int z=0;
	scanf("%d",&l);

	memset(taken,0,sizeof(taken));

	for(int i=0;i<l;i++){
		scanf("%d",&stones[i]);
		sum+=stones[i];
	}
	double ans;
	cap=(int)sum/2;
	ans=call(0,0,0);

	printf("%.lf %.lf\n",ans,(double)(sum-ans));
	}
	
	
	return 0;
}
