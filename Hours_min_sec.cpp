#include <stdio.h>

int main(){

	int testcase,i;
	long int time,rem;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		scanf("%ld",&time);
		rem=time;
		
		printf("Case %d: ",i);
		if((time/31104000)!=0){
			if((time/31104000)==1) printf("1 year ");
			else printf("%d years ",time/31104000);
			rem=time%31104000;
		}

		if((rem/2592000)!=0){
			if((rem/2592000)==1) printf("1 month ");
			else printf("%d months ",rem/2592000);
			rem=rem%2592000;
		}

		if((rem/86400)!=0){
			if((rem/86400)==1) printf("1 day ");
			else printf("%d days ",rem/86400);
			rem=rem%86400;
		}

		if((rem/3600)!=0){
			if((rem/3600)==1) printf("1 hour ");
			else printf("%d hours ",rem/3600);
			rem=rem%3600;
		}

		if((rem/60)!=0){
			if((rem/60)==1) printf("1 minute ");
			else printf("%d minutes ",rem/60);
			rem=rem%60;
		}

		if (rem!=0){
			if (rem==1) printf("1 second ");
			else printf("%d seconds ",rem);
		}

		printf("\n");
	
	}


	return 0;
}