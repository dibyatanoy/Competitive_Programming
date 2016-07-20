#include <stdio.h>

int main(){

	int testcase,i,n,digit,rem,res,j;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		scanf("%d %d",&n,&digit);

		res=1;

		rem=digit%n;

		j=digit;

		while(rem!=0){
			digit=digit*10+j;
			rem=digit%n;
			res++;
			
		}

		printf("Case %d: %d\n",i,res);
	
	}

	return 0;
}