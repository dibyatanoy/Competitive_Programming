#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

long int fact(int n,int k){
	
	if(n<=0) return 1;
	return n*fact(n-k,k);
}

int main(){

	int n,k=0;
	char brackets[24];

	scanf("%d",&n);
	getchar();
	scanf("%s",brackets);
	k=strlen(brackets);

	if(n<=k) printf("%d\n",n);
	else printf("%ld\n",fact(n,k));
	

	return 0;
}

/** AC!!! **/