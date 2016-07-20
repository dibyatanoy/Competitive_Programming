#include<stdio.h>

int main(){

	int testcase,i,a,b,c;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		scanf("%d %d %d",&a,&b,&c);

		printf("Case %d: ",i);
		if(a==0 && b==0 && c==0)
			printf("Arithmetic Progression");
		else if((b-a)==(c-b)){
			if(a!=0 && b!=0 && c!=0 && (b*b)==(a*c))
				printf("Both");
			else
				printf("Arithmetic Progression");
		
		}else if((a!=0) && (b!=0) && (c!=0) && (b*b)==(a*c))
			printf("Geometric Progression");
		else
			printf("None");

		printf("\n");
	
	
	}

	return 0;
}