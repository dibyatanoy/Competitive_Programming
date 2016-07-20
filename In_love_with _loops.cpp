#include <stdio.h>

int main(){

	int testcase,i,j,k,l,a,b,c;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		scanf("%d %d %d",&a,&b,&c);
	
		printf("Case %d:\n",i);

		for(j=0;j<=a;j++){
			for(k=1;k<=b;k++){
				if(k>j){
					for(l=2;l<=c;l++){
						if(l>k)
							printf("%d %d %d\n",j,k,l);
					}
				}
			}
		
		}

	}

	return 0;
}
