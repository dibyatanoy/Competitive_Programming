#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#define MAXX 100002
#define pb push_back
#define INF 1e7

using namespace std;

vector <int> edges[MAXX];
int next[MAXX],dfs_ctr=0;
int depth[MAXX],comp[MAXX];
int n,max_e=1,max_v;
bool stat[MAXX],vis[MAXX];

int maxim(int a,int b){
	return (a>b)? a:b;
}

int dfs(int v){
	comp[v]=dfs_ctr;
	vis[v]=1;
	if(stat[v]==1){
		depth[v]=1;
		vis[v]=1;
		return 1;
	}
	if(edges[v].size()==0) {depth[v]=-INF;return -INF;}

	int u,i;
	u=edges[v][0];
	
	if(edges[u].size()>1){
		depth[v]=-INF;
		return -INF;
	}
	if(!vis[u]){
		int temp=dfs(u);
		depth[v]=maxim(-INF,temp+1);
		if(temp>0) next[v]=u;
		return depth[v];
	}else if(comp[u]!=comp[v]){
		depth[v]=depth[u]+1;
		if(depth[u]>0) next[v]=u;
		return depth[v];
	}

}


int main(){

	scanf("%d",&n);
	int i,j;

	for(i=1;i<=n;i++){
		scanf("%d",&stat[i]);
	}

	for(i=1;i<=n;i++){
		int v;
		scanf("%d",&v);
		edges[v].pb(i);
	}
	memset(vis,0,sizeof(vis));
	memset(next,-1,sizeof(next));

	for(i=1;i<=n;i++){
		if(!vis[i]&&edges[i].size()<2) {
			dfs_ctr++;
			int curr=dfs(i);
			if(curr>=max_e) {max_e=curr;max_v=i;}
		}
	}

	printf("%d\n",max_e);
	printf("%d",max_v);
	int n=next[max_v];

	while(n!=-1){
		printf(" %d",n);
		n=next[n];
	}
	printf("\n");

	return 0;
}