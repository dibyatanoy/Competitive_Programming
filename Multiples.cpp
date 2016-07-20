#include <stdio.h>

int main(){

	int testcase,i,number,range,j;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		j=1;
		scanf("%d %d",&number,&range);

		printf("Case %d: ",i);
		while((number*j)<=range){
			printf("%d ",number*j);
			j++;
		}

		printf("\n");
	
	
	}
	return 0;
}