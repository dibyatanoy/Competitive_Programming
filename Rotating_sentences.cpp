#include <stdio.h>

char sentences[100][100],inputchar;
int i,count,length[100],n,row,col,start_add,max,max_length=0;

int find_max(){
	for(count=0;count<100;count++){
		if(length[count]>max)
			max=length[count];
	}
	return max;
}


void input_data(){

	row=0;
	col=99;

	while(scanf("%c",&inputchar)==1){
		while(inputchar!='\n'){
			sentences[row][col]=inputchar;
			row++;
			scanf("%c",&inputchar);
		}
		
		if(inputchar=='\n'){
			length[col]=row;
			row=0;
			col--;
		}
	}
	start_add=col;
}

void print_result(){
	max_length=find_max();
	for(i=0;i<=max_length;i++){
		for(n=start_add;n<=99;n++){
			if((sentences[i][n])!='*')
				printf("%c",sentences[i][n]);
		}
		printf("\n");
	}

}


void initialize_arrays(){

	for(n=0;n<100;n++)
		length[n]=0;

	for(row=0;row<100;row++){
		for(col=0;col<100;col++)
			sentences[row][col]='*';
	}

}

void main(){

	initialize_arrays();
	input_data();
	print_result();
}