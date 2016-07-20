/*
ID: dibyapo2
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct data1{
	int st;
	int ed;

	bool operator <(const data1&p)const{
		return st<p.st;
	}
	
};

typedef struct data2{
	int st;
	int ed;

	bool operator <(const data2&p)const{
		return ed<p.ed;
	}
	
};

vector <data1> times1;
vector <data2> times2;
int dp[5002],curr_st[5002],curr_ed[5002];

int main(){

	int N,max1=0,max2=0,curr1=0,curr2=0;

	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);

	scanf("%d",&N);

	int i,j;

	for(i=0;i<N;i++){
		int s,e;
		scanf("%d %d",&s,&e);
		data1 u;
		data2 v;
		u.st=s;u.ed=e;
		v.st=s;v.ed=e;
		times1.push_back(u);
		times2.push_back(v);
	}

	sort(times1.begin(),times1.end());

	//for(i=0;i<N;i++) printf("%d ",times1[i].st);

	dp[0]=times1[0].ed-times1[0].st;
	curr_ed[0]=times1[0].ed;

	for(i=1;i<N;i++){
		if(times1[i].st<=curr_ed[i-1]){
			if(times1[i].ed<curr_ed[i-1]) {
				dp[i]=dp[i-1];
				curr_ed[i]=curr_ed[i-1];
			}else {
				dp[i]=dp[i-1]+times1[i].ed-curr_ed[i-1];
				curr_ed[i]=times1[i].ed;
			}
		}else{
			dp[i]=times1[i].ed-times1[i].st;
			curr_ed[i]=times1[i].ed;
		}
	}


	for(i=0;i<N;i++){
		if(max1<dp[i]) max1=dp[i];
	}

	dp[0]=0;
	
	
	for(i=1;i<N;i++){
		if(times1[i].st>curr_ed[i-1]){
			dp[i]=times1[i].st-curr_ed[i-1];
			curr_ed[i]=times1[i].ed;
		}else{
			dp[i]=0;
			if(times1[i].ed<curr_ed[i-1]) curr_ed[i]=curr_ed[i-1];
			else curr_ed[i]=times1[i].ed;
		}
	}

	for(i=0;i<N;i++){
		if(max2<dp[i]) max2=dp[i];
	}


	printf("%d %d\n",max1,max2);

	return 0;
}

/** AC!!! **/