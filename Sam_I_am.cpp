#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <fstream>
#define ROW 0
#define COL 1

using namespace std;

bool grid[1001][1001],vis[1001][1001];
int r,c,n,dp[1001][1001],low[1001],rt[1001],nextc[1001],nextr[1001];
bool d[1001][1001];

void fire(int i,int j){
	if(i==0||j==0||i>r||j>c) return;
	int nc=j,nr=i;
	while(low[nc]<=i){
		nc=nextc[nc];
	}
	while(rt[nr]<=j){
		nr=nextr[nr];
	}
	if(d[i][j]==ROW){
		printf(" r%d",i);
		fire(nextr[i],nc);
	}else{
		printf(" c%d",j);
		fire(nr,nextc[j]);
	}
	return;
}

int call(int i,int j){
	if(i==0||j==0||i>r||j>c) return 0;
	if(vis[i][j]) return dp[i][j];

	int gain1,gain2,nc=j,nr=i;
	while(low[nc]<=i){
		nc=nextc[nc];
	}
	while(rt[nr]<=j){
		nr=nextr[nr];
	}
	//printf("i=%d,j=%d,nc=%d,nr=%d\n",i,j,nc,nr);

	gain1=1+call(nextr[i],nc);
	gain2=1+call(nr,nextc[j]);

	if(gain1<=gain2){
		dp[i][j]=gain1;
		d[i][j]=ROW;
	}else{
		dp[i][j]=gain2;
		d[i][j]=COL;
	}

	vis[i][j]=0;
	return dp[i][j];
}

int main(){

	while(scanf("%d %d %d",&r,&c,&n)&&r&&c&&n){
		int i,j;
		memset(grid,0,sizeof(grid));
		memset(nextr,0,sizeof(nextr));
		memset(nextc,0,sizeof(nextc));
		rt[0]=100000;
		low[0]=100000;

		for(i=0;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			grid[x][y]=1;
		}
		int prev=0;
		bool fnd=0;

		for(i=1;i<=r;i++){
			fnd=0;
			for(j=1;j<=c;j++){
				if(grid[i][j]){
					nextr[prev]=i;
					rt[i]=j;
					fnd=1;
				}
			}
			if(fnd) prev=i;
		}
		prev=0;
		fnd=0;

		for(i=1;i<=c;i++){
			fnd=0;
			for(j=1;j<=r;j++){
				if(grid[j][i]){
					//printf("Found enemy at [%d][%d]\n",j,i);
					nextc[prev]=i;
					low[i]=j;
					fnd=1;
				}
			}
			if(fnd) prev=i;
		}

		
		memset(vis,0,sizeof(vis));

		for(i=0;i<=r;i++){
			printf("%d ",nextr[i]);
		}
		printf("\n");
		for(i=0;i<=c;i++){
			printf("%d ",nextc[i]);
		}
		printf("\n");
		for(i=0;i<=r;i++){
			printf("%d ",rt[i]);
		}
		printf("\n");
		for(i=0;i<=c;i++){
			printf("%d ",low[i]);
		}
		printf("\n");

		int ans=call(nextr[0],nextc[0]);

		printf("%d",ans);
		fire(nextr[0],nextc[0]);

		printf("\n");
	}
	
	return 0;
}

/** FAILED :< **/