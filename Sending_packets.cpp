#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1000000
#define pb push_back
#define eps 1e-8

using namespace std;

struct data{
    int u;
	double w;
    bool operator <(const data &p)const{
        return ((p.w-w)>eps);
    }
};

double dist[101];
vector <int> edges[102];
vector <double> cost[102];
int N,M,S,K;

int minim(int a,int b){
	return (a<b)? a:b;
}
int maxim(int a,int b){
	return (a>b)? a:b;
}

double dijkstra(int src){
    int i,j;
    for(i=0;i<101;i++){
        dist[i]=0.0;
    }
	dist[src]=1.0;
    priority_queue <data> Q;
    data temp;
    temp.u=src;temp.w=1.0;
    Q.push(temp);

    while(!Q.empty()){
        data curr=Q.top();Q.pop();

		if(curr.u==N-1) return curr.w;

        for(i=0;i<edges[curr.u].size();i++){
            int v=edges[curr.u][i];
			//printf("src=%d updating %d from %d\n",src,v,curr.u);
           
            if((curr.w*cost[curr.u][i]-dist[v])>eps){
				dist[v]=curr.w*cost[curr.u][i];
				//printf("!\n");
                data temp2;
                temp2.u=v;
				temp2.w=dist[v];
                Q.push(temp2);
            }
            
        }
    }
	return 0.0;

}


int main(){

    int i,j,kases;

	scanf("%d",&kases);

	for(i=0;i<kases;i++){
		
		scanf("%d %d %d %d",&N,&M,&S,&K);

		for(j=0;j<102;j++) {edges[j].clear();cost[j].clear();}

		for(j=0;j<M;j++){
			int u,v;
			double w;
			scanf("%d%d %lf",&u,&v,&w);

			edges[u].pb(v);edges[v].pb(u);
			cost[u].pb(w/100);cost[v].pb(w/100);
		}
		

		double route=dijkstra(0);
			//printf("%d\n",ans);
		//printf("%lf\n",route);
			
	
		printf("Case %d: %.6lf\n",i+1,(double)(2*K)/route*(double)S);
	}

    return 0;
}

/** AC!!! **/