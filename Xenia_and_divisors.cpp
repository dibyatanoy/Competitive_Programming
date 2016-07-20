#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;
int nums[8];
int N;
bool fnd;
vector <int> v1,v2,v3;
vector <int> n1,n2,n3;


int main(){

	bool val=0,inval=0;


	int t1=0,t2=0,t3=0;

	scanf("%d",&N);
	int i;
	memset(nums,0,sizeof(nums));
	for(i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		nums[x]++;
		if(x==5||x==7) inval=1;
		else if(x>3) val=1;
	}

	if(nums[4]){
		if(nums[1]<nums[4]||nums[2]<nums[4]) inval=true;
		else{
			nums[1]-=nums[4];
			nums[2]-=nums[4];
			t3=nums[4];
			nums[4]=0;
		}

	}
	if(nums[6]){
		if((nums[6]<nums[3])||nums[1]<nums[3]) inval=true;
		else if(nums[3]!=0){
			nums[1]-=nums[3];
			nums[6]-=nums[3];
			t2=nums[3];
			nums[3]=0;
		}else{
			if(nums[6]!=nums[2]||nums[6]!=nums[1])	inval=true;
			else{
				t1=nums[2];
				nums[1]-=nums[2];
				nums[6]-=nums[2];
				nums[2]=0;
			}
		}
	}
	if(!inval&&nums[1]==0&&nums[2]==0&&nums[3]==0&&nums[4]==0&&nums[5]==0&&nums[6]==0){
		for(i=0;i<t3;i++){
			printf("1 2 4\n");
		}
		for(i=0;i<t1;i++){
			printf("1 2 6\n");
		}
		for(i=0;i<t2;i++){
			printf("1 3 6\n");
		}
	}else printf("-1\n");


	return 0;
}