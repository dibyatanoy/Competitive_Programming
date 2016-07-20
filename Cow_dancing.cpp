#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int N,M;
vector <int> ht_cows;
vector <int> ht_bulls;
int dp[250][250];
bool taken[250][250];

int minim(int a,int b){
	if(a<b) return a;
	return b;
}

int call(int bull,int cow){
	if(bull==N) return 0;
	if(cow==M) return 1e9;
	if(taken[bull][cow]) return dp[bull][cow];

	int diff1,diff2;

	diff1=abs(ht_bulls[bull]-ht_cows[cow])+call(bull+1,cow+1);
	diff2=call(bull,cow+1);

	dp[bull][cow]=minim(diff1,diff2);
	taken[bull][cow]=1;

	return dp[bull][cow];
}

int main(){

	int i,j,k;
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++) {int a;scanf("%d",&a);ht_bulls.push_back(a);}
	for(i=0;i<M;i++) {int a;scanf("%d",&a);ht_cows.push_back(a);}

	sort(ht_bulls.begin(),ht_bulls.end());
	sort(ht_cows.begin(),ht_cows.end());

	memset(taken,0,sizeof(taken));

	int ans=call(0,0);

	printf("%d\n",ans);
	

	return 0;
}