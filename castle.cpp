/*
ID: dibyapo2
TASK: castle
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define MAXX 51

using namespace std;


struct data{
	bool walls[4]; //0-west,1-north,2-east,3-south
};

int M,N,max_brk,brk_r,brk_c,brk_dir;
int direc[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
string directions="WNES";

data grid[MAXX][MAXX];
int r_grid[MAXX][MAXX];
bool visited[MAXX][MAXX];
int room_no[MAXX*MAXX];

void generate(int r,int c,int num){
	int i,cnt=0;
	string digits="";
	for(i=num;i!=0;i/=2){
		digits+='0'+(i%2);
	}
	memset(grid[r][c].walls,0,sizeof(grid[r][c].walls));
	for(i=0;i<digits.length();i++){
		grid[r][c].walls[i]=(bool)(digits[i]-'0');
	}
	/*printf(" ");
	cout << digits << " ";
	for(i=0;i<4;i++) printf("%d",grid[r][c].walls[i] );
	printf(" ");*/

	return;

}

int dfs(int r,int c,int room){
	int cnt=1;
	visited[r][c]=1;
	r_grid[r][c]=room;

	if(grid[r][c].walls[0]==0&&c-1>=0&&!visited[r][c-1]) cnt+=dfs(r,c-1,room);
	if(grid[r][c].walls[1]==0&&r-1>=0&&!visited[r-1][c]) cnt+=dfs(r-1,c,room);
	if(grid[r][c].walls[2]==0&&c+1<M&&!visited[r][c+1]) cnt+=dfs(r,c+1,room);
	if(grid[r][c].walls[3]==0&&r+1<N&&!visited[r+1][c]) cnt+=dfs(r+1,c,room);

	return cnt;

}

int breakwall(int r,int c,int dir){
	if(r+direc[dir][0]>=0&&r+direc[dir][0]<N&&c+direc[dir][1]>=0&&c+direc[dir][1]<M){
		if(r_grid[r][c]!=r_grid[r+direc[dir][0]][c+direc[dir][1]]) return room_no[r_grid[r][c]]+room_no[r_grid[r+direc[dir][0]][c+direc[dir][1]]];
	}
	return 0;
}

int main(){

	int i,j,cnt,maxrooms=0,room=0;

	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);

	scanf("%d %d",&M,&N);

	for(i=0;i<N;i++){
		//printf("Reached! i=%d ",i);
		for(j=0;j<M;j++){
			int temp;
			scanf("%d",&temp);
			generate(i,j,temp);
		}
	}
	memset(visited,0,sizeof visited);
	//printf("Here ! ");

	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(!visited[i][j]) {room=room+1;cnt=dfs(i,j,room);
			room_no[room]=cnt;
			if(maxrooms<cnt) maxrooms=cnt;
			}
		}
	}
	
	for(i=0;i<M;i++){
		for(j=N-1;j>=0;j--){
			for(int k=0;k<4;k++){
				int temp_brk;
				if(grid[j][i].walls[k]==1) temp_brk=breakwall(j,i,k);
				if(temp_brk>max_brk){
					max_brk=temp_brk;
					brk_r=j;
					brk_c=i;
					brk_dir=k;
				}
			}
		}
	}
	printf("%d\n",room);
	printf("%d\n",maxrooms);
	printf("%d\n",max_brk);
	printf("%d %d %c\n",brk_r+1,brk_c+1,directions[brk_dir]);
	//for(i=1;i<=room;i++) printf("%d ",room_no[i]);

	return 0;
}

/** AC!!! **/