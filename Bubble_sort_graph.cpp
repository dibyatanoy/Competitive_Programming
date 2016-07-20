#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#define MAXX 10010

using namespace std;

int bit[MAXX];

void update(int pos,int val){
	int i;
	for(i=pos;i<=MAXX;i+=(i & -i)){
		bit[i]+=val;
	}
	return;
}

int query(int pos){
	int i,sum=0;
	for(i=pos;i>0;i-=(i & -i)){
		sum+=bit[i];
	}
	return sum;
}

int main(){

	int N;
	int rem_nodes[MAXX],seq[MAXX];
	memset(rem_nodes,0,sizeof(rem_nodes));
	memset(bit,0,sizeof(bit));

	scanf("%d",&N);
	int i,j;

	for(i=0;i<N;i++){
		scanf("%d",&seq[i]);
	}

	int swaps;
	for(i=N-1;i>=0;i--){
		swaps=query(seq[i]-1);
		//printf("i=%d, query=%d\n",i,swaps);
		rem_nodes[seq[i]]+=swaps;
		update(seq[i],1);
	}
	memset(bit,0,sizeof(bit));
	for(i=0;i<N;i++){
		swaps=query(MAXX-4)-query(seq[i]);
		//printf("i=%d, query=%d\n",i,swaps);
		rem_nodes[seq[i]]+=swaps;
		update(seq[i],1);
	}

	int mincuts=MAXX+3;

	for(i=1;i<=N;i++){
		if(rem_nodes[i]<mincuts) mincuts=rem_nodes[i];
	}

	//for(i=0;i<N;i++){
	//	printf("%d\n",rem_nodes[i]);
	//}

	//if(N-mincuts==1) printf("0\n");
	/*else*/ printf("%d\n",N-mincuts);




	return 0;
}