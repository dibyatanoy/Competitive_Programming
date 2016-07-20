/*
ID: dibyapo2
TASK: nocows
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define MUST 1

using namespace std;

int dp[201][101];
bool visited[201][101];
int N,K;

int call(int r_node,int r_ht){
	if(r_node%2==0) return 0;
	if(r_node==0||r_ht==0) return 0;
	if(r_node==1) return 1;

	if(visited[r_node][r_ht]) return dp[r_node][r_ht];

	int gain=0,i,j,temp1,temp2;

	for(i=1;i<r_node-1;i++){
		
		gain=(gain+call(i,r_ht-1)*call(r_node-i-1,r_ht-1))%9901;
	}
	
	visited[r_node][r_ht]=1;
	dp[r_node][r_ht]=gain;
	return dp[r_node][r_ht];

}

int main(){

	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);

	scanf("%d %d",&N,&K);
	if(N%2==0){
		printf("0\n");
		return 0;
	}
	memset(visited,0,sizeof(visited));

	call(N,K);

	printf("%d\n",(9901+call(N,K)-call(N,K-1))%9901);

	return 0;
}
	
