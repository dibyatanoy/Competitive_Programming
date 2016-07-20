#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
#define pb push_back
#define MP make_pair
#define maxim(a,b) ((a)>(b)? (a):(b))
#define minim(a,b) ((a)<(b)? (a):(b))
#define INF 1e5
#define MAXX 30005
#define all(v) v.begin(),v.end()

using namespace std;

int dp[30002][2],N,d[30002];

int call(int pos,int v){
	if(pos==N) return 0;
	if(dp[pos][v]!=-1) return dp[pos][v];

	int ret=40000;
	if((d[pos]-1)==v){
		ret=minim(ret,call(pos+1,v));
		if(v==0) ret=minim(ret,call(pos+1,!v));
	}else{
		ret=minim(ret,call(pos+1,v)+1);
		if(v==0) ret=minim(ret,call(pos+1,!v));
	}

	return dp[pos][v]=ret;
}

int main(){

	scanf("%d",&N);

	int i,j;
	for(i=0;i<N;i++) scanf("%d",&d[i]);
	memset(dp,-1,sizeof(dp));

	int ans=minim(call(0,0),call(0,1));

	printf("%d\n",ans);

	return 0;
}