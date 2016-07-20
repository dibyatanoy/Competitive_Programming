#include <stdio.h>

void main(){

	int t,n,ans1=0,ans2=0;

	scanf("%d",&t);

	while(t--){
		
		scanf("%d",&n);
		if(n>10){
			ans1 = 10;
			ans2 = n-10;
		}else{
			ans1=n;
			ans2 = 0;

		}

		printf("%d %d\n",ans1,ans2);
	}
}