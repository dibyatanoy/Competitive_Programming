#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#define MAXX 1<<16

using namespace std;

int dp[MAXX+2],damage[16][16],health[16],n;
bool taken[MAXX+2];

int Set(int N,int pos){return N=N | (1<<pos);} 
int reset(int N,int pos){return N= N & ~(1<<pos);} 
bool check(int N,int pos){return (bool)(N & (1<<pos));} 

int minim(int a,int b){
	if(a<b) return a;
	return b;
}


int call(int bt){
	if(bt==(1<<n)-1) return 0;
	if(taken[bt]) return dp[bt];

	int ret=1e6,i,j;

	for(i=0;i<n;i++){
		if(check(bt,i)==0){
			int temp=Set(bt,i);
			int max_wp=0;
			for(j=0;j<n;j++){
				if(check(bt,j)==1&&damage[j][i]>max_wp) max_wp=damage[j][i];
			}
			if(max_wp==0) max_wp=1;

			ret=minim(ret,call(temp)+ceil(health[i]/(double)(max_wp)));

		}
	}
	taken[bt]=1;
	return dp[bt]=ret;

}

int main(){
	
	int testcases,i,j;
	char dmg[18];

	scanf("%d",&testcases);
	for(i=1;i<=testcases;i++){
		memset(taken,0,sizeof(taken));
		scanf("%d",&n);
		for(j=0;j<n;j++) scanf("%d",&health[j]);

		for(j=0;j<n;j++){
			scanf("%s",dmg);
			for(int k=0;k<n;k++) damage[j][k]=(int)dmg[k]-'0';
		}

		int ans=call(0);
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}

/** AC!!! **/