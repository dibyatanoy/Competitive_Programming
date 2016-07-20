#include <stdio.h>
#include <iostream.h>
#include <math.h>

int possible(int people,int coco){

	int mod,x,i,tf=0,n,escape=0;
	mod=coco;
	n=people;

	for(i=0;i<n;i++){
		
		x=mod%people;
		if(x!=1)
			break;
		
		mod = mod-1;
		mod = (n-1)/n * mod;
		if(i==n-1){
			if(mod%people == 0){
				tf=1;
				break;
			}
		
		}
		
	}

	if (tf==1)
		return (1);
	else
		return(0);
}

void main(){

	int k,coconuts,peoplemax,valid=0;
	scanf("%d",&coconuts);

	while(coconuts>-1){
	peoplemax = sqrt(coconuts)+1;

	for (k=peoplemax;k>=1;k--){
		if(possible(k,coconuts)==1){
			printf("\nThe solution for %d coconuts is %d people and 1 monkey.\n",coconuts,k);
			valid = 1;
			break;
		}
	}
	

	if(!valid)
		printf("\nThere is no solution.\n");

	scanf("%d",&coconuts);
	}

}