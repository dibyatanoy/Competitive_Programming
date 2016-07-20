#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

long long int N;
long long int fact[22];
vector <int> sols;
bool fnd=0;
int T,kase;

void process(){
	printf("Case %d: ",kase);
	printf("%d!",sols[0]);
	for(int j=1;j<sols.size();j++) printf("+%d!",sols[j]);
	printf("\n");
	
}

void call(int pos,long long int rem){
	if(fnd) return;
	if(rem==0) {fnd=1;process();}
	else if(pos==19) return;
	else{
		if(fact[pos]<=rem){
			call(pos+1,rem);
			sols.push_back(pos);
			call(pos+1,rem-fact[pos]);
			sols.pop_back();
		}
	}
	return;
}

int main(){
	scanf("%d",&T);
	for(kase=1;kase<=T;kase++){
		fnd=0;
	scanf("%lld",&N);

	int i,j;
	fact[0]=1;
	for(i=1;i<20;i++) fact[i]=i*fact[i-1];

	call(0,N);
	if(!fnd) printf("Case %d: Impossible\n",kase);
	}
}