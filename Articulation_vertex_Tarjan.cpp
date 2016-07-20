#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#define pb push_back
#define sz sizeof
#define minim(a,b) (a<b)? a:b

using namespace std;

vector <int> edges[100];
bool vis[100],art_vtx[100];
int dfs_low[100],dfs_num[100],dfs_ctr=1;
int par[100],dfsRoot,rootc;

void dfs(int u){
	dfs_low[u]=dfs_num[u]=dfs_ctr++;

	int i;
	for(i=0;i<edges[u].size();i++){
		int v=edges[u][i];
		if(!vis[v]){
			par[v]=u;
			if(dfsRoot==u) rootc++;
			vis[v]=1;
			dfs(v);
			if(dfs_low[v]>=dfs_num[u]) {art_vtx[u]=1;}
			dfs_low[u]=minim(dfs_low[u],dfs_low[v]);
		}
		else if(v!=par[u]) dfs_low[u]=minim(dfs_low[u],dfs_num[v]);
	}
	return;
}

int main(){

	int V,E;
	scanf("%d %d",&V,&E);

	memset(vis,0,sz vis);
	memset(art_vtx,0,sz art_vtx);

	int i,j,k;
	for(i=0;i<100;i++) edges[i].clear();

	for(i=1;i<=E;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		edges[u].pb(v);
		edges[v].pb(u);
	}
	for(i=1;i<=V;i++){
		rootc=0;
		if(!vis[i]) {dfsRoot=i;dfs(i);}
		art_vtx[dfsRoot]=(rootc>1);
	}
	for(i=1;i<=V;i++){
		if(art_vtx[i]==1) printf("%d",i);
	}
	printf("\n");


	return 0;
}