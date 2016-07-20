/*
PROB: snowplow
SOURCE: bd IOI 2013 team selection contest 3
Retake!! seems to be working!
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <stack>
#define MAXX 2002
#define INF 1e7

using namespace std;

vector <int> edges[MAXX];
int cost[MAXX],par[MAXX],next[MAXX];
int N,K;
int last=1;
int dp[MAXX][MAXX];
bool vis[MAXX][MAXX];

int minim(int a,int b){
	if(a<b) return a;
	return b;
}

void bfs(){
	queue <int> Q;
	Q.push(1);
	cost[1]=0;

	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=0;i<edges[u].size();i++){
			int v=edges[u][i];
			last=v;
			par[v]=u;
			if(i<edges[u].size()-1) next[v]=edges[u][i+1];
			Q.push(v);
		}
	}
	return;
}

int call(int v,int left){
	//printf("in with v=%d,left=%d\n",v,left);
	if(left==0) return 0;
	if(v==-1) return INF;
	//if(v==last&&left>1) return INF;
	if(vis[v][left]) return dp[v][left];

	int x=v;
	while(next[x]==-1&&x!=1){
		x=par[x];
	}

	bool done=0;
	int gain=INF;
	if(x!=1){
		gain=minim(call(next[x],left-1)+cost[v],call(next[x],left));
		done=1;
	}
	if(edges[v].size()!=0) {gain=minim(gain,call(edges[v][0],left-1)+cost[v]);done=1;}
	if(!done) gain=call(-1,left-1)+cost[v];
	
	vis[v][left]=1;
	return dp[v][left]=gain;
}

int main(){

	scanf("%d %d",&N,&K);
	int i,j;

	memset(cost,0,sizeof(cost));
	memset(par,-1,sizeof(par));
	memset(next,-1,sizeof(next));
	for(i=0;i<MAXX;i++) edges[i].clear();
	for(i=0;i<N-1;i++){
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		edges[u].push_back(v);
		cost[v]=c;
	}
	bfs();
	memset(vis,0,sizeof(vis));

	int ans=call(edges[1][0],K);

	//for(i=1;i<=N;i++) printf("%d ",next[i]);

	printf("%d\n",ans);
	return 0;
}