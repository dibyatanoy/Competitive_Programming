#include <stdio.h>
#include <math.h>

int main(){

	int testcase,i,r1,r2,c1,c2;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		scanf("%d %d %d %d",&r1,&c1,&r2,&c2);

		printf("Case %d: ",i);

		if(abs(r1-r2)>abs(c1-c2))
			printf("%d",abs(r1-r2));
		else
			printf("%d",abs(c1-c2));

		printf("\n");
	}

	return 0;
}
