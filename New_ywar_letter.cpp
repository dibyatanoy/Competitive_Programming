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
int k,x;

int gcd(int a,int b){
	return (b==0)? a:gcd(b,a%b);


}
bool check(int i,int j){
	int seq[52],z;
	seq[1]=i;seq[2]=j;
	for(z=3;z<=k;z++){
		seq[z]=seq[z-1]+seq[z-2];
	}
	return seq[k]==x? 1:0;
}

int main(){

	int n,m,a;
	bool fnd=0;
	scanf("%d %d %d %d",&k,&x,&n,&m);

	int i,j;
	for(i=0;i<=n;i+=2){
		for(j=0;j<=m;j+=2){
			
			if(check(i/2,j/2)){
				fnd=1;
				break;
			}
		}
		if(fnd) break;
	}
	if(!fnd) printf("Happy new year!\n");
	else{
		//printf("%d %d ",i,j);
		for(a=0;a<i;a+=2) printf("AC");
		for(;a<n;a++) printf("B");
		printf("\n");
		for(a=0;a<j;a+=2) printf("AC");
		
		for(;a<m;a++) printf("B");
		printf("\n");
	}

	return 0;
}