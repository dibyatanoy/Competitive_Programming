#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long int dp[5001][5001];
int N,M;
bool visited[5001][5001];
vector<int> bulls;
vector<int> cows;

long long int minim(long long int a,long long int b){
	if(a<b) return a;
	return b;
}

long long int call(int bull,int cow){
	if(bull==N) return 0;
	if(cow==M) return 1e10;
	if(visited[bull][cow]) return dp[bull][cow];

	long long int gain1,gain2;
	gain1=abs(bulls[bull]-cows[cow])+call(bull+1,cow+1);
	gain2=call(bull,cow+1);

	dp[bull][cow]=minim(gain1,gain2);

	visited[bull][cow]=1;
	return dp[bull][cow];
}

int main(){

	int i,j,ed;
	int temp_min,min_pos,tot_min=0;
	

	scanf("%d %d",&N,&M);
	int temp;

	for(i=0;i<N;i++){
		scanf("%d",&temp);
		bulls.push_back(temp);
	}
	for(i=0;i<M;i++){
		scanf("%d",&temp);
		cows.push_back(temp);
	}

	//ed=M-1;
	sort(bulls.begin(),bulls.end());
	sort(cows.begin(),cows.end());
	memset(dp,0,sizeof(dp));

	/*for(i=N-1;i>=0;i--){
		temp_min=100000;
		for(j=ed;j>=i;j--){
			if(abs(cows[j]-bulls[i])<temp_min){
				temp_min=abs(cows[j]-bulls[i]);
				min_pos=j;
			}
		}
		tot_min+=temp_min;
		ed=min_pos-1;
	}*/

	printf("%lld\n",call(0,0));

	return 0;
}