#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define MAXX 1002

using namespace std;
int N;
vector <int> edges[MAXX];
int dp[MAXX][2];
int par[MAXX];

int minim(int a,int b){
	if(a<b) return a;
	return b;
}

int call(int u,int isGuard){
	//printf("Reached!\n");
	if(edges[u].size()==0) return isGuard;
	if(dp[u][isGuard]!=-1) return dp[u][isGuard];

	int gain=0,i;
	for(i=0;i<(int)edges[u].size();i++){
		int v=edges[u][i];
		if(par[u]!=v){
			par[v]=u;
			if(!isGuard) gain+=call(v,1);
			else{
				gain+=minim(call(v,0),call(v,1));
			}
		}
	}
	dp[u][isGuard]=gain+isGuard;
	return dp[u][isGuard];
}

int main(){

	while(scanf("%d",&N)&&N!=0){
		int i,j;
		for(i=0;i<MAXX;i++) edges[i].clear();
		memset(par,-1,sizeof(par));
		for(i=1;i<=N;i++){
			int cnt;
			scanf("%d",&cnt);
			for(j=0;j<cnt;j++){
				int u;
				scanf("%d",&u);
				edges[i].push_back(u);
			}
		}
		memset(dp,-1,sizeof dp);
		int ans=minim(call(1,0),call(1,1));
		if(edges[1].size()==0) ans=1;
		printf("%d\n",ans);
	}

	return 0;
}
/** AC!!! **/