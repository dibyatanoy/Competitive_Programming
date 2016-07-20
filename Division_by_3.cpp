#include <stdio.h>						/*time limit exceeded*/

void main(){

	int a,i,b,total,result,t,count,count2;

	scanf("%d",&t);

	for(i=1;i<=t;i++){
		total = 0;
		result = 0;
		scanf("%d %d",&a,&b);
		for(count=1;count<a;count++)
			total+=count/10+count%10;

		for(count2=a;count2<=b;count2++){
			
			total+=count2/10+count2%10;
			if(total%3==0)
				result++;
		}

		printf("Case %d: %d\n",i,result);
	
	}


}