#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct data{
	int v,wt;

	bool operator <(const data&p)const{
		return wt>p.wt;				//Note: Operator overloaded
	}
};
vector <int> edges[1002],cost[1002];
int dist[1002];

int dijkstra(int src){
	priority_queue <data> Q;
	dist[src]=0;
	data u;
	u.v=src;u.wt=0;Q.push(u);

	while(!Q.empty()){
		data v=Q.top();Q.pop();

		int i;
		for(i=0;i<edges[v.v].size();i++){
			int u=edges[v.v][i];

			if(dist[u]>dist[v.v]+cost[v.v][i]){
				dist[u]=dist[v.v]+cost[v.v][i];
				data temp;
				temp.v=u;temp.wt=dist[u];Q.push(temp);
			}
		}
	}
	return 0;
}

/****************************************************************************************************************/
// MST

struct data2{
	int u,v,wt;
	bool operator <(const data&p)const{
		return wt<p.wt;
	}
};

int par[1002];
vector <data2> edges;

int find_p(int u){
	return (par[u]==u)? u:par[u]=find_p(par[u]);
}

int mst(){
	int i,cost=0,u,v;
	for(i=0;i<MAXX;i++) par[i]=i;

	sort(edges.begin(),edges.end());

	for(i=0;i<edges.size();i++){
		data2 curr=edges[i];
		u=find_p(curr.u);v=find_p(curr.v);		
		if(u!=v){
			cost+=curr.wt;
			par[u]=v;
		}
	}
	return cost;

}												//For second best mst, find mst, then empty par array;
												//select an edge to remove, then reconstruct par array 
												//using edges used in mst, except this one,then use the others
												// to fill in the gap. Take the least among all new msts.

/********************************************************************************************************/
// Bellman-ford SSSP
struct data{
	int u,int v,int wt;
};

vector <data> edge_list;
int V;	//Vertex no

int relax(int u,int v,int w){
	if(dist[u]+w<dist[v]) dist[v]=dist[u]+w;	// Uses edge list
}

int bellman_ford(int u){
	int i,j;

	for(i=0;i<V-1;i++){
		for(j=0;j<edge_list.size();j++){
			relax(edge_list[j].u,edge_list[j].v,edge_list[j].w);
		}
	}

	//Negative cycle finding
	for(i=0;i<edge_list.size();i++){
		int u=edge_list[i].u;
		int v=edge_list[i].v;
		int w=edge_list[i].w;

		if(dist[u]+w<dist[v]) return -1;
	}

	
}

/***************************************************************************************************/
//			Articulation vertex and bridge

vector <int> edges[100];
bool vis[100],art_vtx[100];
int dfs_low[100],dfs_num[100],dfs_ctr=1;
int par[100],dfsRoot,rootc;

void dfs(int u){
	dfs_low[u]=dfs_num[u]=dfs_ctr++;

	int i;
	for(i=0;i<edges[u].size();i++){
		int v=edges[u][i];
		if(!vis[v]){
			par[v]=u;
			if(dfsRoot==u) rootc++;
			vis[v]=1;
			dfs(v);
			if(dfs_low[v]>=dfs_num[u]) {art_vtx[u]=1;}	//articulation vertex
														//bridge condition: dfs_low[v]>dfs_num[u]
			dfs_low[u]=minim(dfs_low[u],dfs_low[v]);
		}
		else if(v!=par[u]) dfs_low[u]=minim(dfs_low[u],dfs_num[v]);
	}
	return;
}

/***************************************************************************************************/

// Finding diameter: Choose arbitrary root, run dfs to find furthest node, then run dfs again from this node

/***************************************************************************************************/

int order[MAXX];
bool vis[MAXX];

void topsort(int u){
	vis[u]=1;
	for(i=0;i<edges[u].size();i++){
		if(!vis[edges[u][i]]) topsort(edges[u][i]);
	}
	order.push_back(u);
}

reverse(order,order+n);	//list is in reverse order

/***************************************************************************************************/
// Floyd warshall APSP

for(k=0;k<v;k++){
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			if(dist[i][j]>dist[i][k]+dist[k][j]) dist[i][j]=dist[i][k]+dist[k][j]; 
		}
	}
}

/**************************************************************************************************/
//Heavy Light Decomposition.....

struct Segment {				
	int sum, max, pre, suf, lzy, val;
};

