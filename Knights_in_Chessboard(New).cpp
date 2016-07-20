#include <stdio.h>

int max(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){

	int testcase,m,n,i,ct1,ct2,ans;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%d %d",&m,&n);

		ans=0;
		if(m>2 && n>2){
			ans = (m*n)/2;
			printf("Case %d: %d\n",i,max(ans,m*n-ans));
		}else if(m==1||n==1)
			printf("Case %d: %d\n",i,max(m,n));
		else if(m==2||n==2){
			m=max(m,n);
			n=2;
			for(ct1=1;ct1<=m;ct1+=2){
				for(ct2=1;ct2<=2 && ct1<=m;ct2++,ct1++){
					ans+=2;
				}
			}
			printf("Case %d: %d\n",i,ans);

		}
	}

	return 0;
}