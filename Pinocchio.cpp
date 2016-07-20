#include <stdio.h>

int main(){

	int testcase,i,num,largest,cnt,lengths;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	 
		largest=2;cnt=0;
		scanf("%d",&lengths);

		while(lengths--){
		scanf("%d",&num);
		if(num>largest){
			if((num-largest)%5==0){
				cnt+=(num-largest)/5;
			}else{
				cnt+=(num-largest)/5+1;
			}
			largest=num;
			
		}
		}

		printf("Case %d: %d\n",i,cnt);
	}

	return 0;
}

/** AC!!! **/