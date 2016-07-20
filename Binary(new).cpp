#include <stdio.h>

int recursive_pt(int k,int n,int array[11]){

	int j;
	if(k==n){
		array[k]=1;
		recursive_pt(k-1,n,array);
	}else if(k==0){
		for(j=n;j>0;j--)
			printf("%d",array[j]);

		printf("\n");
	}else{
		array[k]=0;
		recursive_pt(k-1,n,array);
		array[k]=1;
		recursive_pt(k-1,n,array);
	}

	return 0;
}

int main(){

	int testcase,k,n,i,array[11];

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		
		scanf("%d",&n);
		k=n;
		
		if(n==1){
			printf("0\n1\n");
		}else{
			recursive_pt(k,n,array);
		}
	}

	return 0;
}