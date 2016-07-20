#include <stdio.h>

void main(){

	int i,cases,people,total=0,temp;

	scanf("%d",&cases);
	
	for(i=1;i<=cases;i++){
	
		scanf("%d",&people);
		total =0;

		while(people--){
			scanf("%d",&temp);
			total+=temp;
		}

		printf("Case %d: %d\n",i,total);
	}

}