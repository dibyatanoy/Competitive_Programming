#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MX 1000

using namespace std;

struct data{
	int v;
	int wt;
	bool operator <(const data &p)const{
		return wt>p.wt;
	}
};

vector <data> edges[MX];
priority_queue <data> Q;

int snowplough(){
	int cost=0;
	int i;
	for(i=0;i<edges[1].size();i++) Q.push_back(edges[1][i]);

	while((k-1)--){
		data u=Q.front();
		Q.pop();
		cost+=u.wt;
		for(i=0;i<edges[u.v].size();i++) Q.push_back(edges[u.v][i]);
	}
	return cost;
	
}

int main(){
	return 0;
}