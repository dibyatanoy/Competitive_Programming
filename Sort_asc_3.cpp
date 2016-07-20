#include <stdio.h>

int main(){

	int testcase,c,d,i,a[3],swap;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		scanf("%d %d %d",&a[0],&a[1],&a[2]);

		for(c=0;c<2;c++){
			for(d=0;d<2-c;d++){
			
				if(a[d]>a[d+1]){
				
					swap=a[d];
					a[d]=a[d+1];
					a[d+1]=swap;
				}
			}
		
		}

		printf("Case %d: %d %d %d\n",i,a[0],a[1],a[2]);
	
	}

	return 0;
}