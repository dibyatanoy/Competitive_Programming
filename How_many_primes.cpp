#include <stdio.h>
#include <math.h>

int main(){

	int testcase,i,a,b,j,root,k,found,count;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		scanf("%d %d",&a,&b);

		count=0;
		found=0;
		if((a%2)==0){
			if(a==2) count++;
			for(j=a+1;j<=b;j=j+2){
				root=(int)sqrt(j)+1;
				for(k=3;k<=root;k++){
					if((j%k)==0){
						found=1;
						break;
					}
					
				}
				if(!found){
					count++;
				
				}
				found=0;
				
			}
		
		}else if(a!=1){
			for(j=a;j<=b;j=j+2){
				root=(int)sqrt(j)+1;
				for(k=3;k<=root;k++){
					if((j%k)==0){
						found=1;
						break;
					}
					
				}
				if(!found)
					count++;
				found=0;
			}
			}else{
				if((a+1)==2 && b>=2) count++;
				for(j=a+2;j<=b;j=j+2){
				root=(int)sqrt(j)+1;
				for(k=3;k<=root;k++){
					if((j%k)==0){
						found=1;
						break;
					}
					
				}
				if(!found)
					count++;
				found=0;
			}
		
		}

		printf("Case %d: %d\n",i,count);
	
	}

	return 0;
}