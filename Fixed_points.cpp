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

	int n,nums[100002],fp=0;
	int inplace[100002];
	memset(nums,-1,sizeof(nums));
	memset(inplace,-1,sizeof(inplace));
	bool found2=0,f1=0;

	scanf("%d",&n);

	int i;
	for(i=0;i<n;i++){
		scanf("%d",&nums[i]);
		if(nums[i]==i) {fp++;inplace[i]=1;}
		else{
			f1=1;
			inplace[i]=0;
			if(inplace[nums[i]]==0&&nums[nums[i]]==i) found2=1;
		}
	}
	if(f1&&found2) printf("%d\n",fp+2);
	else if(f1)printf("%d\n",fp+1);
	else{
		printf("%d\n",fp);
	}

	return 0;
}