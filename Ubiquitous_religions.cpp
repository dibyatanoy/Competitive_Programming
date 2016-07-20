#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int>relations[50100];
int taken[50100],max_rel;

int BFS(int src){
	queue<int>Q;
	Q.push(src);
	taken[src]=1;

	while(!Q.empty()){
		int u=Q.front();
		for(int i=0;i<relations[u].size();i++){
			int v=relations[u][i];
			if(!taken[v]){
				taken[v]=1;
				Q.push(v);
			}
		}
		Q.pop();
	}
	
	return 0;
}

int main(){

	int testcases=0;
	int people,man1,man2;
	long int m;

	while(scanf("%d%ld",&people,&m)==2&&people!=0){
		int i;
		for(i=0;i<50100;i++) relations[i].clear();
		memset(taken,0,sizeof(taken));
		max_rel=0;
		
		for(i=0;i<m;i++){
			scanf("%d%d",&man1,&man2);
			relations[man1].push_back(man2);
			relations[man2].push_back(man1);
		}
		for(i=1;i<=people;i++){
			if(!taken[i]){BFS(i);
			max_rel++;
			}
		}
		printf("Case %d: %d\n",++testcases,max_rel);
	}

	return 0;
}

/** AC!!! Supposed to be a DS problem, but i found it a BFS problem! **/