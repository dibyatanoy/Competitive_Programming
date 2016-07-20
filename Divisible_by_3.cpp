#include <stdio.h>

int main(){

	int testcase,i,input;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		scanf("%d",&input);

		if((input%3)==0) printf("%d is a multiple of 3",input);
		else printf("%d is not a multiple of 3",input);

		printf("\n");
	
	}

	return 0;
}