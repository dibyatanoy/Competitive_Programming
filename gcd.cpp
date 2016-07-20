#include <stdio.h>
#include <iostream.h>

void gcd(int u,int v){

	int temp;

	while (v!=0){
		temp = u%v;
		u=v;
		v = temp;
	
	}

	printf("Greatest Common Divisor = %d\n",u);

}

void main(){

	int input1,input2;
	printf ("Enter two numbers at a time and press 'Enter'\n");
	while (scanf("\n%d %d",&input1,&input2) && input1>0 && input2>0){
		
		gcd(input1, input2);
	}
	

}