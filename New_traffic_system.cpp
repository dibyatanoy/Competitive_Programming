#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#define MAXX 10002
#define INF 1e9

using namespace std;

struct data{
	int v,wt,used;

	bool operator <(const data &p)const{
		return wt>p.wt; 
	}
};

int n,m,k,d;
vector <int> edges[MAXX],cost[MAXX],extra[MAXX],e_cost[MAXX];
int dist[MAXX][11];

int dijkstra(){
	priority_queue <data> Q;
	data temp;
	int j;
	temp.v=0;temp.wt=0;temp.used=0;
	for(int i=0;i<n;i++) {for(j=0;j<11;j++) dist[i][j]=INF;}
	dist[0][0]=0;
	Q.push(temp);

	//printf("Reached!");

	while(!Q.empty()){
		data u=Q.top();Q.pop();
		if(u.v==n-1){
			int min=INF;
			for(j=0;j<=d;j++){
				if(dist[u.v][j]<min) min=dist[u.v][j];
			}
			return min;
		}
		
		for(j=0;j<edges[u.v].size();j++){
			int v=edges[u.v][j];
			if(dist[u.v][u.used]+cost[u.v][j]<dist[v][u.used]){
				dist[v][u.used]=dist[u.v][u.used]+cost[u.v][j];
				temp.v=v;
				temp.wt=dist[v][u.used];
				temp.used=u.used;
				Q.push(temp);
			}

		}
		for(j=0;j<extra[u.v].size();j++){
			int v=extra[u.v][j];
			if(u.used<d&&dist[u.v][u.used]+e_cost[u.v][j]<dist[v][u.used+1]){
				dist[v][u.used+1]=dist[u.v][u.used]+e_cost[u.v][j];
				temp.v=v;
				temp.wt=dist[v][u.used+1];
				temp.used=u.used+1;
				Q.push(temp);
			}

		}
	}
	return -1;

}

int main(){
	
	int i,T,j;
	scanf("%d",&T);
	
	for(i=1;i<=T;i++){
		for(j=0;j<n;j++){
			edges[j].clear();
			extra[j].clear();
			cost[j].clear();
			e_cost[j].clear();
		}
		scanf("%d %d %d %d",&n,&m,&k,&d);

		for(j=0;j<m;j++){
			int t_u,t_v,w;
			scanf("%d %d %d",&t_u,&t_v,&w);
			edges[t_u].push_back(t_v);
			cost[t_u].push_back(w);
		}
		for(j=0;j<k;j++){
			int t_u,t_v,w;
			scanf("%d %d %d",&t_u,&t_v,&w);
			extra[t_u].push_back(t_v);
			e_cost[t_u].push_back(w);
		}
		int ans=dijkstra();
		if(ans==-1) printf("Case %d: Impossible\n",i);
		else printf("Case %d: %d\n",i,ans);
	}

	return 0;
}

/** AC!!! **/
