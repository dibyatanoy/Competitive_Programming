#include <stdio.h>
#include <math.h>

void main(){

	int t,row,col,intsqr,placeholder;
	unsigned long int s;
	float sqroot;

	scanf("&ld",&s);

	sqroot=sqrt(s);
	intsqr=sqroot;

	if((sqroot-intsqr)!=0){
		if((sqroot-intsqr)<0.5)
			col=intsqr+1;
		else 
			row=intsqr+1;

	}

	placeholder=intsqr*(intsqr-1)+1;
	placeholder=s-placeholder;




}