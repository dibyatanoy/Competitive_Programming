#include <stdio.h>
#include <math.h>

int main(){

	int testcase,i,n;
	double R,angle,r;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%lf %d",&R,&n);
		angle=(double)2*acos(0.0)/n;
		r=R*sin(angle)/(1+sin(angle));

		printf("Case %d: %.8lf\n",i,r);
		
	}

	return 0;
}

/** AC!!! **/