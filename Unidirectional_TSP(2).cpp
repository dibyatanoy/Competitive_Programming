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

long int grid[12][103],dp[12][103];
int row,col;
pos paths[12][103];

int find_linear_min(){
	int min=999999999,minrow;
	for(int i=0;i<row;i++){
		if(grid[i][0]<min) {min=grid[i][0];minrow=i;}
	}
	printf("%d\n%d\n",minrow+1,min);
	return 0;
}

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
	if(col==1) return find_linear_min();
	long int min=999999999;
	int minx,miny;
	for(i=0;i<row;i++){
		dp[i][col-1]=grid[i][col-1];
	}
	for(i=col-2;i>=0;i--){

		for(j=0;j<row;j++){
			long int gain1,gain2,gain3;
			if(row>2){
				gain1=dp[mod(j-1,row)][i+1];
				gain2=dp[j][i+1];
				gain3=dp[mod(j+1,row)][i+1];
			}else{
				gain1=dp[j][i+1];
				gain2=dp[mod(j+1,row)][i+1];
				gain3=30000;
			}
			if(row>2){
				if((gain1==gain2)&&(gain1<=gain3)&&((j+1)!=row)){
					if(j-1<0){
						dp[j][i]=gain2+grid[j][i];
						paths[j][i].r=j;
						paths[j][i].c=i+1;
					}else{
						dp[j][i]=gain1+grid[j][i];
						paths[j][i].r=mod(j-1,row);
						paths[j][i].c=i+1;
					} 
				}else if(gain1==gain3&&gain1<=gain2){
					if((j+1)==row){
						dp[j][i]=gain3+grid[j][i];
						paths[j][i].r=mod(j+1,row);
						paths[j][i].c=i+1;
					}
					else if(j-1<0){
						dp[j][i]=gain3+grid[j][i];
						paths[j][i].r=mod(j+1,row);
						paths[j][i].c=i+1;
					}else{
						dp[j][i]=gain1+grid[j][i];
						paths[j][i].r=mod(j-1,row);
						paths[j][i].c=i+1;
					}
				}else if(gain2==gain3&&j+1==row&&gain1>=gain2){
						dp[j][i]=gain3+grid[j][i];
						paths[j][i].r=mod(j+1,row);
						paths[j][i].c=i+1;
				}
				else if(gain1<=gain2&&gain1<=gain3){
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
				if(gain1<gain2){
					dp[j][i]=gain1+grid[j][i];
					paths[j][i].r=j;
					paths[j][i].c=i+1;
				}else if(gain1==gain2){
					if(j+1==row){
						dp[j][i]=gain2+grid[j][i];
						paths[j][i].r=mod(j+1,row);
						paths[j][i].c=i+1;
					}else {
						dp[j][i]=gain1+grid[j][i];
						paths[j][i].r=j;
						paths[j][i].c=i+1;
					}
				}else{
					dp[j][i]=gain2+grid[j][i];
					paths[j][i].r=mod(j+1,row);
					paths[j][i].c=i+1;
				}
			}
			if(i==0&&dp[j][i]<min){min=dp[j][i];minx=j;miny=i;}
		}

	}
	prt_path(minx,miny);
	printf("\n%ld\n",min);

	return 0;
}

int main(){

	int i,j;

	while(scanf("%d%d",&row,&col)==2){
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				scanf("%ld",&grid[i][j]);
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

/** AC!!!!!!!!!!!! Very,very,very painful problem !!!  **/