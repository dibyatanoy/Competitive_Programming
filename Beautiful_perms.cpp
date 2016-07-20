#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define MAXX 100002
#define INF 1e6

using namespace std;

int maxim(int a,int b){
	return (a>b)? a:b;
}
int minim(int a,int b){
	return (a<b)? a:b;
}

int gcd(int a,int b){
	return(b==0)? a:gcd(b,a%b);
}

int main(){

	int n,k,i,j,cnt=0;
	int nums[MAXX];
	memset(nums,-1,sizeof(nums));

	scanf("%d %d",&n,&k);
	cnt=n-1;

	
	for(i=2;i<=n&&(cnt-2)>=k;i+=2){
		nums[i]=i+1;
		nums[i+1]=i;
		cnt-=2;
	}
	
	
	if(k==n||cnt-1>k||((n==1||n==2)&&k!=0)) printf("-1\n");
	else if(n==1&&k==0) printf("1\n");
	else if(n==2&&k==0) printf("1 2\n");
	else{
		
	
			//printf("%d ",cnt);
		if((cnt-1)==k){
			nums[1]=n;
			nums[n]=1;
		}
		if(nums[1]==-1) printf("1");
		else printf("%d",nums[1]);
		for(i=2;i<=n;i++){
			if(nums[i]==-1) printf(" %d",i);
			else printf(" %d",nums[i]);
		}
		
	}
	printf("\n");
	return 0;
}