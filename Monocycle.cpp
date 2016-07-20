#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct data{
	int x,y,dir_now;
	bool dir[4];
	memset(dir,0,sizeof(dir));
};

queue <data> Q;
int M,N;
char grid[26][26];

int bfs(int st_x,st_y){
	data src;
	bool taken[26][26][4];
	memset(taken,0,sizeof(taken));
	int dist[26][26][4];
	src.x=st_x;
	src.y=st_y;
	src.dir_now=0;
	src.dir[0]=true;
	Q.push(src);
	taken[src.x][src.y][src.dir_now]=true;
	dist[src.x][src.y][src.dir_now]=0;

	while(!Q.empty()){
		
	}
}

int main(){

	while(scanf("%d %d",&M,&N)&&M!=0&&N!=0){
		int i,j,st_x,st_y;
		bool found=false;

		for(i=0;i<M;i++){
			scanf("%s",grid[i]);
		}

		for(i=0;i<M;i++){
			for(j=0;j<N;j++){
				if(grid[i][j]=='S'){
					st_x=i;
					st_y=j;
					found=1;
					break;
				}
			}
			if(found) break;
		}

		int ans=bfs(st_x,st_y);
	}


	return 0;
}
	
