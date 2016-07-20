#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int best=100000002;
int seq[100010],rt[100010],lt[100010];

int minim(int a,int b){
	return (a<b)? a:b;
}

int main(){

	int n,k,seq[100010],rt[100010],lt[100010],i,j,b_pos;


	scanf("%d %d",&n,&k);

	for(i=0;i<n;i++){
		scanf("%d",&seq[i]);
		rt[i]=seq[i];
	}
	for(i=0;i<n;i++){
		if(i<k) lt[i]=0;
		else{
			lt[i]=lt[i-k]+seq[i-k];
		}
	}
	for(i=n-1;i>=0;i--){
		if(i+k>n-1) continue;
		else{
			rt[i]=rt[i+k]+seq[i];
		}
	}
	for(i=0;i<n;i++){
		if(lt[i]+rt[i]<best){
			best=lt[i]+rt[i];
			b_pos=i;
		}
	}
	printf("%d\n",b_pos+1);


	return 0;
}
/** AC!!! **/