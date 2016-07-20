#include <stdio.h>

void main(){

	int num1,num2,total,n,i;

	scanf("%d",&n);

	for(i=1;i<=n;i++){
		
		scanf("%d %d",&num1,&num2);
		total = num1+num2;
		printf("Case %d: %d\n",i,total);
	}
}