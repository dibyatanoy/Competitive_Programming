#include <stdio.h>
#include <math.h>

int main(){

	int testcase,i,Ox,Oy,Ax,Ay,Bx,By;
	long double radius,angle,s1,ans;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%d %d %d %d %d %d",&Ox,&Oy,&Ax,&Ay,&Bx,&By);
		
		if(!(Ax==Ox && Ay==Oy)){
		radius=sqrt(abs((Ax-Ox)*(Ax-Ox)+(Ay-Oy)*(Ay-Oy)));
		s1=sqrt(abs((Ax-Bx)*(Ax-Bx)+(Ay-By)*(Ay-By)));
		angle=acos((2*radius*radius-s1*s1)/(2*radius*radius));
		ans=radius*angle;

		printf("Case %d: %.6llf\n",i,ans+1e-7);
		}else printf("Case %d: 0.000000\n",i);
	}

	return 0;
}