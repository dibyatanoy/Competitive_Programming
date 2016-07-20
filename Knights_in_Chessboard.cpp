#include <stdio.h>

void main(){

	int i,t,m,n,ans;

	scanf("%d",&t);

	for(i=1;i<=t;i++){
	
		scanf("%d %d",&m,&n);

		ans=(m*n)/2;

		if(((m*n)%2)!=0)
			ans++;

		printf("Case %d: %d\n",i,ans);
	}

}