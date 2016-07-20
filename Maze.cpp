#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int rem,n,m;
char grid[502][502];
bool vis[502][502];

void dfs(int i,int j){
	vis[i][j]=1;
	if(i+1<n && grid[i+1][j]!='#' && !vis[i+1][j]) dfs(i+1,j);
	if(i-1>=0 && grid[i-1][j]!='#' && !vis[i-1][j]) dfs(i-1,j);
	if(j+1<m && grid[i][j+1]!='#' && !vis[i][j+1]) dfs(i,j+1);
	if(j-1>=0 && grid[i][j-1]!='#' && !vis[i][j-1]) dfs(i,j-1);

	if(rem>0){
		rem--;
		grid[i][j]='X';
	}
	return;

}

int main(){

	scanf("%d %d %d",&n,&m,&rem);

	int i,j;
	for(i=0;i<n;i++) scanf("%s",grid[i]);
	memset(vis,0,sizeof(vis));

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(grid[i][j]=='.'){
				dfs(i,j);
				break;
			}
		}
	}

	for(i=0;i<n;i++){
		printf("%s\n",grid[i]);
	}

	return 0;
}

/** AC!!! **/