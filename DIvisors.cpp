#include <stdio.h>

int main(){

	int testcase,i,n,j;	

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		scanf("%d",&n);

		printf("Case %d:",i);

		for(j=1;j<=n;j++)
			if((n%j)==0) printf(" %d",j);

		printf("\n");
	}

	return 0;
}