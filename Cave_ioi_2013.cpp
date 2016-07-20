#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define MAXX 5002

using namespace std;

int exploreCave(int N){
	int S[MAXX];
	int states[MAXX];	//the switch state for door i to be open
	int dis[MAXX];//the switch no of door i
	int sw_dr[MAXX] //switch i corresponds to ...
	int l,h,mid;

	memset(S,0,sizeof(S));
	memset(states,0,sizeof(states));
	memset(dis,-1,sizeof(dis));
	memset(sw_dr,-1,sizeof(sw_dr));

	int i,j,k;

	for(i=0;i<N;i++){
		l=0;
		h=N-1;
		memset(S,0,sizeof(S));
		for(j=0;j<i;j++) S[dis[j]]=states[j];

		int temp=tryCombination(S);
		if(temp>i||temp==-1) states[i]=0;
		else{
			states[i]=1;
		}

		//if(states[i]==1){
			while(l!=h){							//binary search
				mid=(l+h)/2;
				for(j=0;j<=mid;j++){
					if(sw_dr[j]==-1) S[j]=1;
				}
				for(j=mid+1;j<=h;j++){
					if(sw_dr[j]==-1) S[j]=0;
				}
				int response=tryCombination(S);
				if(response>i||response==-1){
					if(states[i]==1) h=mid;
					else l=mid+1;
				}else{
					if(states[i]==1) l=mid+1;
					else h=mid;
				}
			}
			dis[i]=l;
			sw_dr[l]=i;
		//}
	}
}

int main(){

	scanf("%d",&N);
	exploreCave(N);

	return 0;
}