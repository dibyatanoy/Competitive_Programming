#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define INF 1e15

using namespace std;

int dp[1003][1003][2];
bool vis[1003][1003][2];
int N,nums[1003];

long long int minim(long long int a,long long int b){
	return (a<b)? a:b;
}

long long int call(int l,int r,int f){
	if(l==0&&r>=N-1) return 0;
	if(vis[l][r][f]) return dp[l][r][f];

	long long int cost1=INF,cost2=INF;

	if(f){
		if(l>0) cost1=call(l-1,r,1)+(nums[l]-nums[l-1])*(N-(r-l+1));
		if(r<N-1)cost2=call(l,r+1,0)+(nums[r+1]-nums[l])*((N-(r-l+1)));
	}else{
		if(l>0) cost1=call(l-1,r,1)+(nums[r]-nums[l-1])*((N-(r-l+1)));
		if(r<N-1) cost2=call(l,r+1,0)+(nums[r+1]-nums[r])*(N-(r-l+1));
	}
	vis[l][r][f]=1;

	return dp[l][r][f]=minim(cost1,cost2);
}

int main(){

	int i,j,L,h=-1,l=-1;

	scanf("%d %d",&N,&L);

	h=-1,l=-1;
	for(i=0;i<N;i++){
		scanf("%d",&nums[i]);
		if(nums[i]<=L) l=i;
		if(nums[i]>=L&&h!=-1) h=i;
	}

	memset(vis,0,sizeof vis);

	long long int ans=1000000;
	if(l!=-1) ans=call(l,l,1)+(long long)(N*(L-nums[l]));
	if(h!=-1) ans=minim(ans,call(h,h,0)+(long long )(N*(nums[h]-L)));

	printf("%lld\n",ans);
	return 0;
}
