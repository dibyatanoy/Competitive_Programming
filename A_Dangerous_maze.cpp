#include <stdio.h>

int GCD(int u,int v){

	int temp;

	while (v!=0){
		temp = u%v;
		u=v;
		v = temp;
	
	}

	return u;
}

int main(){

	int testcase,i,j,sum_times,returns,n,times[100],denom,gcd;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%d",&n);
		sum_times=0;returns=0;

		for(j=0;j<n;j++) scanf("%d",&times[j]);

		for(j=0;j<n;j++){
			if(times[j]>0) sum_times+=times[j];
			else{
				sum_times-=times[j];
				returns++;
			}
		}

		if(returns==n){
			printf("Case %d: inf\n",i);
		}else{
			sum_times=sum_times;
			denom=n-returns;
			gcd=GCD(sum_times,denom);
			printf("Case %d: %d/%d\n",i,sum_times/gcd,denom/gcd);
			
		}
	}

	return 0;
}

/* AC!!! By the way, how is this DP?? **/