#include <stdio.h>
#include <math.h>

int main(){

	int testcase,i;
	double r1,r2,r3,s1,s2,s3,a1,a2,a3,area1,area2,ans;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%lf %lf %lf",&r1,&r2,&r3);

		s1=r1+r2;
		s2=r1+r3;
		s3=r2+r3;
		a1=acos((s2*s2+s3*s3-s1*s1)/(2*s2*s3));
		a2=acos((s1*s1+s3*s3-s2*s2)/(2*s1*s3));
		a3=acos((s2*s2+s1*s1-s3*s3)/(2*s2*s1));
		area1=0.5*s2*s3*sin(a1);
		area2=0.5*r1*r1*a3+0.5*r2*r2*a2+0.5*r3*r3*a1;
		ans=area1-area2;

		printf("Case %d: %.10lf\n",i,ans+1e-11);

	}

	return 0;
}

/** AC!!! **/