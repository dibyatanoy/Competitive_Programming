#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define pb push_back
#define INF 1e7

using namespace std;

int maxim(int a,int b){
	return (a>b)? a:b;
}

int minim(int a,int b){
	return (a<b)? a:b;
}

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main(){

	int n,i,x,y,t1=0,t2,t3,t4,s1,s2;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		s1=(s1+x)%2;
		s2=(s2+y)%2;
		if((x+y)%2==1) t1++;
	}
	if(s1==0&&s2==0) printf("0\n");
	else if(s1==1&&s2==1){
		if(t1) printf("1\n");
		else printf("-1");
	}else{
		printf("-1\n");
	}

	return 0;
}