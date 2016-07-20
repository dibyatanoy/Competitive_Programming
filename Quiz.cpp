#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cstdlib>
#include <cmath>
#define MOD 


using namespace std;

int main(){

	int n,m,d;
	scanf("%d %d %d",&n,&m,&d);

	int i,j,places;
	int ans=0;

	if(n>d){
		ans=1;
		places=ceil((double)(n)/double(d));

		int cons= (m>places)? m-places*(d-1):0;


		for(i=1;i<=cons;i++){
			ans*=2;
			ans%=1000000009;
		}
		ans=(ans-1)%1000000009;
		ans*=2;
		ans%=1000000009;
		ans*=d;
		ans%=1000000009;

		ans+=m-cons*d;
		ans%=1000000009;
	}else if(n<d){
		ans=m;
	}else{
		if(n==m) ans=m*2;
		else ans=m;
	}
	printf("%d\n",ans);

	return 0;
}