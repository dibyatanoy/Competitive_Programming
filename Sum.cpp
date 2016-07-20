#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	
	int N,ans;

	scanf("%d",&N);

	if(N>=1){
		ans=N*(N+1)/2;
	}else if(N<0){
		ans=1+N*(-N+1)/2;
	}else ans=1;

	printf("%d\n",ans);
	
	return 0;
}