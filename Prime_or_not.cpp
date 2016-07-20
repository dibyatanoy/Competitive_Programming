#include <stdio.h>
#include <math.h>

int main(){
	long long int number,i,count;
	int found,testcase,j;

	scanf("%d",&testcase);

	for(j=0;j<testcase;j++){
		
		scanf("%lld",&number);
		found=0;
		count=(int)sqrt(number)+1;
		
		for(i=2;i<=count;i++){
			if((number%i)==0 && number!=2){
				found=1;
				printf("%lld is not a prime\n",number);
				break;
			}
		}

		if(!found)
			printf("%lld is a prime\n",number);
	}

	return 0;
}