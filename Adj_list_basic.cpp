#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000
using namespace std;

vector<int>edges[MAX];

void bfs(int n,int source){
	vector<int>V1,V2;
	V1.push_back(source);
	int taken[100]={0};
	taken[source]=1;

	printf("Level 0::%d\n",source);

	for(int loop=1;loop<n;loop++){
		printf("Level %d::",loop);
		for(int i=0;i<V1.size();i++){
			int u=V1[i];
			for(int j=0;j<edges[u].size();j++){
				int v=edges[u][j];
				if(!taken[v]){
					printf("%d ",v);
					V2.push_back(v);
					taken[v]=1;
				}
			}
		}

		if(V2.empty()){puts("EMPTY");break;}
		else{
			puts("");
			V1.clear();
			V1=V2;
			V2.clear();
		}
	}
}

void bfs2(int n,int src){
	queue<int>Q;

	Q.push(src);
	int taken[100]={0},distance[100];
	taken[src]=1;
	distance[src]=0;

	while(!Q.empty()){
		int u=Q.front();
		for(int i=0;i<edges[u].size();i++){
			int v=edges[u][i];
			if(!taken[v]){
				taken[v]=1;
				distance[v]=distance[u]+1;
				Q.push(v);
			}
		}
		Q.pop();
	}
	for(int i=1;i<=n;i++){
		printf("%d to %d distance is %d\n",src,i,distance[i]);
	}
}

int main(){

	int N,E,i,source;

	scanf("%d%d",&N,&E);

	for(i=1;i<=E;i++){
		int x,y;

		scanf("%d%d",&x,&y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

/*	vsize=edges[1].size();
	for(i=0;i<vsize;i++){
		printf("%d ",edges[1][i]);
	}*/
	scanf("%d",&source);
	bfs(N,source);
	printf("\n");
	bfs2(N,source);

	return 0;


}
