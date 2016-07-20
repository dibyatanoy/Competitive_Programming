#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define maxim(a,b) (a>b)? a:b
#define minim(a,b) (a<b)? a:b
#define INF 1e7
#define pb push_back
#define mp make_pair

using namespace std;

int gcd(int a,int b){
	return (b==0)? a:gcd(b,a%b);
}

int main(){

	int N,pt[1002];

	scanf("%d",&N);

	int i,j;
	for(i=0;i<N;i++){
		scanf("%d",&pt[i]);
	}

	int l=-1e6-2,r=1e6+2;
	bool fnd=0;

	for(i=0;i<N-1;i++){
		if(pt[i]<pt[i+1]){
			if(pt[i+1]>r){
				fnd=1;
				printf("yes\n");
				break;
			}else{
				l=pt[i];
			}
		}else if(pt[i]>pt[i+1]){
			if(pt[i+1]<l){
				fnd=1;
				printf("yes\n");
				break;
			}else{
				r=pt[i];
			}
		}
	}
	if(!fnd) printf("no\n");

	return 0;
}