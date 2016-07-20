#include <stdio.h>
#include <conio.h>

void main(){

	int i,j,array[66],temp,n,k;
	scanf("%d\n",&n);

	for (k=0;k<n;k++){
		scanf("%d ",&array[k]);
	}

	for (i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if (array[j]<array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			
			}
		}
	}

	printf("\n");
	for (i=0;i<n;i++){
		printf("%d ",array[i]);
	}
	}