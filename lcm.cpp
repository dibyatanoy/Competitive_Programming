#include <stdio.h>
#include <iostream.h>

void lcm(int u,int v){

	int temp,lcm,product;
	product = u*v;

	while (v!=0){
		temp = u%v;
		u=v;
		v = temp;
	
	}

	lcm = product/u;

	printf("Least common multiple = %d\n",lcm);

}

void main(){

	int input1,input2;
	printf ("Enter two numbers at a time and press 'Enter'\n");
	while (scanf("\n%d %d",&input1,&input2) && input1>0 && input2>0){
		
		lcm(input1, input2);
	}
	

}