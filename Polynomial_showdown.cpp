#include <stdio.h>

int main(){

	int coeff[9],i,started,null;

	while(1==scanf("%d",&coeff[0])){
	
		for(i=1;i<9;i++)
			scanf("%d",&coeff[i]);

		started=0;
		null=1;
		for(i=0;i<9;i++){
			if(coeff[i]!=0){
				null=0;
				if(coeff[i]<0){
					if(!started){
						if(coeff[i]==-1){
							if(i==8)
								printf("-1");
							else if(i==7)
								printf("-x");
							else
								printf("-x^%d",8-i);
						}else{
							if(i==8)
								printf("%d",coeff[i]);
							else if(i==7)
								printf("-%dx",-coeff[i]);
							else
								printf("-%dx^%d",-coeff[i],8-i);

						}

						started=1;
					}else{
					
						if(started) printf(" ");
						if(coeff[i]==-1){
							if(i==8)
								printf("- 1");
							else if(i==7)
								printf("- x");
							else
								printf("- x^%d",8-i);
						}else{
							if(i==8)
								printf("- %d",-coeff[i]);
							else if(i==7)
								printf("- %dx",-coeff[i]);
							else
								printf("- %dx^%d",-coeff[i],8-i);
						}
					
					
					}

				}else{
				
					if(!started){
						if(coeff[i]==1){
							if(i==8)
								printf("1");
							else if(i==7)
								printf("x");
							else
								printf("x^%d",8-i);
						}else{
							if(i==8)
								printf("%d",coeff[i]);
							else if(i==7)
								printf("%dx",coeff[i]);
							else
								printf("%dx^%d",coeff[i],8-i);
						
						}

						started=1;
					
					}else{
						if(started) printf(" ");
						if(coeff[i]==1){
							if(i==8)
								printf("+ 1");
							else if(i==7)
								printf("+ x");
							else
								printf("+ x^%d",8-i);
						}else{
							if(i==8)
								printf("+ %d",coeff[i]);
							else if(i==7)
								printf("+ %dx",coeff[i]);
							else
								printf("+ %dx^%d",coeff[i],8-i);
						}
					}
				
				}
			
			
			}
		
		}
	
	if(null) printf("0");
	printf("\n");
	}

	return 0;
}