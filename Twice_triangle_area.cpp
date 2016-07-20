#include <stdio.h>

int main(){

	int testcase,i,base,ht;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		scanf("%d %d",&base,&ht);

		printf("Case %d: %d\n",i,base*ht);
	}

	return 0;
}