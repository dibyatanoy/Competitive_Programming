#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

struct data{
	int x,j;
	bool r,b,y,g;
};

int r,c,move_x[]={0,-1,1,0};
int move_y[]={1,0,0,-1};
char grid[103][103];
bool vis[103][103][2][2][2][2];
int dist[103][103][2][2][2][2];

int bfs(int src_x,int src_y){
	queue <data> Q;
	dist[src_x][src_y][0][0][0][0]=0;
	vis[src_x][src_y][0][0][0][0]=1;

	data src; src.x=src_x;src.j=src_y;src.r=src.b=src.g=src.y=0;

	Q.push(src);

	while(!Q.empty()){
		//printf("Here \n");
		data u=Q.front();Q.pop();

		if(grid[u.x][u.j]=='X') return dist[u.x][u.j][u.r][u.b][u.y][u.g];

		for(int i=0;i<4;i++){
			if((u.x+move_x[i]>=0) && (u.x+move_x[i]<r) && (u.j+move_y[i]>=0) && (u.j+move_y[i]<c) ){
				if(grid[u.x+move_x[i]][u.j+move_y[i]]=='#') continue;
				else if(!vis[u.x+move_x[i]][u.j+move_y[i]][u.r][u.b][u.y][u.g] && grid[u.x+move_x[i]][u.j+move_y[i]]=='.'){
					vis[u.x+move_x[i]][u.j+move_y[i]][u.r][u.b][u.y][u.g]=1;
					data temp;
					temp.x=u.x+move_x[i];
					temp.y=u.j+move_y[i];
					temp.r=u.r;
					temp.b=u.b;
					temp.y=u.y;
					temp.g=u.g;
					dist[u.x+move_x[i]][u.j+move_y[i]][u.r][u.b][u.y][u.g]=dist[u.x][u.j][u.r][u.b][u.y][u.g]+1;
					Q.push(temp);
					//printf("Here \n");
					//printf("Here \n");
				}else if(vis[u.x+move_x[i]][u.j+move_y[i]][u.r][u.b][u.y][u.g] && grid[u.x+move_x[i]][u.j+move_y[i]]=='*'){
					vis[u.x+move_x[i]][u.j+move_y[i]][u.r][u.b][u.y][u.g]=1;
					data temp;
					//printf("Here \n");
					temp.x=u.x+move_x[i];
					temp.j=u.j+move_y[i];
					temp.r=u.r;
					temp.b=u.b;
					temp.y=u.y;
					temp.g=u.g;
					dist[u.x+move_x[i]][u.j+move_y[i]][u.r][u.b][u.y][u.g]=dist[u.x][u.j][u.r][u.b][u.y][u.g]+1;
					Q.push(temp);
				}else if(!vis[u.x+move_x[i]][u.j+move_y[i]][u.r][u.b][u.y][u.g] && grid[u.x+move_x[i]][u.j+move_y[i]]>='a' && grid[u.x+move_x[i]][u.j+move_y[i]]<='z'){
					char curr=grid[u.x+move_x[i]][u.j+move_y[i]];
					data t2;
					t2.r=u.r;t2.b=u.b;t2.y=u.y;t2.g=u.g;
					if(curr=='r') {vis[u.x+move_x[i]][u.j+move_y[i]][1][u.b][u.y][u.g]=1;t2.r=1;}
					else if(curr=='b') {vis[u.x+move_x[i]][u.j+move_y[i]][u.r][1][u.y][u.g]=1;t2.b=1;}
					else if(curr=='y') {vis[u.x+move_x[i]][u.j+move_y[i]][u.r][u.b][1][u.g]=1;t2.y=1;}
					else {vis[u.x+move_x[i]][u.j+move_y[i]][u.r][u.b][u.y][1]=1;t2.y=1;}

					data temp;
					temp.x=u.x+move_x[i];
					temp.j=u.j+move_y[i];
					temp.r=t2.r;
					temp.b=t2.b;
					temp.y=t2.y;
					temp.g=t2.g;
					vis[temp.x][temp.j][temp.r][temp.b][temp.y][temp.g]=1;

					dist[u.x+move_x[i]][u.j+move_y[i]][temp.r][temp.b][temp.y][temp.g]=dist[u.x][u.j][u.r][u.b][u.y][u.g]+1;
					Q.push(temp);
				}else if(!vis[u.x+move_x[i]][u.j+move_y[i]][u.r][u.b][u.y][u.g]){
					char curr=grid[u.x+move_x[i]][u.j+move_y[i]];
					if(curr=='R'){if(!u.r) continue;}
					else if(curr=='B') {if(!u.b) continue;}
					else if(curr=='Y') {if(!u.y) continue;}
					else if(curr=='G') {if(!u.g) continue;}

					data temp;

					temp.x=u.x+move_x[i];
					temp.j=u.j+move_y[i];
					temp.r=u.r;
					temp.b=u.b;
					temp.y=u.y;
					temp.g=u.g;

					vis[temp.x][temp.j][temp.r][temp.b][temp.y][temp.g]=1;
					dist[u.x+move_x[i]][u.j+move_y[i]][u.r][u.b][u.y][u.g]=dist[u.x][u.j][u.r][u.b][u.y][u.g]+1;
					Q.push(temp);

				}
				//printf("Here \n");
			}
		}
	}
	return -1;
}

int main(){

	scanf("%d %d",&r,&c);
	int i,j,ans;
	bool fnd;

	for(i=0;i<r;i++) scanf("%s",grid[i]);

	memset(vis,0,sizeof(vis));
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(grid[i][j]=='*') {
			 ans=bfs(i,j);
			 fnd=1;
			 break;
			}
		}
		if(fnd) break;
	}

	if(ans==-1) printf("The poor student is trapped!\n");
	else {
		printf("Escape possible in %d steps\n",ans);
	}

	return 0;
}