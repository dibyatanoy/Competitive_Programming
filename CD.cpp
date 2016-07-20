#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int dir[1000][22],N,indx;
long int dp[1000][22];
int length[22];

int printks(int w,int j){
	if(dir[w][j]==-1) {/*printf("Reached pks(%d,%d) ",w,j);*/return 0;}
	if(dir[w][j]==1){ 
		printf("%d ",length[j]);
		printks(w+length[j],j+1);
	}else{
		printks(w,j+1);
	}
	return 0;
}

int ks(int weight,int i){
	if(i==indx) return 0;
	if(dp[weight][i]!=-1) return dp[weight][i];

	int gain1=0,gain2=0;

	if(weight+length[i]<=N) gain1=ks(weight+length[i],i+1)+length[i];
	gain2=ks(weight,i+1);

	if(gain1>gain2){
		dp[weight][i]=gain1;
		dir[weight][i]=1;
	}
	else {dp[weight][i]=gain2;dir[weight][i]=2;}

	return dp[weight][i];
}

int main(){

	while(scanf("%d%d",&N,&indx)==2){
		int i;
		for(i=0;i<indx;i++){
			scanf("%d",&length[i]);
		}

		memset(dp,-1,sizeof(dp));
		memset(dir,-1,sizeof(dir));

		double ans=ks(0,0);

		printks(0,0);

		printf("sum:%.lf\n",ans);
	}

	return 0;
}

/** AC!!! */
