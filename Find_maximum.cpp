#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define pb push_back
#define INF 1e7
#define MAXX 100002

using namespace std;

int maxim(int a,int b){
	return (a>b)? a:b;
}

int minim(int a,int b){
	return (a<b)? a:b;
}

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main(){

	int nums[MAXX],sum[MAXX];
	char bit[MAXX];

	int n,i;

	scanf("%d",&n);

	scanf("%d",&nums[0]);
	sum[0]=nums[0];

	for(i=1;i<n;i++){
		scanf("%d",&nums[i]);
		sum[i]=sum[i-1]+nums[i];
	}
	int max_sum=0,max_pos,max_add;
	scanf("%s",bit);

	int l=strlen(bit);
	int curr_add=0;

	for(i=l-1;i>=0;i--){
		if(i==0&&bit[i]=='1'){
			if(sum[i]+curr_add>max_sum){
				max_sum=sum[i]+curr_add;
			}
		}
		else if(bit[i]=='1'){
			//printf("Found,i=%d\n",i);
			if(sum[i-1]+curr_add>max_sum){
				max_sum=sum[i-1]+curr_add;
			}
			curr_add+=nums[i];
		}
	}
	printf("%d\n",max_sum);
	
	return 0;
}