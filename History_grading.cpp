#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int count,ara[22],lis[22];

int max(int a,int b){
	if(a>b) return a;
	return b;
}

int liss(int n){
	
	if(lis[n]!=-1) return lis[n];
	lis[n]=1;
	for(int i=0;i<n;i++){
		if(ara[i]<ara[n]&&ara[i]!=-1&&ara[n]!=-1) lis[n]=max(lis[n],lis[i]+1);
	}

	return lis[n];
}


int main(){

	int N,input[22],i,j,input2[22];

	scanf("%d",&N);

	for(i=0;i<N;i++) scanf("%d",&input[i]);


	while(scanf("%d",&ara[0])==1){
		for(i=1;i<N;i++) scanf("%d",&ara[i]);
		
		count=0;
		/*for(i=0;i<N;i++){
			if(ara[i]==input[i]){
				count++;
				ara[i]=-1;
			}
		}*/
		memset(lis,-1,sizeof(lis));
		for(i=0;i<N;i++) input2[i]=input[i];

		for(i=0;i<N-1;i++){
			for(j=N-1;j>i;j--){
				if(input2[j]<input2[j-1]&&ara[j]!=-1&&ara[j-1]!=-1){
					int temp=ara[j];
					ara[j]=ara[j-1];
					ara[j-1]=temp;
					
					temp=input2[j];
					input2[j]=input2[j-1];
					input2[j-1]=temp;
				}
			}
		}


		int ans=1;

		for(i=0;i<N;i++){
			if(ara[i]!=-1) ans=max(ans,liss(i));
		}

		printf("%d\n",ans);
	}

	return 0;


}

/** AC!!! **/