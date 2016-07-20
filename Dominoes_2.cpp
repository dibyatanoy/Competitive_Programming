#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define MAX 100001

vector<int>edges[MAX];
int taken[MAX];


long int max(long int a,long int b){
	if(a>b) return a;
	return b;
}

long int bfs(int src){
	queue<int>Q;
	Q.push(src);
	taken[src]=1;
	int falls=1;
	

	while(!Q.empty()){
		int u=Q.front();
		for(int j=0;j<edges[u].size();j++){
			int v=edges[u][j];
			if(!taken[v]){
				taken[v]=1;
				falls++;
				
				Q.push(v);
			}
		}
		Q.pop();
	}

	return(falls);

}

int main(){
	int testcase,i,j,x,y,source,N,M,L;
	

	scanf("%d",&testcase);
	
	for(i=1;i<=testcase;i++){
		scanf("%d%d%d",&N,&M,&L);
		
		
		memset(edges,0,sizeof(edges));
		for(j=0;j<M;j++){
			scanf("%d%d",&x,&y);
			edges[x].push_back(y);
			//edges[y].push_back(x);

		}
		memset(taken,0,sizeof(taken));
		int count=0;
		for(j=0;j<L;j++){
			scanf("%d",&source);
			
		
				if(!taken[source]){
					count+=bfs(source);
				}
			
		}
		printf("%d\n",count);


	}

	return 0;

}