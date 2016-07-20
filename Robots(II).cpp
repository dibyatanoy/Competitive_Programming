#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define RIGHT 1
#define DOWN 2


using namespace std;

int dp1[102][102],dp2[102][102],dir[102][102],row,col,ways_cnt=1;
bool visited1[102][102],grid[102][102],visited2[102][102];

int call1(int r,int c){
	if(r>=row||c>=col) return 0;
	if(visited1[r][c]) return dp1[r][c];

	int gain1=0,gain2=0;
	if(grid[r][c]){
		gain1=gain2=1;
	}
	gain1+=call1(r+1,c);
	gain2+=call1(r,c+1);
	if(gain1<gain2){
		dp1[r][c]=gain2;
		dir[r][c]=RIGHT;
	}else{
		dp1[r][c]=gain1;
		dir[r][c]=DOWN;
	}
	visited1[r][c]=true;
	return dp1[r][c];
}

void traverse(int r,int c){
	visited2[r][c]=true;
	if(r>=row||c>=col) return;
	if(dir[r][c]==RIGHT){
		traverse(r,c+1);
	}else if(dir[r][c]==DOWN){
		traverse(r+1,c);
	}
	
	return;
}

void call2(int r,int c,bool fnd){

	if(r>=row||c>=col){
		if(fnd==true) {ways_cnt+=1;}
		return;
	}

	if(grid[r][c]&&(!visited2[r][c])){fnd=1;printf("New route at (%d %d)\n",r,c);}

	visited2[r][c]=true;
	
	if(dp1[r+1][c]>dp1[r][c+1]){
		call2(r+1,c,fnd);
	}else if(dp1[r+1][c]<dp1[r][c+1]){
		call2(r,c+1,fnd);
	}else{
		call2(r+1,c,fnd);
		call2(r,c+1,0);
	}

	return;

}

/*int call2(int r,int c){
	if(r>=row-1||c>=col-1) return 1;
	/*if(r>=row){
		visited2[r][c]=1;
		return dp2[r][c]=call2(r,c+1);
	}
	if(c>=col){
		visited2[r][c]=1;
		return dp2[r][c]=call2(r+1,c);
	}*/
	//if(visited2[r][c]) return dp2[r][c];

	//int ways1,ways2;
	/*if(call1(r+1,c)>call1(r,c+1)){
		dp2[r][c]=call2(r+1,c);
	}else if(call1(r+1,c)<call1(r,c+1)){
		dp2[r][c]=call2(r,c+1);
	}else dp2[r][c]=call2(r+1,c)+call2(r,c+1);

	visited2[r][c]=true;
	return dp2[r][c];
}*/

int main(){

	while(scanf("%d %d",&row,&col)&&row!=-1&&col!=-1){
		ways_cnt=1;

		memset(grid,false,sizeof(grid));
		memset(dp1,0,sizeof(dp1));
		memset(visited1,0,sizeof(visited1));
		memset(visited2,0,sizeof(visited2));
		int curr_r,curr_c;
		while(scanf("%d %d",&curr_r,&curr_c)&&curr_r!=0&&curr_c!=0){
			grid[curr_r-1][curr_c-1]=true;
		}
		call1(0,0);
		traverse(0,0);

		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++) printf("%d ",dir[i][j]);

			printf("\n");
		}
		printf("\n");

		for( i=0;i<row;i++){
			for(int j=0;j<col;j++) printf("%d ",dp1[i][j]);

			printf("\n");
		}
		printf("\n");
		call2(0,0,false);
		printf("%d %d\n",dp1[0][0],ways_cnt);



	}

	return 0;
}