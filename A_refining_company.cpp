#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;

int m,n;
int U[502][502];
int R[502][502];
long int dp[502][502];

long int max(long int a,long int b){
	if(a>b) return a;
	return b;
}

long int find_R(int r,int c){

	int ret=0;
	for(int cnt=r;cnt>=0;cnt--){
		ret+=R[cnt][c];
	}

	return ret;
}

long int find_U(int r,int c){

	int ret=0;
	for(int cnt=c;cnt>=0;cnt--){
		ret+=U[r][cnt];
	}

	return ret;
}


long int call(int row, int col){
	if(row<0||col<0) return 0;
	if(dp[row][col]!=-1) return dp[row][col];

	long int gain1,gain2;

	gain1=find_U(row,col)+call(row-1,col);
	gain2=find_R(row,col)+call(row,col-1);

	long int ans=max(gain1,gain2);

	return dp[row][col]=ans;


}

int main(){

	int testcase,i,j,k;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%d%d",&m,&n);

		for(int x=0;x<m;x++){
			for(int y=0;y<n;y++) scanf("%d",&U[x][y]);
		}

		for(j=0;j<m;j++){
			for(k=0;k<n;k++) scanf("%d",&R[j][k]);
		}
		
		memset(dp,-1,sizeof(dp));

		long int ans=call(m-1,n-1);

		printf("Case %d: %ld\n",i,ans);
		
	}

	return 0;
}

/** AC!!! **/