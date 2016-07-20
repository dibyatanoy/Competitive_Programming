#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define MAX 100001

vector<int>edges[MAX];
int team[MAX],taken[MAX];
long int team1,team2;

long int max(long int a,long int b){
	if(a>b) return a;
	return b;
}

long int bfs(int src,long int team_max){
	queue<int>Q;
	Q.push(src);
	team[src]=1;taken[src]=1;
	team1=1;team2=0;
	

	while(!Q.empty()){
		int u=Q.front();
		for(int j=0;j<edges[u].size();j++){
			int v=edges[u][j];
			if(!taken[v]){
				taken[v]=1;
				if(team[u]==1){team[v]=2;team2++;}
				else {team[v]=1;team1++;}
				Q.push(v);
			}
		}
		Q.pop();
	}

	return(team_max+max(team1,team2));

}

int main(){
	int testcase,i,j,x,y,source;
	long int min=0,max=0,team_max=0,N;

	scanf("%d",&testcase);
	
	for(i=1;i<=testcase;i++){
		scanf("%ld",&N);
		source=-1;
		team_max=0;max=0;min=0;
		memset(edges,0,sizeof(edges));
		for(j=0;j<N;j++){
			scanf("%d%d",&x,&y);
			edges[x].push_back(y);
			edges[y].push_back(x);
			if(x>max)max=x;
			if(x<min)min=x;
			if(y>max)max=y;
			if(y<min)min=y;


		}
		memset(team,0,sizeof(team));
		memset(taken,0,sizeof(taken));
		
		for(j=min;j<=max;j++){
			if(!taken[j] && edges[j].size()!=0){
				team_max=bfs(j,team_max);
			}
		}
		printf("Case %d: %ld\n",i,team_max);


	}

	return 0;

}

/* AC!!! My first graph theory problem.*/
