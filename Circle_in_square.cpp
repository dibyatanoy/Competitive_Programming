#include <stdio.h>
#include <math.h>

int main(){
	
	int testcase,i;
	long double radius,sq_area,ans;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%Lf",&radius);

		sq_area=4*radius*radius;
		ans=sq_area-2*acos(0.0)*radius*radius;

		printf("Case %d: %.2Lf\n",i,ans);
	}
	
	return 0;
}