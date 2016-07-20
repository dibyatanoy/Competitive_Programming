#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>


int N;
bool taken[22];
int stones[21];

using namespace std;

double min(double a,double b){

	if(a<b) return a;
	return b;
}

int call(int l,int r,int i){
	if(i==N){if(l>r) return (l-r);else return(r-l);}

	return min(call(l+stones[i],r,i+1),call(l,r+stones[i],i+1));
}

int main(){

	int sum=0;

	scanf("%d",&N);
	memset(taken,0,sizeof(taken));

	for(int i=0;i<N;i++){
		scanf("%d",&stones[i]);
	}
	double ans;
	ans=call(0,0,0);

	printf("%.lf\n",ans);

	return 0;
}

/** AC!!! **/
