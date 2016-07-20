#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cstdlib>


using namespace std;

int minim(int a,int b){
	if(a<b) return a;
	return b;
}

int main(){

	int n,m,nums[1010];

	scanf("%d %d",&n,&m);

	int i;
	for(i=0;i<m;i++){
		scanf("%d",&nums[i]);
	}
	sort(nums,nums+m);

	int	minx=100000;
	for(i=0;i+n-1<m;i++){
		minx=minim(minx,nums[i+n-1]-nums[i]);
	}
	printf("%d\n",minx);

	return 0;
}