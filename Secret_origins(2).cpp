#include <stdio.h>

int main(){
	
	int testcase,i,length1,length2,found;
	long int num,temp,j;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%ld",&num);
		temp=num;

		length1=0;length2=0;found=0;

		while(num!=0){
			if((num%2)==1) length1++;
			num=num/2;
		}

		for(j=temp+1;;j++){
			num=j;length2=0;
			while(num!=0){
				if((num%2)==1) length2++;
				num=num/2;
				if(length2>length1) break;
			}

			if(length2==length1) break;

		}
		printf("Case %d: %ld\n",i,j);
	}
	
	return 0;
}