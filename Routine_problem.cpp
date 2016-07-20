#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cstdlib>


using namespace std;

int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main(){

	int a,b,c,d;

	scanf("%d %d %d %d",&a,&b,&c,&d);

	int lcm1,lcm2,p,q;
	lcm1=a*c/gcd(a,c);
	lcm2=b*d/gcd(b,d);

	int a1,b1,c1,d1;
	a1=lcm1;c1=lcm1;b1=b*lcm1/a;d1=d*lcm1/c;

	if(d1<b1){
		p=b1-d1;
		q=b1;
		int gc=gcd(p,q);
		p/=gc;
		q/=gc;
	}else{
		a1=a*lcm2/b;c1=c*lcm2/d;b1=lcm2;d1=lcm2;
		p=a1-c1;
		q=a1;
		int gc=gcd(p,q);
		p/=gc;
		q/=gc;
	}

	printf("%d/%d\n",p,q);

	return 0;
}