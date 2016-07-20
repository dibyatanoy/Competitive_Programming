#include <stdio.h>
#include <math.h>

int main(){

	int testcase,i,r1,r2,p,h;
	double ans,height_1,rad2,vol1,vol2;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%d %d %d %d",&r1,&r2,&h,&p);

		height_1=(double)h*r2/(r1-r2);
		rad2=(double)r2*(height_1+p)/height_1;
		vol1=2*acos(0.0)*rad2*rad2*(height_1+p);
		vol2=2*acos(0.0)*r2*r2*height_1;

		ans=vol1/3-vol2/3;

		printf("Case %d: %.9lf\n",i,ans);

	}

	return 0;
}

/* AC!!! */