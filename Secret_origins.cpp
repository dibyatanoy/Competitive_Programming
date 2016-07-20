#include <stdio.h>
#include <math.h>

int main(){
	
	int testcase,i,n,mod,found;
	long int num,temp;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%ld",&num);

		n=0;temp=num;found=0;
		while(temp!=0 && found==0){
			mod=temp%2;
			temp=temp/2;
			if(mod==1){
				if((temp%2)==0){
					found=1;
					break;	
				}
			}
			n++;
		}

		num=num+pow(2,n+1)-pow(2,n);
		printf("Case %d: %ld\n",i,num);
	}
	
	return 0;
}