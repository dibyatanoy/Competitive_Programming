#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#define minim(a,b) (a<b)? a:b
#define maxim(a,b) (a>b)? a:b

using namespace std;
char grid[22][22];
int m,n,dp[16][1<<16],gold,posx[16],posy[16];
bool vis[16][1<<16];

bool check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){return N=(N|(1<<pos));}

int call(int i,int mask){

	int cost,cost2;

	if(mask==(1<<gold)-1) {
		//cost=minim(abs(posx[gold]-posx[i]),abs(posy[gold]-posy[i]));
		cost2=maxim(abs(posx[gold]-posx[i]),abs(posy[gold]-posy[i]));
		return cost2;
	}
	if(vis[i][mask]) return dp[i][mask];

	int ret=100000000,k;

	for(k=0;k<gold;k++){
		if(check(mask,k)==0){
			int temp=Set(mask,k);
			//cost=minim(abs(posx[k]-posx[i]),abs(posy[k]-posy[i]));
			cost2=maxim(abs(posx[k]-posx[i]),abs(posy[k]-posy[i]));
			//printf("\n%d %d",cost,cost2);
			ret=minim(ret,call(k,temp)+cost2);
		}
	}
	vis[i][mask]=1;
	return dp[i][mask]=ret;
}

int main(){

	int kases,i,j,k,st_x,st_y;

	scanf("%d",&kases);

	for(i=1;i<=kases;i++){
		
		scanf("%d %d",&m,&n);
		for(j=0;j<m;j++) scanf("%s",grid[j]);
		memset(vis,0,sizeof(vis));

		gold=0;

		for(j=0;j<m;j++){
			for(k=0;k<n;k++){
				if(grid[j][k]=='g') {posx[gold]=j;posy[gold++]=k;}
			}
		}

		for(j=0;j<m;j++){
			for(k=0;k<n;k++){
				if(grid[j][k]=='x') {posx[gold]=j;posy[gold]=k;break;}
			}
		}
		//printf("%d %d %d %d ",posx[0],posy[0],posx[gold],posy[gold]);

		int ans=call(gold,0);

		printf("Case %d: %d\n",i,ans);
	}

	return 0;
}