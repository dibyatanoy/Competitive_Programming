#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int st_x,st_y,end_x,end_y;
int times_t[9][9];
bool taken[9][9];

int bfs(){
	queue <int> Qx,Qy;
	Qx.push(st_x);
	Qy.push(st_y);
	times_t[st_x][st_y]=0;
	taken[st_x][st_y]=1;


	while(!Qx.empty()){
		int x=Qx.front();
		int y=Qy.front();
		if(x==end_x&&y==end_y){
			return times_t[x][y];
		}
		if(x-2>=0&&y-1>=0&&!taken[x-2][y-1]){
			taken[x-2][y-1]=1;
			Qx.push(x-2);
			Qy.push(y-1);
			times_t[x-2][y-1]=times_t[x][y]+1;
		}
		if(x-2>=0&&y+1<8&&!taken[x-2][y+1]){
			taken[x-2][y+1]=1;
			Qx.push(x-2);
			Qy.push(y+1);
			times_t[x-2][y+1]=times_t[x][y]+1;
		}
		if(x-1>=0&&y-2>=0&&!taken[x-1][y-2]){
			taken[x-1][y-2]=1;
			Qx.push(x-1);
			Qy.push(y-2);
			times_t[x-1][y-2]=times_t[x][y]+1;
		}
		if(x-1>=0&&y+2<col&&!taken[x-1][y+2]){
			taken[x-1][y+2]=1;
			Qx.push(x-1);
			Qy.push(y+2);
			times_t[x-1][y+2]=times_t[x][y]+1;
		}
		if(x+2<8&&y-1>=0&&!taken[x+2][y-1]){
			taken[x+2][y-1]=1;
			Qx.push(x+2);
			Qy.push(y-1);
			times_t[x+2][y-1]=times_t[x][y]+1;
		}
		if(x+2<8&&y+1<8&&!taken[x+2][y+1]){
			taken[x+2][y+1]=1;
			Qx.push(x+2);
			Qy.push(y+1);
			times_t[x+2][y+1]=times_t[x][y]+1;
		}
		if(x+1<8&&y-2>=0&&!taken[x+1][y-2]){
			taken[x+1][y-2]=1;
			Qx.push(x+1);
			Qy.push(y-2);
			times_t[x+1][y-2]=times_t[x][y]+1;
		}
		if(x+1<8&&y+2<8&&!taken[x+1][y+2]){
			taken[x+1][y+2]=1;
			Qx.push(x+1);
			Qy.push(y+2);
			times_t[x+1][y+2]=times_t[x][y]+1;
		}
		Qx.pop();
		Qy.pop();
	}

	return 0;
}

int main(){
	
	int r,no,b_rows;
	char c;

	scanf("%d%d",&row,&col);

	while(scanf("%c %d",&c,&r)==2){
		
		st_x=r;
		st_y=(int)(c-'a');

		scanf("%c %d",&c,&r);

		end_x=r;
		end_y=(int)(c-'a');
		memset(taken,0,sizeof(taken));
		int ans=bfs();
		printf("%d\n",ans);
	}


	return 0;
}

/** AC!!! **/