/*
ID: dibyapo2
LANG: C++
TASK: sort3
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define sz sizeof
#define all(a) a.begin(),a.end()
#define minim(a,b) (a<b)? a:b

using namespace std;

int nums[4],N,list[1002];

int main(){

	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);

	int i;
	vector<int>sorted;
	scanf("%d",&N);
	memset(nums,0,sz(nums));

	for(i=0;i<N;i++){
		scanf("%d",&list[i]);
		nums[list[i]]++;
		sorted.push_back(list[i]);
	}
	int lim[5];
	int swaps=0;
	int outofplace[3][3];
	memset(outofplace,0,sz outofplace);

	

	lim[1]=nums[1]-1;
	lim[2]=lim[1]+nums[2];
	lim[3]=lim[2]+nums[3];

	for(i=0;i<=lim[1];i++) outofplace[0][list[i]-1]++;
	for(i=lim[1]+1;i<=lim[2];i++) outofplace[1][list[i]-1]++;
	for(i=lim[2]+1;i<=lim[3];i++) outofplace[2][list[i]-1]++;

	swaps+=minim(outofplace[0][1],outofplace[1][0]);
	swaps+=minim(outofplace[0][2],outofplace[2][0]);
	swaps+=minim(outofplace[2][1],outofplace[1][2]);

	swaps+=(N-swaps*2-outofplace[0][0]-outofplace[1][1]-outofplace[2][2])/3*2;



	
	printf("%d\n",swaps);
	//for(int k=0;k<N;k++) printf("%d ",list[k]);
	//printf("\n");

	return 0;
}