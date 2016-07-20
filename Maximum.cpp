#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(){
	
	int n,seq[100050],max[100050],last_max=1;
	int i;

	seq[0]=0;
	seq[1]=1;
	max[1]=1;
	for(i=2;i<=99999;i++){
		if(i%2==0) seq[i]=seq[i/2];
		else seq[i]=seq[(i-1)/2]+seq[(i-1)/2+1];
		if(seq[i]>last_max){
			last_max=seq[i];
		}
		max[i]=last_max;
	}

	while(scanf("%d",&n)&&n!=0){
		printf("%d\n",max[n]);
	}

	return 0;
}

/** AC!!! **/