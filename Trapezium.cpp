#include <stdio.h>
#include <math.h>

int main(){

	int testcase,i;
	double a,b,c,d,x,area;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		
		if(c!=a){
		x=(d*d-b*b+(c-a)*(c-a))/(2*(c-a));

		area=0.5*(c+a)*(sqrt(d*d-x*x));

		printf("Case %d: %.8lf\n",i,area);
		}else{
			printf("Case %d: %.8lf\n",i,a*b);
		}

		
	}

	return 0;
}