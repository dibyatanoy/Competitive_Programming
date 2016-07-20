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
#include <cmath>
#define pb push_back
#define MP make_pair
#define minim(a,b) ((a)<(b)? (a):(b))
#define INF 1e7
#define MAXX 9
#define all(v) v.begin(),v.end()

using namespace std;
int n,k,dp[103][103][6];
char seq[103];
bool vis[103][103][6],op;

int call(int i,int j,int done){
	if(i>j) {printf("here\n");return 0;}

	if(i==j && done==k-1) return 1;
	
	if(vis[i][j][done]) return dp[i][j][done];

	int ret=INF;
	//printf("here\n");

	if(done==k-1) ret=minim(ret,call(i+1,j,0)+1);

	int x;
	for(x=i+1;x<=j;x++){
		if(seq[x]==seq[i]) ret=minim(ret,call(i+1,x-1,0)+call(x,j,minim(k-1,done+1)));
	}
	vis[i][j][done]=1;
	return dp[i][j][done]=ret;
}

int main(){

	scanf("%d %d",&n,&k);

	scanf("%s",seq);

	if(seq[0]=='G') op=0;
	else op=1;

	if(call(0,n-1,0)>100) printf("-1\n");
	else printf("%d\n",call(0,n-1,0));

	return 0;
}

/** AC!!! **/