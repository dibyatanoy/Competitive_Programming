#include <stdio.h>

int max(int a,int b){
	if(a>b) return a;
	return b;
}

int min(int a,int b){
	if(a<b) return a;
	return b;
}


int main(){

	int testcase,i,j,gold[100],n,k,end;
	double prob[100],res;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%d",&n);

		for(j=0;j<n;j++)
			scanf("%d",&gold[j]);

		prob[0]=1;
		res=gold[0];

		for(j=1;j<n;j++){
			prob[j]=0;
			for(k=max(0,j-6);k<j;k++){
				end=min(n-1,k+6);
				prob[j]+=(double)prob[k]/(end-k);
			}
			res+=(double)prob[j]*gold[j];
		}

		printf("Case %d: %.8lf\n",i,res);
	}

	return 0;
}

/* AC!!!! */