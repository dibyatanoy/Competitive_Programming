#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
vector<int>edges[110],output;
int indegree[110],tasks,rem;
queue<int>Q;

int topsort(){
	
	for(int i=1;i<=tasks;i++){
		if(indegree[i]==0){
			Q.push(i);
			output.push_back(i);
		}
	}
	while(!Q.empty()){
		int u=Q.front();
		indegree[u]--;
		for(int k=0;k<edges[u].size();k++){
			int v=edges[u][k];
			indegree[v]--;
		}
		Q.pop();
		rem--;
	}
	if(rem) topsort();
	return 0;

}

int main(){

	int i,x,y,links;

	scanf("%d%d",&tasks,&links);
	while(tasks!=0){
	rem=tasks;
	memset(indegree,0,sizeof(indegree));
	for(i=0;i<110;i++){edges[i].clear();}
	output.clear();
	for(i=1;i<=links;i++){
		scanf("%d%d",&x,&y);
		edges[x].push_back(y);
		indegree[y]++;
	}

	topsort();
	printf("%d",output[0]);

	for(i=1;i<tasks;i++) printf(" %d",output[i]);
	printf("\n");
	scanf("%d%d",&tasks,&links);
	}

	return 0;
}

/** AC!!! **/