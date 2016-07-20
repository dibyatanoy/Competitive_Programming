#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MX 25000
#define INF 1e7
 
using namespace std;

typedef struct data{
	int idx;
	int wt;
};

bool taken[500];
int N,K;

vector <data> edges[500];
int cnt=0;
int dist[500];
int par[500];
int color[500];

void DFS_visit(int src){
	int i,j;
	for(i=0;i<edges[src].size();i++){
		data v=edges[src][i];
		if(dist[src]+v.wt<=K){

			if(!taken[v.idx]&&!taken[src]&&v.idx!=par[src]){cnt++;printf("%d to %d\n",src,v.idx);}
			if(v.idx!=par[src]) par[v.idx]=src;
			dist[v.idx]=dist[src]+v.wt;
			color[v.idx]=1;
			DFS_visit(v.idx);
		}
	}
}

void DFS(){
	int i,j;
	for(i=1;i<=N;i++){
		memset(dist,0,sizeof(dist));
		memset(par,0,sizeof(par));
		dist[i]=0;
		DFS_visit(i);
		taken[i]=1;
	}
}

int main(){
	scanf("%d %d",&N,&K);

	int i,j;
	for(i=0;i<N-1;i++){
		int u,v,wt;
		data x;
		scanf("%d %d %d",&u,&v,&wt);
		x.idx=v;
		x.wt=wt;
		edges[u].push_back(x);
		x.idx=u;
		x.wt=wt;
		edges[v].push_back(x);
	}
	memset(taken,0,sizeof(taken));

	DFS();
	printf("%d\n",cnt);

	return 0;
}

 
