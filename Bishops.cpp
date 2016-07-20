#include<stdio.h>
#include <math.h>

int main(){

	int testcase,i;
	long int r1,c1,r2,c2;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%ld %ld %ld %ld",&r1,&c1,&r2,&c2);

		if(abs((r1%2-c1%2))!=abs((r2%2-c2%2)))
			printf("Case %d: impossible\n",i);
		else if(abs(r1-r2)==abs(c1-c2))
			printf("Case %d: 1\n",i);
		else
			printf("Case %d: 2\n",i);
	}

	return 0;
}

/** AC!!! **/