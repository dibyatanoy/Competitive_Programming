#include <stdio.h>

int cycle(int m){

	int length = 1;
	
	while (m!=1){
	
		if (m%2==0)
			m = m/2;
		else
			m = 3*m+1;
		length++;
	}
	return length;

}

void main(){

	int i,j,iOriginal,jOriginal,m,maxCycleLength,temp;

		while (scanf("%d %d",&i,&j)){
			
			iOriginal = i;
			jOriginal = j;

			if (i>j){
				temp = i;
				i=j;
				j = temp;
			
			}

			maxCycleLength = cycle(i);

			for (m= i+1;m<=j;m++){
				temp = cycle(m);
				if (temp > maxCycleLength)
					maxCycleLength = temp;

			}
			printf("%d %d %d\n",iOriginal,jOriginal,maxCycleLength);

		

	
		}

}