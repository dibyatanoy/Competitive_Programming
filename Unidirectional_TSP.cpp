#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct pos{
	int r;
	int c;
};

int grid[12][103],dp[12][103],row,col;
pos paths[12][103];

int mod(int a,int b){
	if(a<0) return mod(a+b,b);
	//printf("Returning %d from mod() ",a%b);
	return a%b;
}

int prt_path(int i,int j){
	if(paths[i][j].r==-1) printf("%d",i+1);
	else{
		printf("%d ",i+1);
		prt_path(paths[i][j].r,paths[i][j].c);
	}
	return 0;
}

int TSP(){

	int i,j;
	int min=30000,minx,miny;
	for(i=0;i<row;i++){
		dp[i][col-1]=grid[i][col-1];
	}
	for(i=col-2;i>=0;i--){

		for(j=0;j<row;j++){
			int gain1,gain2,gain3;
			if(row>2){gain1=dp[mod(j-1,row)][i+1];
			gain2=dp[j][i+1];
			gain3=dp[mod(j+1,row)][i+1];}
			else{
				gain1=dp[j][i+1];
				gain2=dp[mod(j+1,row)][i+1];
				gain3=30000;
			}
			if(row>2){
				if(gain1<=gain2&&gain1<=gain3){
					dp[j][i]=gain1+grid[j][i];
					paths[j][i].r=mod(j-1,row);
					paths[j][i].c=i+1;
				}else if(gain2<=gain3){
					dp[j][i]=gain2+grid[j][i];
					paths[j][i].r=j;
					paths[j][i].c=i+1;
				}else{
					dp[j][i]=gain3+grid[j][i];
					paths[j][i].r=mod(j+1,row);
					paths[j][i].c=i+1;
				}
			}else{
				if(gain1<=gain2){
				dp[j][i]=gain1+grid[j][i];
				paths[j][i].r=j;
				paths[j][i].c=i+1;
			}else{
				dp[j][i]=gain2+grid[j][i];
				paths[j][i].r=mod(j+1,row);
				paths[j][i].c=i+1;
			}
			if(i==0&&dp[j][i]<min){min=dp[j][i];minx=j;miny=i;}
		}

	}
	prt_path(minx,miny);
	printf("\n%d\n",min);

	return 0;
}

int main(){

	int i,j;

	while(scanf("%d%d",&row,&col)==2){
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				scanf("%d",&grid[i][j]);
			}
		}
		for(i=0;i<12;i++){
			for(j=0;j<103;j++){
				paths[i][j].r=-1;
				paths[i][j].c=-1;
			}
		}

		TSP();
	}

	return 0;
}
