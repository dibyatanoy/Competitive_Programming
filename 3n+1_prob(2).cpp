#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

int dp[1000002];
int cycle(long long int m){

	if(m==1) return 1;
	if(m<1000001 && dp[m]!=-1) return dp[m];

	int length;
	
	if (m%2==0)
		length= cycle(m/2)+1;
	else
		length= cycle(3*m+1)+1;

	return (m<1000001)? dp[m]=length:length;

}

int main(){

	int i,j,iOriginal,jOriginal,m,maxCycleLength,temp;
	memset(dp,-1,sizeof(dp));

		while (scanf("%d %d",&i,&j)==2){
			
			iOriginal = i;
			jOriginal = j;

			if (i>j){
				temp = i;
				i=j;
				j = temp;
			
			}

			maxCycleLength = cycle(i);

			for (m=i+1;m<=j;m++){
				temp = cycle(m);
				if (temp > maxCycleLength)
					maxCycleLength = temp;

			}
			printf("%d %d %d\n",iOriginal,jOriginal,maxCycleLength);

		

	
		}
	return 0;
}

/** AC!!! After 1.5 yrs :) **/