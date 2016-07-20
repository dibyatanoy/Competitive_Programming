#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#define pb push_back
#define MP make_pair
#define minim(a,b) (((a)<(b))? (a):(b))
#define maxim(a,b) (((a)>(b))? (a):(b))

using namespace std;
int par[500002],dist[500002][2],op,curr=5;
bool type[500002];

int gcd(int a,int b){
	return (b==0)? a:gcd(b,a%b);

}

int main(){

	scanf("%d",&op);
	par[1]=-1;par[2]=1;par[3]=1;par[4]=1;
	dist[2][1]=0;dist[3][1]=0;dist[4][1]=0;
	dist[2][0]=0;dist[3][0]=0;dist[4][0]=0;

	int i,v,dia=2,cmax;
	for(i=0;i<op;i++){
		scanf("%d",&v);
		int cmax=0,c;
		par[curr]=v;type[curr]=0;dist[curr][0]=0;dist[curr++][1];par[curr]=v;type[curr]=1;dist[curr][0]=0;dist[curr++][1]=0;
		dist[v][0]=1;dist[v][1]=1;
		int d=1;

		while(par[v]!=1){
			c=v;
			v=par[v];
			if(d+1+dist[v][1-type[c]]>dia){
				dia=d+1+dist[v][1-type[c]];
				
			}
			dist[v][type[c]]=maxim(dist[v][type[c]],d+1);
			d++;
		}
		if(v==2){
			dia=maxim(dia,d+2+maxim(dist[3][0],dist[3][1]));
			dia=maxim(dia,d+2+maxim(dist[4][0],dist[4][1]));
		}else if(v==3){
			dia=maxim(dia,d+2+maxim(dist[2][0],dist[2][1]));
			dia=maxim(dia,d+2+maxim(dist[4][0],dist[4][1]));
		}else{
			dia=maxim(dia,d+2+maxim(dist[3][0],dist[3][1]));
			dia=maxim(dia,d+2+maxim(dist[2][0],dist[2][1]));
		}
		printf("%d\n",dia);
	}


	return 0;
}