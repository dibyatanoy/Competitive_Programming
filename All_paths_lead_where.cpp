#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define MAX 28

vector<int>edges[MAX];
int taken[28],parent[28];
char city1[50],city2[50];

int printbfs(int city){

	if(parent[city]==-1) printf("%c",(char)(city+(int)'A'));

	else{
		printbfs(parent[city]);
		printf("%c",(char)(city+(int)'A'));
	}

	return 0;
}

void bfs(int src,int dest){
	queue<int>Q;
	int found=0;
	memset(taken,0,sizeof(taken));
	memset(parent,-1,sizeof(parent));
	taken[src]=1;
	
	Q.push(src);

	while(!Q.empty()){
		int u=Q.front();
		for(int j=0;j<edges[u].size();j++){
			int v=edges[u][j];
			if(!taken[v]){
				taken[v]=1;
				parent[v]=u;
				if(v==dest){found=1;break;}
				Q.push(v);
			}
		}
		Q.pop();
		if(found) break;
	}

	printbfs(dest);
	

}

int main(){

	int i,x,y,N,E,source=-1,Q;

	scanf("%d",&N);

	while(N--){
		scanf("%d%d",&E,&Q);

		memset(edges,0,sizeof(edges));

		for(i=0;i<E;i++){
			scanf("%s %s",city1,city2);
			x=(int)city1[0]-'A';
			y=(int)city2[0]-'A';
			edges[x].push_back(y);
			edges[y].push_back(x);
			
		}

		for(i=0;i<Q;i++){
			scanf("%s%s",city1,city2);
			x=(int)city1[0]-'A';
			y=(int)city2[0]-'A';
			bfs(x,y);
		}

		
		printf("\n");
	}

	

	return 0;
}