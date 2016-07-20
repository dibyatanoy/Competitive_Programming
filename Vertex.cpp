#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define MAX 102

vector<int>edges[MAX];
int taken[102],parent[102],N,cnt;

int printbfs(){

	for(int k=1;k<=N;k++){
		if(!taken[k]) printf(" %d",k);
	}
	return 0;
}

void bfs(int src){
	queue<int>Q;
	int found=0;
	memset(taken,0,sizeof(taken));
	memset(parent,-1,sizeof(parent));
	
	Q.push(src);

	while(!Q.empty()){
		int u=Q.front();
		for(int j=0;j<edges[u].size();j++){
			int v=edges[u][j];
			if(!taken[v]){
				cnt--;
				taken[v]=1;
				parent[v]=u;
				Q.push(v);
			}
		}
		Q.pop();
		if(found) break;
	}

	

}

int main(){

	int i,x,y,E,source=-1,Q;

	//scanf("%d",&N);

	while(scanf("%d",&N)==1 && N!=0){
		memset(edges,0,sizeof(edges));

		while(scanf("%d",&E)==1 && E!=0){

			while(scanf("%d",&x)==1 && x!=0){
			
				edges[E].push_back(x);
			
			}
		}

		scanf("%d",&Q);

		for(i=0;i<Q;i++){
			scanf("%d",&y);
			cnt=N;
			bfs(y);
			printf("%d",cnt);
			printbfs();
			printf("\n");
		}

		
		//printf("\n");
	}

	

	return 0;
}

/** AC!!! **/