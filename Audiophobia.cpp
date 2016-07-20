#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 1e7

using namespace std;
int S,C;
int sound[102][102];

int max(int a,int b){
	if(a>b) return a;
	return b;
}
int min(int a,int b){
	if(a<b) return a;
	return b;
}

void relax(int i,int j,int k){
	sound[i][j]=min(sound[i][j],max(sound[i][k],sound[k][j]));
	return;
}
void FLOYD(){
	int i,j,k;
	for(k=1;k<=S;k++){
		for(i=1;i<=S;i++){
			for(j=1;j<=S;j++){
				relax(i,j,k);
			}
		}
	}
	return;
}

int main(){

	int Q,kase=0,j;
	while(scanf("%d %d %d",&S,&C,&Q)==3 && S!=0){
		int i,x,y,wt;
		for(i=1;i<=S;i++){
			for(j=1;j<=S;j++) sound[i][j]=INF;
		}
		for(i=1;i<=C;i++){
			scanf("%d %d %d",&x,&y,&wt);
			sound[x][y]=wt;
			sound[y][x]=wt;
		}
		FLOYD();
		if(kase>0)printf("\nCase #%d\n",++kase);
		else printf("Case #%d\n",++kase);
		for(i=1;i<=Q;i++){
			scanf("%d%d",&x,&y);
			if(sound[x][y]!=INF) printf("%d\n",sound[x][y]);
			else printf("no path\n");
		}
	}
	return 0;
}

/** AC!!! **/