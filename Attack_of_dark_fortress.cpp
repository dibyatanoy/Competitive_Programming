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
#define INF 100000
#define MAXX 105
#define all(v) v.begin(),v.end()

struct data{
	int x,y;
};

using namespace std;

int m,n,move_x[]={0,0,1,-1,-1,-1,1,1},move_y[]={1,-1,0,0,-1,1,-1,1};

int c[MAXX*MAXX],g[MAXX*MAXX],f[MAXX*MAXX];

vector <int> edges[MAXX*MAXX],tele[28];
char grid[MAXX][MAXX];

void gelu(int src){
	queue <int>  Q;
	g[src]=0;
	int par[MAXX*MAXX];
	bool vis[MAXX*MAXX];

	memset(vis,0,sizeof(vis));
	par[src]=-1;

	Q.push(src);

	while(!Q.empty()){
		int u=Q.front();Q.pop();

		if(grid[u/n][u%n]>='A' && grid[u/n][u%n]<='Z'){
			int curr=grid[u/n][u%n]-'A';

			for(int j=0;j<tele[curr].size();j++){
				int x=tele[curr][j];

				if(!vis[x] && x!=u){
					g[x]=g[u];
					par[x]=u;
					vis[x]=1;
					Q.push(x);
				}
			}
		}

		for(int i=0;i<edges[u].size();i++){
			int v=edges[u][i];
			if(!vis[v] && v!=par[u]){
				g[v]=g[u]+1;
				par[v]=u;
				vis[v]=1;
				Q.push(v);
			}
		}
		
	}
	return;
}

void cath(int src){
	queue <int>  Q;
	c[src]=0;
	int par[MAXX*MAXX];
	bool vis[MAXX*MAXX];

	memset(vis,0,sizeof(vis));
	par[src]=-1;

	Q.push(src);

	while(!Q.empty()){
		int u=Q.front();Q.pop();
		if(grid[u/n][u%n]>='A' && grid[u/n][u%n]<='Z'){
			int curr=grid[u/n][u%n]-'A';

			for(int j=0;j<tele[curr].size();j++){
				int x=tele[curr][j];

				if(!vis[x] && x!=u){
					c[x]=c[u];
					par[x]=u;
					vis[x]=1;
					Q.push(x);
				}
			}
		}

		for(int i=0;i<edges[u].size();i++){
			int v=edges[u][i];
			if(!vis[v] && v!=par[u]){
				c[v]=c[u]+1;
				par[v]=u;
				vis[v]=1;
				Q.push(v);
			}
		}
		
	}
	return;
}

void fortress(int src){
	queue <int>  Q;
	f[src]=0;
	int par[MAXX*MAXX];
	bool vis[MAXX*MAXX];

	memset(vis,0,sizeof(vis));
	par[src]=-1;

	Q.push(src);

	while(!Q.empty()){
		int u=Q.front();Q.pop();

		if(grid[u/n][u%n]>='A' && grid[u/n][u%n]<='Z'){
			int curr=grid[u/n][u%n]-'A';

			for(int j=0;j<tele[curr].size();j++){
				int x=tele[curr][j];

				if(!vis[x] && x!=u){
					f[x]=f[u];
					par[x]=u;
					vis[x]=1;
					Q.push(x);
				}
			}
		}

		for(int i=0;i<edges[u].size();i++){
			int v=edges[u][i];
			if(!vis[v] && v!=par[u]){
				f[v]=f[u]+1;
				par[v]=u;
				vis[v]=1;
				Q.push(v);
			}
		}
		
	}
	return;
}


int main(){

	int i,j,s_c,s_g,s_f;
	scanf("%d %d",&m,&n);

	for(i=0;i<m;i++) scanf("%s",grid[i]);

	for(i=0;i<MAXX*MAXX;i++) g[i]=INF;
	for(i=0;i<MAXX*MAXX;i++) c[i]=INF;
	for(i=0;i<MAXX*MAXX;i++) f[i]=INF;


	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(grid[i][j]=='.' || grid[i][j]=='$'|| grid[i][j]=='!' ||grid[i][j]=='*' || (grid[i][j]>='A' && grid[i][j]<='Z')){
				for(int k=0;k<8;k++){
					int cx,cy;
					cx=move_x[k]+i;
					cy=move_y[k]+j;
					if(cx<m && cx>=0 && cy<n && cy>=0 && grid[cx][cy]!='#' && grid[cx][cy]!='*'){
						edges[n*(maxim(i,0))+j].pb(n*(maxim(cx,0))+cy);
					}
				}
			}
			if(grid[i][j]=='$') s_c=n*(maxim(i,0))+j;
			if(grid[i][j]=='!') s_g=n*(maxim(i,0))+j;
			if(grid[i][j]=='*') s_f=n*(maxim(i,0))+j;



		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(grid[i][j]>='A' && grid[i][j]<='Z'){
				tele[grid[i][j]-'A'].pb(n*(maxim(i,0))+j);
			}
		}
	}

	cath(s_c);gelu(s_g);fortress(s_f);
	int ans=INF;
	//printf("%d\n",g[1]);

	/*for(i=0;i<2;i++){
		for(j=0;j<tele[i].size();j++) printf("%d\n",tele[i][j]);
		printf("\n");
	}*/

	for(i=0;i<n*m;i++){
		if(maxim(g[i],c[i])+f[i]<ans) {/*printf("%d\n",i);*/ans=maxim(g[i],c[i])+f[i];}


	}

	if(ans>=INF) printf("Impossible\n");
	else printf("%d\n",ans);
	return 0;
}

/** AC!!! Wow, within contest time ! Beat bristy! :P **/