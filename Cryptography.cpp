#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(){
	int testcases,num[200000],i,j,term;
	vector<int> primes;

	memset(num,0,sizeof(num));
	for(i=2;i<200000;i++){
		if(num[i]==0){
			for(j=2;i*j<200000;j++){
				num[i*j]=1;
			}
			primes.push_back(i);
		}
	}

	scanf("%d",&testcases);
	while(testcases--){
		scanf("%d",&term);
		printf("%d\n",primes[term-1]);
		
	}
	return 0;
}

/** AC!!! **/