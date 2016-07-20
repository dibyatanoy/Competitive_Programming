#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct data{
	int ht;
	int max_ht;

};

int cow_no;
int dp[200010];
int ht_now[200010];
vector <data> cows;
int maxim;

int main(){
	
	int i,j,k,temp;
	scanf("%d",&cow_no);

	for(i=0;i<cow_no;i++){data u;
	scanf("%d %d",&u.ht,&u.max_ht);
	cows.push_back(u);
	}

	for(i=0;i<cow_no;i++){
		for(j=1;j<cow_no;j++){
			if(cows[j].ht<cows[j-1].ht){
				temp=cows[j].ht;
				cows[j].ht=cows[j-1].ht;
				cows[j-1].ht=temp;
				temp=cows[j].max_ht;
				cows[j].max_ht=cows[j-1].max_ht;
				cows[j-1].max_ht=temp;
			}else if(cows[j].ht==cows[j-1].ht&&cows[j].max_ht<cows[j-1].max_ht){
				temp=cows[j].ht;
				cows[j].ht=cows[j-1].ht;
				cows[j-1].ht=temp;
				temp=cows[j].max_ht;
				cows[j].max_ht=cows[j-1].max_ht;
				cows[j-1].max_ht=temp;
			}
		}
	}
	for(i=0;i<cow_no;i++) dp[i]=1;

	dp[0]=1;
	ht_now[0]=cows[0].ht;
	maxim=1;

	for(i=1;i<cow_no;i++){
		for(j=0;j<i;j++){
			if(ht_now[j]<=cows[i].max_ht&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
				ht_now[i]=ht_now[j]+cows[i].ht;
				if(dp[i]>maxim) maxim=dp[i];
			}
		}
	}

	printf("%d\n",maxim);

	return 0;
}