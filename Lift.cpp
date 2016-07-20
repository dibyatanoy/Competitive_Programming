#include <stdio.h>

void main(){
	
	int i,t,my_pos,lift_pos,result;

	scanf("%d",&t);

	for(i=1;i<=t;i++){
	
		scanf("%d %d",&my_pos,&lift_pos);

		if(my_pos>lift_pos)
			result = (my_pos-lift_pos) * 4 + my_pos *4 + 9 + 10 ;
		else
			result = (lift_pos-my_pos) * 4 + my_pos *4 + 9 + 10 ;

		printf("Case %d: %d\n",i,result);
	}

}