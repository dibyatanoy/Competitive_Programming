#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define MAXX 100010
#define minim(a,b) (a<b)? a:b
#define maxim(a,b) ((a)>(b))? (a):(b)

using namespace std;
char seq[MAXX];
long long int dp[26];

int main(){

	int kases,i,j;
	scanf("%d",&kases);

	while(kases--){
		scanf("%s",seq);
		memset(dp,0,sizeof(dp));

		int curr;
		long long int ans=0;
		long long int temp,prev=0;
		int l=strlen(seq);
		for(i=0;i<l;i++){
			temp=0;
			curr=seq[i]-'A';
			
			temp+=prev;
			temp%=1000000007;
			temp++;
			long long int del=dp[curr];
			if(temp<del){
				temp+=1000000007;
				
			}
			temp-=del;
			//printf("%d\n",temp);
			temp%=1000000007;
			ans+=temp;
			//printf("%d\n",ans);
			ans%=1000000007;
			prev+=temp;
			prev%=1000000007;
			dp[curr]+=temp;
			dp[curr]%=1000000007;
		}

		printf("%lld\n",ans+1);

	}

	return 0;
}