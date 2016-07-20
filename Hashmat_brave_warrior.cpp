#include <stdio.h>

void main(){
	
	long int num1,num2,diff;
	
	while(scanf("%ld %ld",&num1,&num2)){
		
		if(num1>num2)
			diff = num1 - num2;
		else
			diff = num2 - num1;

		printf("%ld\n",diff);
		
	}


}