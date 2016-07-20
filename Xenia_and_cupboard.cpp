#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main(){

	int r,h,b,rem;
	scanf("%d %d",&r,&h);

	b=(h/r)*2;
	rem=h-r*(h/r);

	double r2=r;
	if(rem>=(r2/2)) b+=2;
	else b+=1;

	printf("%d\n",b);

	return 0;
}