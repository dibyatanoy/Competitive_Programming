#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#define pb push_back
#define MP make_pair
#define minim(a,b) (((a)<(b))? (a):(b))
#define maxim(a,b) (((a)>(b))? (a):(b))

using namespace std;

struct data{
	int pos, a;
	bool operator <(const data&p)const{
		return a<p.a;
	}
};

int rate[300002];
vector <data> rate2;

int gcd(int a,int b){
	return (b==0)? a:gcd(b,a%b);
}

int main(){

	int n,distinct=0;
	scanf("%d",&n);

	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&rate[i]);
		data temp;
		temp.pos=i;temp.a=rate[i];
		rate2.pb(temp);

	}
	sort(rate2.begin(),rate2.end());

	for(i=0;i<n;i++){
		if(i==0) {rate[rate2[i].pos]=rate2[i].a;distinct=rate2[i].a;}
		else{
			if(rate2[i].a==rate2[i-1].a){
				rate[rate2[i].pos]=rate[rate2[i-1].pos]+1;
				distinct=rate[rate2[i].pos];
			}else {
				
				if(rate2[i].a>distinct){rate[rate2[i].pos]=rate2[i].a;distinct=rate[rate2[i].pos];}
				else {
					rate[rate2[i].pos]=distinct+1;
					distinct++;
				}
			}
		}
	}
	printf("%d",rate[0]);
	for(i=1;i<n;i++) printf(" %d",rate[i]);

	printf("\n");

	return 0;
}