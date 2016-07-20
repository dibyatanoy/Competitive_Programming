#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define MAXX 60004
#define set(a,b) memset(a,b,sizeof(a))
#define pb push_back

using namespace std;
vector<int> edges[MAXX];
int genies[MAXX],N,q,st[MAXX],ed[MAXX]; 
int lvl[MAXX],head[MAXX],parent[MAXX],chainid[MAXX],chainpos[MAXX],cnext[MAXX];
int nchain,dfscnt=0;
int bit[MAXX];

void insert(int pos,int val){
	int i;
	for(i=pos;i<=MAXX;i+=(i & -i)){
		bit[i]+=val;	
	}
	return;
}

int query(int pos){
	int i,ret=0;

	for(i=pos;i>0;i-=(i & -i)){
		ret+=bit[i];
	}
	return ret;
}

int dfs(int u,int p,int d){
	int i,v,sz=edges[u].size(),max,id,tot,hd,k,tmp;
	lvl[u]=d,max=0,id=u,tot=1;
	st[u]=++dfscnt;

	for(i=0;i<sz;i++){
		v=edges[u][i];
		if(v!=p){
			parent[v]=u;
			tmp=dfs(v,u,d+1);
			if(tmp>max){
				max=tmp;
				id=v;
			}
			tot+=tmp;
		}
	}
	ed[u]=++dfscnt;

	if(tot==1) cnext[u]=-1;
	else cnext[u]=id;

	for(i=0;i<sz;i++){
		v=edges[u][i];
		if(v!=p && v!=id){
			for(hd=v,k=0;v!=-1;v=cnext[v],k++){
				head[v]=hd;
				chainpos[v]=k;
				chainid[v]=nchain;
			}
			nchain++;
		}
	}
	return tot;
}

void hld(int v){
	//st[v]=++dfscnt;
	set(head,0);set(parent,-1);set(chainid,0);set(cnext,0);
	set(st,0);set(ed,0);
	int hd,k;
	lvl[v]=0;
	nchain=0;

	dfs(v,0,0);
	//ed[v]=++dfscnt;

	for(hd=v,k=0;v!=-1;v=cnext[v],k++){
		head[v]=hd;
		chainpos[v]=k;
		chainid[v]=nchain;
	}
	nchain++;
}

int lca(int a,int b){
	//printf("%d %d\n", a,b);
	while(chainid[a]!=chainid[b]){
		//printf("%d %d %d %d\n",a,b,chainid[a],chainid[b]);
		if(lvl[head[a]]>lvl[head[b]]) a=parent[head[a]];
		else b=parent[head[b]];
	}
	return (lvl[a]<lvl[b])? a:b;
}

int main(){

	int i,j,kases;

	scanf("%d",&kases);

	for(i=1;i<=kases;i++){
		scanf("%d",&N);
		dfscnt=0;

		for(j=0;j<N;j++) edges[j].clear();
		set(genies,0);

		for(j=0;j<N;j++){
			scanf("%d",&genies[j]);
		}

		for(j=0;j<N-1;j++){
			int u,v;
			scanf("%d %d",&u,&v);
			edges[u].pb(v);edges[v].pb(u);
		}
		hld(0);
		memset(bit,0,sizeof(bit));

		for(j=0;j<N;j++){
			insert(st[j],genies[j]);
			insert(ed[j],-genies[j]);
		}

		int q;
		scanf("%d",&q);
		printf("Case %d:\n",i);


		for(j=0;j<q;j++){
			int op,a,b;
			scanf("%d %d %d",&op,&a,&b);
			if(op){
				insert(st[a],b-genies[a]);
				insert(ed[a],-(b-genies[a]));
				genies[a]=b;
			}else{
				int ans,x;
				
				x=lca(a,b);
				
				if(x!=0) ans=query(st[a])+query(st[b])-query(st[x])-query(st[parent[x]]);
				else ans=query(st[a])+query(st[b])-query(st[x]);

				printf("%d\n",ans);
			}
		}
		

	}

	return 0;
}

/** AC!!! **/