#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N,M;
int dist[102],taken[102];
vector <int> edges[102];

void ptseq(){
	int x,y,started=0;
	int move=0;
	for(x=N;x>0;){
		for(y=1;y<=N;y++){
			if(dist[y]==move){
				if(!started){
					started=1;
					printf("%d",y);
					dist[y]=-1;
					x--;
				}else{
				printf(" %d",y);
				dist[y]=-1;
				x--;}
			}
		}
		move++;
	}
	printf("\n");
}

int bfs(int src){
	queue <int> Q;
	Q.push(src);
	dist[src]=0;
	taken[src]=1;

	while(!Q.empty()){
		int u=Q.front();
		for(int i=0;i<edges[u].size();u++){
			int v=edges[u][i];
			if(!taken[v]){
				taken[v]=1;
				dist[v]=dist[u]+1;
				Q.push(v);
			}
		}
		Q.pop();
	}

	ptseq();
	return 0;

}


int main(){

	int x,y;

	while(scanf("%d%d",&N,&M)==2&&N!=0){
		for(int i=0;i<M;i++){
			scanf("%d%d",&x,&y);
			edges[x].push_back(y);
		}

		memset(dist,0,sizeof(dist));
		for(int k=1;k<=N;k++){
			if(!taken[k]&&edges[k].size()!=0){
				bfs(k);
			}
		}
	}

	return 0;
}