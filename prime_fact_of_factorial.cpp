#include <stdio.h>
#include<math.h>

int find_prime_fact(int i,int ans[],int primes[]){

	int root;

	for(j=0;j<=24;j++){
		if(i==primes[j]){
			ans[primes[j]]++;
			return 0;
		}
	}

	

}

int main(){

	int number,primes[25],ans[98],i;

	primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

	for(i=0;i<98;i++) ans[i]=0;

	scanf("%d",&number);

	for(i=2;i<=number;i++){
		
		find_prime_fact(i,ans[],primes[]);
	
	}

	print_ans();

	return 0;
}