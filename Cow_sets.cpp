#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N,A,B;
vector <int> id;

int call(int sum,int i){
	if(i==N){
		if(sum>=A&&sum<=B) return 1;
		else return 0;
	}
	if(sum<A) return 0;
	//if((sum-1e7*(N-i))>B) return 0;
	return call(sum+id[i],i+1)+call(sum,i+1);
}

int main(){

	scanf("%d %d %d",&N,&A,&B);
	for(int i=0;i<N;i++) {int a;scanf("%d",&a);id.push_back(a);}

	sort(id.begin(),id.end());
	reverse(id.begin(),id.end());

	int ans=call(id[0],1)+call(0,1);

	printf("%d\n",ans);
	return 0;
}