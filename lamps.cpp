/*
ID: dibyapo2
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <set>
#include <map>

using namespace std;

struct data{
	bool states[102];
	
	bool operator <(const data &p) const{
		int i;
		for(i=1;i<=sizeof(states)-1;i++){
			if(states[i]<p.states[i]) return 1;
			if(states[i]>p.states[i]) return 0;
		}
		return 0;
	}
};

vector <data> results;
int final[102];
	int N,C;

void toggle1(bool temp[102]){
	for(int i=1;i<=N;i++) temp[i]=!(temp[i]);
}

void toggle2(bool temp[102]){
	for(int i=1;i<=N;i+=2) temp[i]=!(temp[i]);
}

void toggle3(bool temp[102]){
	for(int i=2;i<=N;i+=2) temp[i]=!(temp[i]);
}
void toggle4(bool temp[102]){
	for(int i=1;i<=N;i+=3) temp[i]=!(temp[i]);
}

bool isvalid(bool temp[102]){
	for(int i=1;i<=N;i++){
		if(final[i]!=-1&&temp[i]!=final[i]) return 0;

	}
	return 1;
}

void process(bool temp[102]){
	data curr;
	for(int i=1;i<=N;i++) curr.states[i]=(bool)temp[i];

	results.push_back(curr);
}

int main(){

	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);

	scanf("%d",&N);
	memset(final,-1,sizeof(final));

	scanf("%d",&C);
	int curr;
	bool fnd=0;
	while(scanf("%d",&curr)&&curr!=-1){
		final[curr]=1;
	}
	while(scanf("%d",&curr)&&curr!=-1){
		final[curr]=0;
	}

	int i,j,k,l;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				for(l=0;l<2;l++){
					if((i+j+k+l)%2!=C%2||(i+j+k+l)>C) continue;
					bool temp[102];
					memset(temp,1,sizeof(temp));
					if(i==1) toggle1(temp);
					if(j==1) toggle2(temp);
					if(k==1) toggle3(temp);
					if(l==1) toggle4(temp);
					if(isvalid(temp)) {/*printf("i=%d,j=%d,k=%d,l=%d\n",i,j,k,l);*/fnd=1;process(temp);}
				}
			}
		}
	}

	sort(results.begin(),results.end());

	for(i=0;i<results.size()&&fnd==1;i++){
		for(j=1;j<=N;j++) printf("%d",(int)(results[i].states[j]));
		printf("\n");
	}
	/*if(C==0){
		fnd=1;
		for(i=0;i<N;i++) printf("1");
		printf("\n");
	}*/
	if(fnd==0) printf("IMPOSSIBLE\n");


	return 0;
}

/** AC!!! **/