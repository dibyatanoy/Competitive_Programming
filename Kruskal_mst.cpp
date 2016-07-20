#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct edges{
	int u,v,w;
	bool operator <(const edges &p)const{
		return w<p.w;
	}
};

vector <edges> e;
int pr[1000];

int find(int r){
	if(pr[r]==r) return r;
	else return pr[r]=find(pr[r]);
}

int mst(int n){
	int i;
	sort(e.begin(),e.end());
	for(i=1;i<=n;i++) pr[i]=i;

	int count=0,size=0;
	for(i=0;i<(int)e.size();i++){
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u!=v){
			size+=e[i].w;
			pr[u]=v;
			count++;
		}
		if(count==n-1) return s;
	}
}

int main(){
	//INPUT METHOD
}