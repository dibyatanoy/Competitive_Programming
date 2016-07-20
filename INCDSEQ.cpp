#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#define MAXR 10010
#define MAXX 10010
#define c 5000000

using namespace std;

int bit[MAXR][55];
int seq[MAXX],dp[MAXX][55];
int N,K;


void update(int pos,int l,int val){
	int i;
	for(i=pos;i<=MAXR;i+=(i & -i)){
		bit[i][l]+=val;
		bit[i][l]%=c;
	}
	return;
}
int query(int pos,int l){
	int i,sum=0;
	for(i=pos;i>0;i-=(i & -i)){
		sum+=bit[i][l];
		sum%=c;
	}
	return sum;
}

int main(){

	int i,len;

	scanf("%d %d",&N,&K);

	int sz2=0,sz=0;
	vector<int> v(N);
	for(i=0;i<N;i++) {scanf("%d",&seq[i]);v[i]=seq[i];}

	sort(v.begin(),v.end());

	for(i=0;i<N;i++) seq[i]=lower_bound(v.begin(),v.end(),seq[i])-v.begin();
	//for(i=0;i<N;i++) printf("%d ",seq[i]);

	//sz=sz2+1;

	memset(dp,0,sizeof(dp));
	memset(bit,0,sizeof(bit));

	for(i=0;i<N;i++){

		//memset(curr_len_val,0,sizeof curr_len_val);

		for(len=1;len<=K;len++){
			//printf("Reached with len=%d, i=%d\n",len,i);
			/*if(seq[i]!=0)  pos=bin_srch(seq[i]);
			if(seq[i]!=0) {dp[i][len]=(query(pos)-curr_len_val[pos])%c;
			curr_len_val[pos]+=dp[i][len];
			curr_len_val[pos]%=c;
			}*/
				
				if(len==1) dp[i][len]=1;
			
				else dp[i][len]=query(seq[i],len-1);
				dp[i][len]=dp[i][len]-(query(seq[i]+1,len)-query(seq[i],len));
				update(seq[i]+1,len,(dp[i][len])%c);

			//printf("dp[%d][%d]=%d\n",i,len,dp[i][len]);
			//printf("Reached! ");
		}
	}
	int tot=0;
	for(i=0;i<N;i++) {tot+=dp[i][K];tot%=c;}
	
	printf("%d\n",tot);

	return 0;
}

/** AC!!! **/