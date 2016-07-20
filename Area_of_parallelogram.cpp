#include <stdio.h>
#include <math.h>

int main(){

	int testcase,i,Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;
	long int sum1,sum2,area;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%d %d %d %d %d %d",&Ax,&Ay,&Bx,&By,&Cx,&Cy);
		Dx=Cx-(Bx-Ax);
		Dy=Ay+(Cy-By);
		sum1=Ax*By+Bx*Cy+Cx*Dy+Dx*Ay;
		sum2=Bx*Ay+By*Cx+Cy*Dx+Dy*Ax;
		area=(sum1-sum2)/2;

		printf("Case %d: %d %d %ld\n",i,Dx,Dy,abs(area));
	}

	return 0;
}

/** AC!!! **/