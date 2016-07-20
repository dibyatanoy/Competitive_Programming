#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int N,indx,n;
long int dp[32][1005];
int cost[1002],weight[1002],group[102];

/*int printks(int w,int j){
	if(dir[w][j]==-1) {printf("Reached pks(%d,%d) ",w,j);return 0;}
	if(dir[w][j]==1){ 
		printf("%d ",length[j]);
		printks(w+length[j],j+1);
	}else{
		printks(w,j+1);
	}
	return 0;
}*/

long int ks(int wt,int i){
	if(i==n) return 0;
	if(dp[wt][i]!=-1) return dp[wt][i];

	long int gain1=0,gain2=0;

	if(wt+weight[i]<=N) gain1=ks(wt+weight[i],i+1)+cost[i];
	gain2=ks(wt,i+1);

	if(gain1>gain2){
		dp[wt][i]=gain1;
		//dir[wt][i]=1;
	}
	else {dp[wt][i]=gain2;}//dir[wt][i]=2;}
	
	return dp[wt][i];
}

int main(){
	
	int testcase;

	scanf("%d",&testcase);
	while(testcase--){
		int G,i;

		scanf("%d",&n);

		for(i=0;i<n;i++) scanf("%d%d",&cost[i],&weight[i]);
		scanf("%d",&G);
		for(i=0;i<G;i++) scanf("%d",&group[i]);



		long int ans=0;

		for(i=0;i<G;i++){
			N=group[i];
			memset(dp,-1,sizeof(dp));
			ans+=ks(0,0);
		}

		//printks(0,0);

		printf("%ld\n",ans);
	}

	return 0;
}


