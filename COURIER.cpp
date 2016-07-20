#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#define MAXX 102
#define INF 1e8

using namespace std;

struct data{
	int u,v;
};

int edges[MAXX][MAXX],dp[MAXX][1<<13];
bool vis[MAXX][1<<13];
int N,M,B,Z,n_tasks=0;
data tasks[13];

int minim(int a,int b){
	return (a<b)? a:b;
}

void floyd(){
	int i,j,k;
	for(k=1;k<=N;k++){
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				if(edges[i][k]+edges[k][j]<edges[i][j]) edges[i][j]=edges[i][k]+edges[k][j];
			}
		}
	}
	return;
}

int call(int curr,int mask){
	if(mask==(1<<n_tasks)-1) return edges[curr][B];
	if(vis[curr][mask]) return dp[curr][mask];

	int cost=100000,i;

	for(i=0;i<n_tasks;i++){
		if(((mask&(1<<i))==0)&&edges[curr][tasks[i].u]!=INF){
			int temp;
			temp=mask|(1<<i);
			cost=minim(call(tasks[i].v,temp)+edges[curr][tasks[i].u]+edges[tasks[i].u][tasks[i].v],cost);
			//printf("cost=%d\n",cost);
		}
	}
	vis[curr][mask]=1;
	return dp[curr][mask]=cost;
}

int main(){

	int testcases,i,j,k;

	scanf("%d",&testcases);

	for(k=1;k<=testcases;k++){
		n_tasks=0;
		
		scanf("%d %d %d",&N,&M,&B);
		for(i=0;i<MAXX;i++){
			for(j=0;j<MAXX;j++){ 
				if(i!=j) edges[i][j]=INF;
				else edges[i][j]=0;
			}
		}
		memset(vis,0,sizeof vis);
		for(i=0;i<M;i++){
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			edges[u][v]=w;
			edges[v][u]=w;
		}
		scanf("%d",&Z);
		for(i=0,j=0;i<Z;i++){
			int b;
			scanf("%d %d %d",&tasks[j].u,&tasks[j].v,&b);
			for(j=j+1;j<n_tasks+b;j++){tasks[j].u=tasks[j-1].u;tasks[j].v=tasks[j-1].v;}
			n_tasks+=b;
		}
		floyd();
		/*for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				printf("%d ",edges[i][j]);
			}
			printf("\n");
		}*/
		//for(i=0;i<n_tasks;i++) printf("%d %d\n",tasks[i].u,tasks[i].v);
		int ans=call(B,0);

		printf("%d\n",ans);
	}

	return 0;
}

/** AC!!! **/