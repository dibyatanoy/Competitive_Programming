#include <stdio.h>

void main(){

	int rem,divident,t,i,parity;

	scanf("%d",&t);

	for(i=1;i<=t;i++){
		
		parity=0;
		scanf("%d",&divident);

		while(divident!=0){
			
			rem=divident%2;
			if(rem==1) parity++;
			divident=divident/2;

		}

		if(parity%2==0)
			printf("Case %d: even\n",i);
		else
			printf("Case %d: odd\n",i);
	
	}
}