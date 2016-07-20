#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct path{
	int x;
	int y;
};

vector<int>edges[5000];
int visited[5000];
int N,M;
int restricted_x,rest_y;
vector<int>out;
int listed[5000];
vector <path> edge_list;


int BFS(){
	queue<int>Q;
	visited[1]=1;
	Q.push(1);

	while(!Q.empty()){
		int v=Q.front();
		for(int i=0;i<edges[v].size();i++){
			int u=edges[v][i];
			if(!visited[u]&&!(v==restricted_x&&u==rest_y)){
				visited[u]=1;
				Q.push(u);
			}
		}
		Q.pop();
	}
	return 0;
}

int main(){

	int i,j,k;
	scanf("%d %d",&N,&M);

	for(i=0;i<=N;i++) edges[i].clear();
	edge_list.clear();

	for(i=0;i<M;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		edges[x].push_back(y);
		path u;
		u.x=x;
		u.y=y;
		edge_list.push_back(u);

	}
	memset(listed,0,sizeof(listed));
	for(j=0;j<edge_list.size();j++){
		restricted_x=edge_list[j].x;
		rest_y=edge_list[j].y;
		memset(visited,0,sizeof(visited));
		BFS();
		for(k=2;k<=N;k++){
			if(!visited[k]&&!listed[k]) {out.push_back(k);listed[k]=1;}
		}

	}
	printf("%d\n",out.size());
	int count=out.size();
	sort(out.begin(),out.end());
	for(i=0;i<count;i++) printf("%d\n",out[i]);
	return 0;
}
