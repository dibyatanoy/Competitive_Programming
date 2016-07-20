#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <stdlib.h>

using namespace std;

vector<int>edges[10000];
int row,col,reachable;

void bfs(int src,int i){

	queue<int>Q;
	int taken[10000];
	int count=0;
	memset(taken,0,sizeof(taken));
	Q.push(src);
	taken[src]=1;

	while(!Q.empty()){
		int u=Q.front();
		for(int j=0;j<edges[u].size();j++){
			int v=edges[u][j];
			if(!taken[v]){
				taken[v]=1;
				count++;
				Q.push(v);
			}
		}
		Q.pop();
	}

	printf("Case %d: %d\n",i,count+1);
}



int main(){

	int testcase,i,j,k,source;
	char line[21][21];

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%d%d",&col,&row);

		memset(edges,0,sizeof(edges));

		for(j=0;j<row;j++){
			scanf("%s",line[j]);
			for(k=0;k<col;k++){
				if(line[j][k]=='.'||line[j][k]=='@'){
					/*if(line[j-1][k-1]=='.'||line[j-1][k-1]=='@'){
						edges[(col-1)*(j-1)+k].push_back((col-1)*(j-2)+k-1);
						edges[(col-1)*(j-2)+k-1].push_back((col-1)*(j-1)+k);
					}*/
					if(line[j][k-1]=='.'||line[j][k-1]=='@'){
						edges[(col)*j+k].push_back((col)*j+k-1);
						edges[(col)*j+k-1].push_back((col)*j+k);
					}
					if(line[j-1][k]=='.'||line[j-1][k]=='@'){
						edges[(col)*j+k].push_back((col)*(j-1)+k);
						edges[(col)*(j-1)+k].push_back((col)*j+k);
					}
					if(line[j][k]=='@') source=(col)*j+k;
				}
			}
		}
		/*printf("Finished input ");*/

		bfs(source,i);
	}

	return 0;
}

/** AC!!! **/