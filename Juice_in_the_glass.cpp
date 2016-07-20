#include<stdio.h>
#include<math.h>

#define pi 3.141592

void main(){

	int t,i;
	double r1,r2,h,p,x,frustum_vol1,frustum_vol2,juice_vol1,juice_vol2;

	scanf("%d",&t);

	for(i=1;i<=t;i++){

		scanf("%f %f %f %f",&r1,&r2,&h,&p);
		
		x=h*r2/(r1-r2);
		frustum_vol1=1/3*pi*r1*r1*(x+h);
		frustum_vol2=1/3*pi*r2*r2*x;
		juice_vol1=(frustum_vol1-frustum_vol2);
		juice_vol2=juice_vol1*(p/h)*(p/h)*(p/h);

		printf("Case %d: %f\n",i,juice_vol2);

	
	}
}
