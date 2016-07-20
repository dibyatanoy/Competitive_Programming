#include <stdio.h>

int main(){

	int testcase,i,marks;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
	
		scanf("%d",&marks);

		if(marks>=80) printf("Case %d: A+",i);
		else if(marks>=75) printf("Case %d: A",i);
		else if(marks>=70) printf("Case %d: A-",i);
		else if(marks>=65) printf("Case %d: B+",i);
		else if(marks>=60) printf("Case %d: B",i);
		else if(marks>=55) printf("Case %d: B-",i);
		else if(marks>=50) printf("Case %d: C",i);
		else if(marks>=45) printf("Case %d: D",i);
		else printf("Case %d: F",i);

		printf("\n");
	}

	return 0;
}