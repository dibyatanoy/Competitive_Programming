#include <stdio.h>				/*runtime error:why?*/

void main(){

	int number,digits,residue;

	digits=0;
	residue=0;

	scanf("%d",&number);
	residue=number;

	while(residue>0){
	
		residue=residue/10;
		digits++;
	}

	printf("%d\n",digits);

}