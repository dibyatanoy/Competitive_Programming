#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int edges_mat[1001][1001];
vector <int> edges[1001];
int dist[1001],V,E;

int relax(int u,int v){

	if(dist[v]>dist[u]+edges_mat[u][v]) dist[v]=dist[u]+edges_mat[u][v];

	return 0;
}

bool Bell_Ford(){
	int i,u,v;
	for(i=0;i<V-1;i++){
		for(u=0;u<V;u++){
			for(v=0;v<edges[u].size();v++){
				int x=edges[u][v];
				relax(u,x);
			}
		}
	}
	for(u=0;u<V;u++){
		for(v=0;v<edges[u].size();v++){
			int y=edges[u][v];
				if(dist[y]>dist[u]+edges_mat[u][y]) return 1;
		}
	}
	return 0;
}

int main(){

	int i,c,x,y;
	scanf("%d",&c);
	while(c--){

		scanf("%d%d",&V,&E);
		for(i=0;i<1000;i++){
			edges[i].clear();
		}
		for(i=0;i<E;i++){
			scanf("%d%d",&x,&y);
			edges[x].push_back(y);
			scanf("%d",&edges_mat[x][y]);
		}

		dist[0]=0;
		for(i=1;i<1001;i++) dist[i]=100000;
		bool NEGATIVE=Bell_Ford();
		if(NEGATIVE) printf("possible\n");
		else printf("not possible\n");
	}

	return 0;
}

/** AC!!! **/