#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#define MAXX 100004

using namespace std;

vector<int> dv[MAXX];
double dp[MAXX];

int main(){

	int i,j;
	int ub=(int)sqrt(MAXX);
	memset(dv,0,sizeof(dv));

	for(i=1;i<ub;i++){
		for(j=i;i*j<=MAXX;j++) {
			if(i!=j) {dv[i*j].push_back(i);dv[i*j].push_back(j);}
			else dv[i*j].push_back(i);
		}
	}
	

	for(i=0;i<=MAXX;i++) dp[i]=0.0;
	dp[1]=0.0;

	for(i=2;i<=MAXX;i++){
		int n=dv[i].size();
		for(j=0;j<n;j++){
			if(dv[i][j]!=i) dp[i]+=(dp[dv[i][j]]+1.000);
		}
		dp[i]+=1.000;
		dp[i]/=(double)(n-1);
	}

	int kases;
	scanf("%d",&kases);

	for(i=1;i<=kases;i++){
		int req;
		scanf("%d",&req);
		printf("Case %d: %.10lf\n",i,dp[req]);
	}
	memset(dv,0,sizeof(dv));
	memset(dp,0,sizeof(dp));
	//printf("!");

	return 0;
}

/** AC!!! **/