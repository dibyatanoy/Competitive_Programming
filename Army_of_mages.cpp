#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define MAXX 100010
#define minim(a,b) (a<b)? a:b
#define maxim(a,b) ((a)>(b))? (a):(b)

using namespace std;

struct data{
	int x, y,pos;
};
vector <data> v[4];

int MOD(int a,int b){
	if(a<0) a=-a;
	if(b<0) b=-b;

	if(a%2==0 && b%2==0) return 0;
	if(a%2==0 && b%2==1) return 1;
	if(a%2==1 && b%2==0) return 2;
	if(a%2==1 && b%2==1) return 3;
}

int main(){

	int n,i,j;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		data t;
		scanf("%d %d",&t.x,&t.y);
		t.pos=i+1;

		int op=MOD(t.x,t.y);
		v[op].pb(t);
	}
	vector <>
	for(i=0;i<4;i++){
		if(v[op].size()>=n){
			sort
		}
	}

	return 0;
}