#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#define pb push_back

using namespace std;

int bit[200010],N;
vector <int> aux;

void update(int pos,int val){
	int i;
	for(i=pos;i<=N;i+=(i& -i)){
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

	int kases,k;
	scanf("%d",&kases);

	for(k=1;k<=kases;k++){

		scanf("%d",&N);
		int i,j,nums[200010];
		memset(bit,0,sizeof(bit));
		aux.clear();

		for(i=0;i<N;i++){
			scanf("%d",&nums[i]);
			aux.pb(nums[i]);
		}

		sort(aux.begin(),aux.end());

		for(i=0;i<N;i++){
			nums[i]=lower_bound(aux.begin(),aux.end(),nums[i])-aux.begin()+1;
		}

		long long int swaps=0;
		for(i=N-1;i>=0;i--){
			swaps+=query(nums[i]);
			update(nums[i]+1,1);
		}
		printf("%lld\n",swaps);
	
	}

	return 0;
}
