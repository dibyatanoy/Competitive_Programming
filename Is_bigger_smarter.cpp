#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int ara[1002],lis[1002],printlis[1002],max_pos=0,no[1002],input[1002];

int pfans(int a){
	if(printlis[a]==-1) printf("%d\n",no[a]);
	else{
		pfans(printlis[a]);
		printf("%d\n",no[a]);
	}
	return 0;
}

int max(int a,int b){
	if(a>b) return a;
	return b;
}

int liss(int n){
	
	if(lis[n]!=-1) return lis[n];
	lis[n]=1;
	for(int i=0;i<n;i++){
		if(ara[i]>ara[n]&&input[i]<input[n]){ 
			if(lis[i]+1>lis[n]){
				lis[n]=lis[i]+1;
				printlis[n]=i;
			}
		}
	}
	if(lis[n]>lis[max_pos]) {max_pos=n;}

	return lis[n];
}


int main(){

	int i,j;


	while(scanf("%d%d",&input[0],&ara[0])==2){
		int k=1;

		while(scanf("%d%d",&input[k],&ara[k])==2){
			k++;
		}

		memset(lis,-1,sizeof(lis));
		memset(printlis,-1,sizeof(printlis));

		for(i=0;i<1002;i++) no[i]=i+1;

		for(i=0;i<k-1;i++){
			for(j=k-1;j>i;j--){
				if(input[j]<input[j-1]){
					int temp=ara[j];
					ara[j]=ara[j-1];
					ara[j-1]=temp;
					
					temp=input[j];
					input[j]=input[j-1];
					input[j-1]=temp;
					temp=no[j];
					no[j]=no[j-1];
					no[j-1]=temp;
				}
			}
		}


		int ans=1;

		for(i=0;i<k;i++){
			ans=max(ans,liss(i));
		}

		printf("%d\n",ans);

		
		pfans(max_pos);
	}

	return 0;


}

/** AC!!! **/