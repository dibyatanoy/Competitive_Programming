#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector <int> edges[1002];
int taken[1002],dist[1002];

int bfs(int src){

	queue<int>Q;
	Q.push(src);
	taken[src]=1;
	dist[src]=0;

	while(!Q.empty()){
		int u=Q.front();
		for(int i=0;i<edges[u].size();i++){
			int v=edges[u][i];
			if(!taken[v]){
				taken[v]=1;
				dist[v]=dist[u]+1;
				Q.push(v);
			}
		}
		Q.pop();
	}

	return 0;
}

int main(){

	int testcases,i,p,d;
	bool blank=false;

	scanf("%d",&testcases);

	while(testcases--){
		scanf("%d%d",&p,&d);
		memset(edges,0,sizeof(edges));
		memset(taken,0,sizeof(taken));
		
		for(i=0;i<d;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			edges[x].push_back(y);
			edges[y].push_back(x);
		}

		bfs(0);
		if(blank){printf("\n");blank=true;}

		for(i=1;i<p;i++) printf("%d\n",dist[i]);
		printf("\n");
	}

	return 0;
}