#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int main(){

	int n,nums[102];
	int max=-10000,min=10000;
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%d",&nums[i]);
	}
	sort(nums,nums+n);
	max=nums[0];
	nums[0]=nums[n-1];
	nums[n-1]=max;

	printf("%d",nums[0]);

	for(int j=1;j<n;j++){
		printf(" %d",nums[j]);
	}
	printf("\n");

	return 0;
}