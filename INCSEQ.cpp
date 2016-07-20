#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#define MAXR 100010
#define MAXX 10010
#define c 5000000

using namespace std;

int bit[MAXR];
int seq[MAXX],dp[MAXX][52];
int N,K;

void update(int pos,int val){
	int i;
	for(i=pos;i<=MAXR;i+=(i & -i)){
		bit[i]+=val;
		bit[i]%=c;
	}
	return;
}
int query(int pos){
	int i,sum=0;
	for(i=pos;i>0;i-=(i & -i)){
		sum+=bit[i];
		sum%=c;
	}
	return sum;
}

int main(){

	int i,len;

	scanf("%d %d",&N,&K);
	for(i=0;i<N;i++) scanf("%d",&seq[i]);

	memset(dp,0,sizeof(dp));

	for(i=0;i<N;i++) dp[i][1]=1;

	for(len=2;len<=K;len++){
		memset(bit,0,sizeof(bit));
		dp[0][len]=0;
		update(seq[0]+1,(dp[0][len-1])%c);
		for(i=1;i<N;i++){
			//printf("Reached with len=%d, i=%d\n",len,i);
			if(seq[i]!=0) dp[i][len]=query(seq[i])%c;
			else dp[i][len]=0;
			update(seq[i]+1,(dp[i][len-1])%c);
		}
	}
	int tot=0;
	for(i=0;i<N;i++) {tot+=dp[i][K];tot%=c;}
	
	printf("%d\n",tot);

	return 0;
}

/** AC!!! **/