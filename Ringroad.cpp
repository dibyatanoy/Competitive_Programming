#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main(){

	int N,M;
	int houses[100010];

	scanf("%d %d",&N,&M);

	int i;
	for(i=0;i<M;i++){
		scanf("%d",&houses[i]);
	}
	int curr_house=1;
	__int64 time=0;

	for(i=0;i<M;i++){
		if(houses[i]>=curr_house) {
			time+=houses[i]-curr_house;
		}else{
			time+=N+houses[i]-curr_house;
		}
		curr_house=houses[i];
	}

	printf("%I64d\n",time);

	return 0;
}