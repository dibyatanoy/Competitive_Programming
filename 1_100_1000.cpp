#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define eps 1e-10

using namespace std;

int main(){

	int testcase,ans2;
	double pos;
	double ans1;

	scanf("%d",&testcase);

	while(testcase--){
		scanf("%lf",&pos);

		ans1=(double)(-0.5+sqrt(-7.0+8.0*pos)/2.0);
		ans2=(int)ans1;

		pos=ans1-(double)ans2;

		if(pos<=eps) printf("1 ");
		else printf("0 ");
	}

	return 0;
}