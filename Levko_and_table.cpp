#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define MAXX 1000
#define INF 1e6

using namespace std;

int maxim(int a,int b){
	return (a>b)? a:b;
}
int minim(int a,int b){
	return (a<b)? a:b;
}

int gcd(int a,int b){
	return(b==0)? a:gcd(b,a%b);
}

int main(){

	int i,j;
	int grid[102][102];

	int n,k;
	scanf("%d %d",&n,&k);

	int d=k-(n-1);

	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			grid[i][j]=1;
		}
	}
	for(i=n-1;i>=0;i--){
		for(j=n-i;j<n;j++){
			grid[i][j]=1;
		}
	}
	for(i=0;i<n;i++){
		grid[i][n-i-1]=d;
	}
	for(i=0;i<n;i++){
		printf("%d",grid[i][0]);
		for(j=1;j<n;j++){
			printf(" %d",grid[i][j]);
		}
		printf("\n");
	}

	return 0;
}