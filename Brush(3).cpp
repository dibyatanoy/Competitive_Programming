#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;


long int dp[104][1004];
long int dusts[104],maxim;
int dust_no[104];
int j;
int width,k;

int maximum(int a,int b){
	if(a>b) return a;
	return b;
}

int dust_pt(int i){
	int ans=0;
	for(int l=i;l<maxim;l++){
		if(dusts[l]>dusts[i]+width) break;
		ans+=dust_no[l];
	}

	return ans;
}

int find_next_level(int i){
	
	for(int n=i+1;n<maxim;n++){
		if(dusts[n]>dusts[i]+width)
			return n;
	}
	return maxim;
}

int call(int i,int moves){
	
	if(i>maxim) return 0;
	if(dp[i][moves]!=-1) return dp[i][moves];
	if(moves>=k) return 0;

	int gain1=0,gain2=0;

	if(moves<k){
		gain1=call(find_next_level(i),moves+1)+dust_pt(i);
		gain2=call(i+1,moves);
	} 

	

	dp[i][moves]=maximum(gain1,gain2);
	return dp[i][moves];
}

int main(){

	int testcase,n,i,found;
	long int y,min=1000000001,x;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%d%d%d",&n,&width,&k);
		j=0;found=0;
		
		memset(dusts,0,sizeof(dusts));
		memset(dust_no,0,sizeof(dust_no));
		
		for(int m=0;m<n;m++){
			scanf("%ld %ld",&x,&y);
			for(int k=0;k<j;k++){
				if(dusts[k]==y){
					dust_no[k]++;
					found=1;
					break;
				}
			}

			if(!found){
				dusts[j]=y;
				dust_no[j]++;
				j++;
			}
			found=0;
			
			if(y<min) min=y;
			
		}
		maxim=j;

		memset(dp,-1,sizeof(dp));
		for(int z=0;z<maxim-1;z++){
			for(int cnt=maxim-1;cnt>z;cnt--){
				if(dusts[cnt]<dusts[cnt-1]){
					/*printf("Swapping %d with %d",dusts[cnt],dusts[cnt-1]);*/
					int temp=dusts[cnt];
					dusts[cnt]=dusts[cnt-1];
					dusts[cnt-1]=temp;
					temp=dust_no[cnt];
					dust_no[cnt]=dust_no[cnt-1];
					dust_no[cnt-1]=temp;
				}
			}
		}

		
		int ans=call(0,0);
		

		printf("Case %d: %d\n",i,ans);
		
	}

	return 0;
}

/** AC!!! **/