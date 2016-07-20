#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXX 10002

using namespace std;
struct data{
	int u,v,w;
	bool operator <(const data &p)const{
		return w < p.w;
	}
};

int N,M,A,components;
vector <data> edges;
int pr[MAXX];

int find(int u){
	return (pr[u]==u)? u:find(pr[u]);
}

long long int mst(){
	int i,j;
	for(i=0;i<MAXX;i++) pr[i]=i;
	long long int cost=0;
	components=N;
	sort(edges.begin(),edges.end());
	
	for(i=0;i<M&&components>1;i++){
		if(edges[i].w>=A) break;
		else{
			int u=find(edges[i].u);
			int v=find(edges[i].v);
			if(u!=v){
				cost+=edges[i].w;
				pr[u]=v;
				components--;
			}
		}
	}
	//printf("%d\n",cost);
	cost+=A*components;
	return cost;
}

int main(){

	int kases,i,j;
	scanf("%d",&kases);

	for(i=1;i<=kases;i++){
		scanf("%d%d%d",&N,&M,&A);
		edges.clear();
		for(j=0;j<M;j++){
			data temp;
			scanf("%d %d %d",&temp.u,&temp.v,&temp.w);
			edges.push_back(temp);
			//data temp1;
			//temp1.u=temp.v;temp1.v=temp.u;temp1.w=temp.w;
			//edges.push_back(temp1);
		}
		long long int cost=mst();
		printf("Case #%d: %lld %d\n",i,cost,components);
	}

	return 0;
}
/** AC!!! **/
