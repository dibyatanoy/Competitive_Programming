#include <stdio.h>

long int array[100];

void add(int d,int n){
	int l;
	for(l=0;l<n;l++)
		array[l]+=d;
}

void mult(int d,int n){
	int l;
	for(l=0;l<n;l++)
		array[l]*=d;
}

void div(int d, int n){
	int l;
	for(l=0;l<n;l++)
		array[l]/=d;
}

void swap(int y,int z){
	int temp;
	temp=array[y];
	array[y]=array[z];
	array[z]=temp;
}

void reverse(int n){
	int k=0;
	n--;

	for(k=0;k<n;k++,n--){
		swap(k,n);
	}
}

int main(){

	int testcase,i,d,k,y,z,n,m,j;
	char com[2];
	

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		
		scanf("%d %d",&n,&m);

		for(j=0;j<n;j++)
			scanf("%ld",&array[j]);
		
		for(j=1;j<=m;j++){
			scanf("%s",com);
			if(com[0]=='S'){
				scanf("%d",&d);
				add(d,n);
			}else if(com[0]=='M'){
				scanf("%d",&d);
				mult(d,n);
			}else if(com[0]=='D'){
				scanf("%d",&k);
				div(k,n);
			}else if(com[0]=='P'){
				scanf("%d %d",&y,&z);
				swap(y,z);
			}else{
				reverse(n);
			}


		}
		
		printf("Case %d:\n%ld",i,array[0]);

		for(j=1;j<n;j++)
			printf(" %d",array[j]);

		printf("\n");
		

		
	}

	return 0;
}

/** AC!!! **/