#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1000000
#define pb push_back

using namespace std;

struct data{
    int u,w;
    bool operator <(const data &p)const{
        return w>p.w;
    }
};

int dist[501][501],N,M,S,target;
int shop[20],s_now;
vector <int> edges[502],cost[502];
int dp[16][1<<16];
bool vis[16][1<<16];

int Set(int N,int pos){return N=(N |(1<<pos));}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int reset(int N,int pos){return N= N & ~(1<<pos);}

int minim(int a,int b){
	return (a<b)? a:b;
}
int maxim(int a,int b){
	return (a>b)? a:b;
}

void dijkstra(int src){
    int i,j;
    for(i=0;i<501;i++){
        dist[src][i]=INF;
    }
	dist[src][src]=0;
    priority_queue <data> Q;
    data temp;
    temp.u=src;temp.w=0;
    Q.push(temp);

    while(!Q.empty()){
        data curr=Q.top();Q.pop();

        for(i=0;i<edges[curr.u].size();i++){
            int v=edges[curr.u][i];
			//printf("src=%d updating %d from %d\n",src,v,curr.u);
           
            if(dist[src][v]>curr.w+cost[curr.u][i]){

				dist[src][v]=curr.w+cost[curr.u][i];
                data temp2;
                temp2.u=v;
				temp2.w=dist[src][v];
                Q.push(temp2);
            }
            
        }
    }
	return;

}

int call2(int pos,int mask){
	int cnt=0,i;
	if(mask==(1<<N)-1) {return (dist[shop[pos]][N-1]>=INF)? -INF:0;}
	if(vis[pos][mask]) return dp[pos][mask];

	int ret=0;
	bool done=0;

	for(i=0;i<S;i++){
		if(check(mask,i)==0 && dist[shop[pos]][shop[i]]<INF){
			int temp=Set(mask,i);
			done=1;
			ret=maxim(ret,call2(i,temp)+1);
		}
	}
	if(!done || ret==0){
		if(dist[shop[pos]][N-1]>=INF) ret=-INF;
	}

	vis[pos][mask]=1;
	return dp[pos][mask]=ret;

}

int call(int pos,int mask){
	int cnt=0,i;
	for(i=0;i<S;i++){
		if(check(mask,i)) cnt++;
	}
	if(cnt==target) return dist[shop[pos]][N-1];
	if(vis[pos][mask]) return dp[pos][mask];

	int ret=INF;

	for(i=0;i<S;i++){
		if(check(mask,i)==0){
			int temp=Set(mask,i);
			ret=minim(ret,call(i,temp)+dist[shop[pos]][shop[i]]);
		}
	}

	vis[pos][mask]=1;
	return dp[pos][mask]=ret;

}

int main(){

    int i,j,kases,ans;

	scanf("%d",&kases);

	for(i=0;i<kases;i++){
		s_now=0;
		ans=INF;
		scanf("%d %d %d",&N,&M,&S);

		for(j=0;j<502;j++) {edges[j].clear();cost[j].clear();}
		memset(vis,0,sizeof(vis));

		for(j=0;j<S;j++){
			int curr;
			scanf("%d",&curr);
			shop[s_now++]=curr;
		}

		for(j=0;j<M;j++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);

			edges[u].pb(v);
			cost[u].pb(w);
		}
		for(j=0;j<N;j++){
			dijkstra(j);
		}

		/*for(j=0;j<N;j++){
			for(int l=0;l<N;l++) printf("%d ",dist[j][l]);
			printf("\n");
		}*/

		int s_max=call2(0,0);
		target=s_max;
		for(int k=0;k<S;k++){
			memset(vis,0,sizeof(vis));
			int t=Set(0,k);
			ans=minim(ans,call(k,t)+dist[0][shop[k]]);
				
		}
			//printf("%d\n",ans);
			
		

		if(s_max>0) printf("Case %d: %d %d\n",i+1,s_max,ans);
		else{
			printf("Case %d: Impossible\n",i+1);
		}
	}

    return 0;
}
