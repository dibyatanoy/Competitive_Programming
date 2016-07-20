#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <queue>
#define maxim2(a,b) (a>b)? a:b
#define maxim(a,b,c) maxim2(a,maxim2(b,c))
#define minim2(a,b) (a<b)? a:b
#define minim(a,b,c) minim2(a,minim2(b,c))

using namespace std;
int N, dp[101][101][2],grid[101],csum[101];
bool vis[101][101][2];

int call(int i,int j,bool p){
	if(i==j) return (p==0)? grid[i]:0;
	if(i>j) return 0;

	if(vis[i][j][p]) return dp[i][j][p];

	int gain1,gain2,ret,k,s,e;

	ret=(p==0)? -100000:100000;

	if(!p){
		//ret=-100000;
		for(k=i;k<j;k++){
			s=(i==0)? csum[k]:csum[k]-csum[i-1];
			e=csum[j]-csum[k];
			//printf("i=%d,j=%d,p=%d,s=%d,e=%d\n",i,j,p,s,e);
			gain1=s+call(k+1,j,!p);
			gain2=e+call(i,k,!p);
			//printf("i=%d,j=%d,p=%d,gain1=%d,gain2=%d\n",i,j,p,gain1,gain2);
			gain1=maxim2(gain1,gain2);
			if(gain1>ret) ret=gain1;
		}
		gain1=(i==0)? csum[j]:csum[j]-csum[i-1];
		if(gain1>ret) ret=gain1;
	}else{
		//ret=100000;
		for(k=i;k<j;k++){
			//s=(i==0)? csum[k]:csum[k]-csum[i-1];
			//e=csum[j]-csum[k];
			gain1=call(k+1,j,!p);
			gain2=call(i,k,!p);
			gain1=minim2(gain1,gain2);
			if(gain1<ret) ret=gain1;
		}
		if(ret>0) ret=0;
	}
	//printf("i=%d, j=%d, p=%d, ret=%d\n",i,j,p,ret);
	vis[i][j][p]=1;
	return dp[i][j][p]=ret;
}

int main(){

	int i,j;

	while(scanf("%d",&N)&&N!=0){
		memset(csum,0,sizeof(csum));
		for(i=0;i<N;i++){
			scanf("%d",&grid[i]);
			csum[i]=(i==0)? grid[i]:csum[i-1]+grid[i];
		}
		memset(vis,0,sizeof(vis));
		printf("%d\n",2*call(0,N-1,0)-csum[N-1]);
	}

	return 0;
}

/** AC!!! **/