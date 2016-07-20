/*
ID: dibyapo2
LANG: C++
PROG: satpix
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define maxim(a,b) (a>b)? a:b

using namespace std;
int w,h;
bool vis[1002][82];
char grid[1002][82];

int flood(int x,int y){

	if(x<0 || x >=h || y<0 || y>=w) return 0;
	vis[x][y]=1;
	int ret=1;

	if(grid[x-1][y]=='*' && (!vis[x-1][y])) ret+=flood(x-1,y);
	if(grid[x+1][y]=='*' && (!vis[x+1][y])) ret+=flood(x+1,y);
	if(grid[x][y-1]=='*' && (!vis[x][y-1])) ret+=flood(x,y-1);
	if(grid[x][y+1]=='*' && (!vis[x][y+1])) ret+=flood(x,y+1);

	//printf("x=%d,y=%d,ret=%d\n",x,y,ret);

	return ret;
	
}

int main(){

	freopen("satpix.in","r",stdin);
	freopen("satpix.out","w",stdout);

	scanf("%d %d",&w,&h);

	int i,j;
	for (i=0;i<h;i++){
		scanf("%s",grid[i]);
	}
	memset(vis,0,sizeof vis);
	//printf("! ");

	int ans=0;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(grid[i][j]=='*'&& !vis[i][j]) {int ret1=flood(i,j);/*printf("Start! x=%d,y=%d,ret=%d",i,j,ret1);*/ans=maxim(ans,ret1);} 
		}
	}
	printf("%d\n",ans);
	
	
	return 0;
}
/** AC!!! **/