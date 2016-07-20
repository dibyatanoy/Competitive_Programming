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

int gcd(int a,int b){
	return (b==0)? a:gcd(b,a%b);
}

int main(){

	int n,a[302];

	scanf("%d",&n);
	int i,j;

	for(i=0;i<n;i++) scanf("%d",&a[i]);

	
	for(i=0;i<n-1;i++){
		if(a[i]==0) printf("R");
		else{for(j=0;j<a[i];j++){
			if(j!=a[i]-1)printf("PRL");
			else printf("PR");
		}
		}
	}
	for(i=0;i<a[n-1];i++){
		printf("PLR");
		
	}
	printf("\n");

	return 0;
}
