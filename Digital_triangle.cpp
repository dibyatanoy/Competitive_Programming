#include <stdio.h>

int main(){

	int testcase,i,j,k,digit,h;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		scanf("%d %d",&digit,&h);

		printf("Case %d:\n",i);

		for(j=1;j<=h;j++){
		
			for(k=1;k<=j;k++) printf("%d",digit);

			printf("\n");
		}

	}
	return 0;
}