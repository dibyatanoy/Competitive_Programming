#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
#define pb push_back
#define MP make_pair
#define maxim(a,b) ((a)>(b)? (a):(b))
#define minim(a,b) ((a)<(b)? (a):(b))
#define INF 1e5
#define MAXX 50005
#define all(v) v.begin(),v.end()

using namespace std;

int N,a[MAXX],K,furthest[MAXX];
vector <int> edges[MAXX],c[MAXX],curr_l,l;
bool vis[MAXX],vis2[MAXX];

__int64 dfs(int v){
	vis[v]=1;
	int i;
	__int64 mx=0;

	for(i=0;i<edges[v].size();i++){
		int u=edges[v][i];
		if(!vis[u]){
			__int64 temp=dfs(u);
			if(temp+c[v][i]>mx){
				mx=temp+c[v][i];
				furthest[v]=u;
			}
		}
	}
	return mx+a[v];
}

__int64 dfs2(int v){
	vis2[v]=1;
	int i;
	__int64 mx=0;

	for(i=0;i<edges[v].size();i++){
		int u=edges[v][i];
		if(!vis2[u]){
			__int64 temp=dfs2(u);
			if(temp+c[v][i]>mx){
				mx=temp+c[v][i];
				furthest[v]=u;
			}
		}
	}
	return mx+a[v];

}

int main(){

	int i,j;
	scanf("%d %d",&N,&K);

	memset(vis,0,sizeof(vis));
	memset(vis2,0,sizeof(vis2));
	memset(furthest,-1,sizeof(furthest));

	for(i=1;i<=N;i++) scanf("%d",&a[i]);

	for(i=0;i<K;i++){
		int a,b,t;
		scanf("%d %d %d",&a,&b,&t);

		edges[a].pb(b);edges[b].pb(a);
		c[a].pb(t);c[b].pb(t);
	}
	__int64 mx=0;
	l.clear();

	for(i=1;i<=N;i++){
		if(!vis[i]){
			int curr;
			dfs(i);
			curr=i;
			while(furthest[curr]!=-1){
				curr=furthest[curr];
			}
			memset(furthest,-1,sizeof(furthest));

			//printf("%d\n",curr);
			__int64 now=dfs2(curr);
			//printf("%d\n",now);

			if(now>=mx){
				
				mx=now;
				l.clear();
				while(furthest[curr]!=-1){
					l.pb(curr);
					curr=furthest[curr];
				}
				l.pb(curr);
			}

		}
	}
	printf("%I64d\n",mx);
	printf("%d\n",l.size());
	printf("%d",l[0]);

	for(i=1;i<l.size();i++) printf(" %d",l[i]);
	printf("\n");

	

	return 0;
}