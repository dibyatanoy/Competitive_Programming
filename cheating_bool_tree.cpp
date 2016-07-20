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
#define MAXX 30005
#define all(v) v.begin(),v.end()

using namespace std;
vector <int> edges[MAXX];
bool change[MAXX],vis[MAXX][2],gate[MAXX],I[MAXX];
int M,V,dp[MAXX][2];

int call(int v,bool val){
	if(edges[v].size()==0){
		if(I[v]==val){
			return 0;
		
		}else return INF;
	}
	if(vis[v][val]) return dp[v][val];

	int gain1=10004,gain2=10004;

	if(!gate[v]){
		if(val==0){
			gain1=call(edges[v][0],0)+call(edges[v][1],0);
			if(change[v]) {
				gain1=minim(gain1,call(edges[v][0],0)+call(edges[v][1],1)+1);
				gain1=minim(gain1,call(edges[v][0],1)+call(edges[v][1],0)+1);
				gain1=minim(gain1,call(edges[v][0],0)+call(edges[v][1],0)+1);
			}
		}else{
			gain1=minim(gain1,call(edges[v][0],0)+call(edges[v][1],1));
			gain1=minim(gain1,call(edges[v][0],1)+call(edges[v][1],0));
			gain1=minim(gain1,call(edges[v][0],1)+call(edges[v][1],1));
			if(change[v]) {
				gain1=minim(gain1,call(edges[v][0],1)+call(edges[v][1],1)+1);
			}
		}
	}else{
		if(val==0){
			gain1=minim(gain1,call(edges[v][0],0)+call(edges[v][1],1));
			gain1=minim(gain1,call(edges[v][0],1)+call(edges[v][1],0));
			gain1=minim(gain1,call(edges[v][0],0)+call(edges[v][1],0));
			if(change[v]){
				gain1=minim(gain1,call(edges[v][0],0)+call(edges[v][1],0)+1);
			}
		}else{
			gain1=call(edges[v][0],1)+call(edges[v][1],1);
			if(change[v]){
				gain1=minim(gain1,call(edges[v][0],0)+call(edges[v][1],1)+1);
				gain1=minim(gain1,call(edges[v][0],1)+call(edges[v][1],0)+1);
				gain1=minim(gain1,call(edges[v][0],1)+call(edges[v][1],1)+1);
			}
		}
	}

	vis[v][val]=1;
	return dp[v][val]=gain1;

}

int main(){

    int kases,i,j;
	scanf("%d",&kases);

	for(i=1;i<=kases;i++){
		for(j=0;j<MAXX;j++) edges[j].clear();

		scanf("%d %d",&M,&V);

		for(j=0;j<(M-1)/2;j++){
			int g,c;
			scanf("%d %d",&g,&c);

			gate[j+1]=g;
			change[j+1]=c;
			edges[j+1].pb(2*(j+1));
			edges[j+1].pb(2*(j+1)+1);
		}
		for(;j<M;j++){
			int val;
			scanf("%d",&val);
			I[j+1]=val;

		}

		memset(vis,0,sizeof(vis));
		int ans=call(1,V);
		if(ans>M){
			printf("Case %d: IMPOSSIBLE\n",i);
		}else printf("Case %d: %d\n",i,ans);
	}
	
    return 0;
}