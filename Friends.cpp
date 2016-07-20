#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int>relations[30100];
int taken[30100],max_rel;

int max(int a,int b){
	if(a>b) return a;
	return b;
}

int BFS(int src){
	queue<int>Q;
	Q.push(src);
	taken[src]=1;
	int friends=1;

	while(!Q.empty()){
		int u=Q.front();
		for(int i=0;i<relations[u].size();i++){
			int v=relations[u][i];
			if(!taken[v]){
				taken[v]=1;
				Q.push(v);
				friends++;
			}
		}
		Q.pop();
	}
	
	return friends;
}

int main(){

	
	int testcases,people,man1,man2;
	long int m;

	scanf("%d",&testcases);

	while(testcases--){
		int i;
		scanf("%d%d",&people,&m);
		for(i=0;i<30100;i++) relations[i].clear();
		memset(taken,0,sizeof(taken));
		max_rel=0;
		
		for(i=0;i<m;i++){
			scanf("%d%d",&man1,&man2);
			relations[man1].push_back(man2);
			relations[man2].push_back(man1);
		}
		for(i=1;i<=people;i++){
			if(!taken[i]){
			max_rel=max(max_rel,BFS(i));
			}
		}
		printf("%d\n",max_rel);
	}

	return 0;
}

/** AC!!! Supposed to be a DS problem, but I found it a BFS problem! **/