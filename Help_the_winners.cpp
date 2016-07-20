#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

long long int dp[16][1<<16][3];
int n,status[16][16];
bool visited[16][1<<16][3];

int Set(int N,int pos){return N=N|(1<<pos);}
int reset(int N,int pos){return N=N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N&(1<<pos));}

long long int call(int pos,int mask,int val){
	if(pos==n&&val!=0) return 1;
	else if(pos==n) return 0;
	if(visited[pos][mask][val]) return dp[pos][mask][val];

	long long int ways1=0;
	int i;

	if(val==2){
		for(i=0;i<n;i++){
			if(check(mask,i)==0){
				int temp=Set(mask,i);
				ways1+=call(pos+1,temp,val);
			}
		}
		dp[pos][mask][val]=ways1;
		
	}else if(val==1){
		for(i=0;i<n;i++){
			if(check(mask,i)==0){
				int temp=Set(mask,i);
				ways1+=call(pos+1,temp,status[pos][i]);
			}
		}
		dp[pos][mask][val]=ways1;
	}else{
		for(i=0;i<n;i++){
			if(check(mask,i)==0){
				int temp=Set(mask,i);

				if(status[pos][i]!=2) ways1+=call(pos+1,temp,0);
				else ways1+=call(pos+1,temp,2);
			}
		}
		dp[pos][mask][val]=ways1;
	}
	visited[pos][mask][val]=1;
	return dp[pos][mask][val];
}


int main(){

	int testcases,i,j,k;

	scanf("%d",&testcases);

	for(i=1;i<=testcases;i++){
		memset(visited,0,sizeof(visited));
		scanf("%d",&n);

		for(k=0;k<n;k++){
			for(j=0;j<n;j++) scanf("%d",&status[k][j]);
		}
		long long int ans=0;

		ans=call(0,0,1);

		printf("Case %d: %lld\n",i,ans);
	}


	return 0;
}

/** AC!!! But %lld not working here **/