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
#define MAXX 10005
#define all(v) v.begin(),v.end()

using namespace std;
vector <int> edges[MAXX];
int dur[MAXX],N,x[MAXX];
bool vis[MAXX];

int topsort(int u){

	vis[u]=1;
	int ret=0,i;

	//if(u==1) printf("!\n");

	for( i=0;i<edges[u].size();i++){
		if(!vis[edges[u][i]]){
			//printf("Going %d\n",edges[u][i]);
			int temp=topsort(edges[u][i]);
			ret=maxim(ret,temp);
			//printf("back\n");
		}else ret=maxim(ret,x[edges[u][i]]);
	}
	//if(u==1) printf("!\n");
	
	//printf("%d %d\n",u,ret+dur[u]);
	
	//if(u==1) printf("!\n");
	//printf("!\n");
	x[u]=ret+dur[u];
	return (ret+dur[u]);
}

int main(){

	int i,j;
	for(i=0;i<MAXX;i++) edges[i].clear();
	memset(vis,0,sizeof(vis));

	scanf("%d",&N);

	for(i=1;i<=N;i++){
		scanf("%d",&dur[i]);
		int x,j;
		scanf("%d",&x);

		for(j=1;j<=x;j++){
			int v;
			scanf("%d",&v);
			edges[i].pb(v);
		}
	}
	/*for(i=1;i<=N;i++){
		for(j=0;j<edges[i].size();j++) printf("%d ",edges[i][j]);
		printf("\n");
	}*/

	
	int ans=0;
	for(i=N;i>=1;i--){
		//order.clear();
		if(!vis[i]){
			ans=maxim(ans,topsort(i));
			//printf("%d %d\n",i,ans);
		}
	}

	printf("%d\n",ans);

	return 0;
}