#include <stdio.h>

void main(){

	int test,n,digit,result,i;
	unsigned long int val;
	
	scanf("%d",&test);

	for(i=1;i<=test;i++){
	
		scanf("%d %d",&n,&digit);

		result=1;

		val=digit;

		while((val%n)!=0){
			val=val*10+digit;
			result++;
		}

		printf("Case %d: %d",i,result);
	
	}

}