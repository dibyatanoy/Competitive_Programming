#include <stdio.h>

int summation(int a[],int d,int n){

	int i;
	for(i=0;i<n;i++)
		a[i]=a[i]+d;
	
	return 0;
}

int multiply(int a[],int d,int n){

	int i;
	for(i=0;i<n;i++)
		a[i]=a[i]*d;

	return 0;
}

int divide(int a[],int d,int n){

	int i;
	for(i=0;i<n;i++)
		a[i]=a[i]/d;

	return 0;
}

int position(int a[],int y,int z,int n){

	int temp=0;
	
	temp=a[y];
	a[y]=a[z];
	a[z]=temp;
	
	return 0;
}

void reverse(int a[], int n){

	int i,temp=0;

	for(i=0;i<(n/2);i++){
		a[i]=temp;
		a[i]=a[n-1-i];
		a[n-1-i]=temp;
	}
}

void print_res(int a[],int t,int n){

	int i;

	printf("Case %d:\n",t);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}

void main(){

	int array[100],t,n,m,d,y,z,count1,count2;
	char operation;

	scanf("%d",&t);

	for(count1=1;count1<=t;count1++){
		
		scanf("\n%d %d",&n,&m);

		for(count2=0;count2<n;count2++)
			scanf("%d",&array[count2]);

		for(count2=0;count2<m;count2++){
			
			scanf("%s", operation);
			if(operation=='R')
				reverse(array,n);
			else if(operation=='P'){
				scanf("%d %d",&y,&z);
				position(array,y,z,n);
			}else{
				scanf("%d",&d);
			}

			if(operation=='S')
				summation(array,d,n);
			if(operation=='M')
				multiply(array,d,n);
			if(operation=='D')
				divide(array,d,n);
			
		}

		print_res(array,t,n);
	}

}