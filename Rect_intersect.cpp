#include <stdio.h>

int main(){

	int testcase,i,Ax1,Ay1,Ax2,Ay2,Bx1,By1,Bx2,By2;
	int no_intersect=0;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		scanf("%d %d %d %d",&Ax1,&Ay1,&Ax2,&Ay2);
		scanf("%d %d %d %d",&Bx1,&By1,&Bx2,&By2);
		
		printf("Case %d: ",i);
		if(Bx1>=Ax2||Ay2<By1||Ax1>Bx2||By2<=Ay1)
			no_intersect=1;
		else
			no_intersect=0;

		if(no_intersect) printf("No");
		else printf("Yes");

		printf("\n");

	
	}

	return 0;
}