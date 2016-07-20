#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define MOD 1000000007

using namespace std;
char seq[1004];
__int64 dp[1004][1004];
bool vis[1004][1004];
int n;

__int64 call(int pos,int vac){
	if(vac<0) return 0;
	if(pos==n){
		if(vac) return 0;
		else return 1;
	}
	if(vis[pos][vac]) return dp[pos][vac];
	__int64 gain=0;
	if(seq[pos]=='U'){
		
		gain=(call(pos+1,vac+1)+(vac)*call(pos+1,vac))%MOD;
	}else if(seq[pos]=='D'){
		gain=(vac*call(pos+1,vac)+(vac)*vac*call(pos+1,vac-1))%MOD;
	}else{
		gain=call(pos+1,vac)%MOD;
	}

	vis[pos][vac]=1;
	return dp[pos][vac]=gain;
}

int main(){

	int kases,i,j;
	scanf("%d",&kases);

	for(i=1;i<=kases;i++){
		scanf("%s",seq);
		memset(vis,0,sizeof(vis));
		n=strlen(seq);

		printf("Case %d: %I64d\n",i,call(0,0)%MOD);
	}

	return 0;
}

/** AC!!! **/