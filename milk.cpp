/*
ID: dibyapo2
LANG: C++
TASK: milk
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

struct data{
	int rate;
	int amount;

	bool operator <(const data &p)const{
		return rate<p.rate;
	}
};


int main(){

	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);

	int N,M,i;
	vector <data> milk;

	scanf("%d %d",&N,&M);
	for(i=0;i<M;i++){
		int r,a;
		scanf("%d %d",&r,&a);
		data temp;
		temp.rate=r;temp.amount=a;
		milk.push_back(temp);
	}

	sort(milk.begin(),milk.end());

	int cost=0;

	for(i=0;i<M;i++){
		if(milk[i].amount<=N){
			cost+=milk[i].rate*milk[i].amount;
			N-=milk[i].amount;
		}else {
			cost+=milk[i].rate*N;
			break;
		}
	}
	printf("%d\n",cost);


	return 0;
}
/** AC!!! **/