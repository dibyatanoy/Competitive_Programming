#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main(){

	int x,y,a,b;
	scanf("%d %d %d %d",&x,&y,&a,&b);

	int lcm=x*y/gcd(x,y);

	int ans=(b/lcm)-(a-1)/lcm;

	printf("%d\n",ans);

	return 0;
} 