/*
UVa#10004
*/

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define MAX 201

vector<int>edges[MAX];
int taken[201];
int colour[201];

void bfs(int N,int src){
	queue<int>Q;
	int found=0;
	memset(colour,0,sizeof(colour));
	memset(taken,0,sizeof(taken));
	taken[src]=1;
	colour[src]=1;
	Q.push(src);

	while(!Q.empty()){
		int u=Q.front();
		for(int j=0;j<edges[u].size();j++){
			int v=edges[u][j];
			if(!taken[v]){
				taken[v]=1;
				if(colour[u]==1)
					colour[v]=2;
				else
					colour[v]=1;
				Q.push(v);
			}else{
				if(colour[u]==colour[v]){
					found=1;
					break;
				}
			}
			
		}
		Q.pop();
		if(found) break;
	}

	if(found) printf("NOT BICOLORABLE.\n");
	else printf("BICOLORABLE.\n");
	

}

int main(){

	int i,x,y,N,E,source=-1;

	scanf("%d",&N);

	while(N!=0){
		scanf("%d",&E);

		memset(edges,0,sizeof(edges));

		for(i=0;i<E;i++){
			scanf("%d%d",&x,&y);
			edges[x].push_back(y);
			edges[y].push_back(x);
			if(source<0) source=x;
		}

		bfs(N,source);
		scanf("%d",&N);
	}

	

	return 0;
}

/** AC!!! **/