#include <stdio.h>

int main(){

	int testcase,i,a,b,c,both=0,done=0;
	double ratio1,ratio2,large,small;
	

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		
		scanf("%d %d %d",&a,&b,&c);

		printf("Case %d: ",i);

		if(a==0 && b==0 && c==0){ 
			printf("Arithmetic Progression");
			done=1;
		}else if((b-a)==(c-b)){
			if(a!=0 && b!=0 && c!=0){ 
				ratio1=(double)b/a;
				ratio2=(double)c/b;
				if (ratio2>ratio1){
					large=ratio2;
					small=ratio1;
				}else{
					large=ratio1;
					small=ratio2;
				}
				
				if((large-small)<0.00000001){
					printf("Both");
					both=1;
					done=1;
				}
			}
			/*printf("Reached check 1");*/
			if(both==0){
				printf("Arithmetic Progression");
				done=1;
			}

		}else if(a!=0 && b!=0 && c!=0){
				ratio1=(double)b/a;
				ratio2=(double)c/b;
				if (ratio2>ratio1){
					large=ratio2;
					small=ratio1;
				}else{
					large=ratio1;
					small=ratio2;
				}
				/*printf("Reached check 2");*/

				if((large-small)<0.00000001){
					printf("Geometric Progression");
					done=1;
				}
			
		} 
		if(done==0) printf("None");

		printf("\n");
	
	}

	return 0;
}