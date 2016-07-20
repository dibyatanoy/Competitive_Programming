#include <stdio.h>

int main(){

	int testcase,i,N,j;
	long int money,account;
	char action[10];

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%d",&N);

		account=0;
		
		printf("Case %d:\n",i);
		for(j=1;j<=N;j++){
			scanf("%s",action);
			
			
			if(action[0]=='d'){
				scanf("%ld",&money);
				account+=money;
			}else if(action[0]=='r'){
					printf("%ld\n",account);
				
			}
		}
	}

	return 0;
}

/** AC!!! *//