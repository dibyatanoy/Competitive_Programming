/*
ID: dibyapo2
TASK: numtri
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int numtri[1001][1001],dp[1001][1001];
int R;

int maxim(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){

	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);

	scanf("%d",&R);
	int i,j;

	for( i=0;i<R;i++){
		for( j=0;j<i+1;j++) scanf("%d",&numtri[i][j]);
	}
	/*for( i=0;i<R;i++){
		for( j=0;j<i+1;j++) printf("%d ",numtri[i][j]);
		printf("\n");
	}*/
	int max=0;
	dp[0][0]=numtri[0][0];
	max=dp[0][0];

	for(i=1;i<R;i++){
		for(j=0;j<i+1;j++){
			if(j-1<0){
				dp[i][j]=dp[i-1][j]+numtri[i][j];
			}else if(j==i){
				dp[i][j]=dp[i-1][j-1]+numtri[i][j];
			}else{
				dp[i][j]=maxim(dp[i-1][j],dp[i-1][j-1])+numtri[i][j];
			}
			if(i==R-1&&dp[i][j]>max) max=dp[i][j];
		}

	}

	printf("%d\n",max);


	return 0;
}