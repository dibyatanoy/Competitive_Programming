#include <stdio.h>

void main(){

	int t,i;
	long int a,b,c;

	scanf("%d",&t);

	for(i=1;i<=t;i++){
	
		scanf("%d %d %d",&a,&b,&c);
		if(c*c==a*a-b*b)
			printf("Case %d: yes\n",i);
		else if(c*c==b*b-a*a)
			printf("Case %d: yes\n",i);
		else if(b*b==a*a-c*c)
			printf("Case %d: yes\n",i);
		else if(b*b==c*c-a*a)
			printf("Case %d: yes\n",i);
		else if(a*a==b*b-c*c)
			printf("Case %d: yes\n",i);
		else if(a*a==c*c-b*b)
			printf("Case %d: yes\n",i);
		else
			printf("Case %d: no\n",i);
	}
}