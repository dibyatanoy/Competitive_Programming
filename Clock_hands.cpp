#include <stdio.h>

void main(){
	
	float num1,num2;
	float angle,min_pos;

	scanf("%f:%f",&num1,&num2);

	while(!((num1==0) && (num2==0))){
		
		min_pos = num2/5;
		num1+= num2/60*1;
		if(min_pos>num1)
			angle = (min_pos-num1)*30;
		else
			angle = (num1-min_pos)*30;

		if(angle>180)
			angle = 360 - angle;
		
		printf("%.3f\n",angle);
		scanf("%f:%f",&num1,&num2);

	
	
	}


}