struct Chain {			// to use with segment tree, this is needed (Snippet from GSS7 SPOJ)
	int n, *a;
	Segment *T;
	Chain(int *aa, int cn) {
		a = new int[n = cn];
		T = new Segment[n << 2];
		memcpy(a, aa, sizeof(int) * n);
		init(1, 0, n-1);
	}
	inline void push(Segment &x, int i, int j, int val) {
		x.lzy = i!=j, x.val = val;
		x.sum = (j - i + 1) * val;
		x.max = x.suf = x.pre = max(0, x.sum);
	}
	inline void update(Segment &x, const Segment &lt, const Segment &rt) {
		x.sum = lt.sum + rt.sum;
		x.max = max(0, max(max(lt.max, rt.max), lt.suf + rt.pre));
		x.pre = max(0, max(lt.pre, lt.sum + rt.pre));
		x.suf = max(0, max(rt.suf, rt.sum + lt.suf));
	}
	void init(int x, int i, int j) {
		T[x].lzy = 0;
		if(i == j) {
			push(T[x], i, j, a[i]);
			return;
		}
		int mid = (i + j) >> 1, lt = x << 1, rt = lt | 1;
		init(lt, i, mid);
		init(rt, mid + 1, j);
		update(T[x], T[lt], T[rt]);
	}
	void upd(int x, int i, int j, int p, int q, int val) {
		if(i == p && j == q) {
			push(T[x], i, j, val);
			return;
		}
		int mid = (i + j) >> 1, lt = x << 1, rt = lt | 1;
		if(i < j && T[x].lzy) {
			T[x].lzy = 0;
			push(T[lt], i, mid, T[x].val);
			push(T[rt], mid + 1, j, T[x].val);
		}
		if(q <= mid) upd(lt, i, mid, p, q, val);
		else if(p > mid) upd(rt, mid + 1, j, p, q, val);
		else {
			upd(lt, i, mid, p, mid, val);
			upd(rt, mid + 1, j, mid + 1, q, val);
		}
		update(T[x], T[lt], T[rt]);
	}
	Segment ask(int x, int i, int j, int p, int q) {
		Segment ret, lres, rres;
		if(T[x].lzy) {
			push(ret, p, q, T[x].val);
			return ret;
		}
		if(i == p && j == q) return T[x];
		int mid = (i + j) >> 1, lt = x << 1, rt = lt | 1;
		if(q <= mid) return ask(lt, i, mid, p, q);
		else if(p > mid) return ask(rt, mid + 1, j, p, q);
		else {
			lres = ask(lt, i, mid, p, mid);
			rres = ask(rt, mid + 1, j, mid + 1, q);
			update(ret, lres, rres);
			return ret;
		}
	}
};

vector< int > G[MAX];
int cost[MAX], lvl[MAX], parent[MAX];
int head[MAX], cnext[MAX], chainid[MAX], chainpos[MAX];

int nchain;
vector< Chain * > chains;

int temp[MAX];

void update(int ca, int u, int w) {
	int chid, chpos;
	Chain *ch;
	while(lvl[u] > lvl[ca]) {
		chid = chainid[u]; chpos = chainpos[u]; ch = chains[chid];
		if(lvl[head[u]] > lvl[ca]) ch->upd(1, 0, ch->n - 1, chainpos[head[u]], chainpos[u], w);
		else ch->upd(1, 0, ch->n - 1, chainpos[ca] + 1, chainpos[u], w);
		u = parent[head[u]];
	}
}

Segment query(int ca, int u) {
	int chid, chpos;
	Chain *ch;
	Segment tmpr = {0, 0, 0, 0, 0, 0}, tmpl, root;
	while(lvl[u] > lvl[ca]) {
		chid = chainid[u]; chpos = chainpos[u]; ch = chains[chid];
		if(lvl[head[u]] > lvl[ca]) tmpl = ch->ask(1, 0, ch->n - 1, chainpos[head[u]], chainpos[u]);
		else tmpl = ch->ask(1, 0, ch->n - 1, chainpos[ca] + 1, chainpos[u]);
		ch->update(root, tmpl, tmpr);
		tmpr = root;
		u = parent[head[u]];
	}
	return tmpr;
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
				temp[k]=cost[v];
				chainpos[v]=k;
				chainid[v]=nchain;
			}
			chains.pb(new Chain(temp,k));
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
		temp[k]=cost[v];
		chainid[v]=nchain;
	}
	chains.pb(new Chain(temp,k));
	nchain++;
}

/**************************************************************************************************/
//LCA

// 1) Using HLD
int lca(int a,int b){
	
	while(chainid[a]!=chainid[b]){
		
		if(lvl[head[a]]>lvl[head[b]]) a=parent[head[a]];
		else b=parent[head[b]];
	}
	return (lvl[a]<lvl[b])? a:b;
}

// 2) DP: (Fast and easy)

//After dfs...

void calcRoot(){

	int i,j;
	for(i=0;i<N;i++){
		for(j=0;1<<j < N;j++) P[i][j]=-1;
	}

	for(i=1;i<N;i++){
		P[i][0]=T[i];					//T[i] : Father of i
	}

	for(j=1;(1<<j)<N;j++){
		for(i=1;i<N;i++){
			if(P[i][j-1]!=-1)
				P[i][j]=P[P[i][j-1]][j-1];
		}
	}
	return;
}

int lca(int p,int q){
	int log,i,j;

	if(lvl[p]<lvl[q]) swap(p,q);

	for(log=1;(1<<log)<=lvl[p];log++) {}
		
	log--;

	for(i=log;i>=0;i--){
		if(lvl[p]-(1<<i)>=lvl[q]) p=P[p][i];
	} 
	

	if(p==q) return p;

	for(i=log;i>=0;i--){
		if(P[p][i]!=-1 && P[p][i]!=P[q][i])
			p=P[p][i];q=P[q][i];
	}
	return T[p];
}