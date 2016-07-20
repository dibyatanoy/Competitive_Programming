#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> cows;
vector <int> bulls;
bool taken[1000];
int N,M;

int main(){

	int i,j,k;
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++){
		int a;
		scanf("%d",&a);
		bulls.push_back(a);
	}
	for(i=0;i<M;i++){
		int a;
		scanf("%d",&a);
		cows.push_back(a);
	}
	int diff=M-N;
	int idx=0;
	int sum=0;
	sort(cows.begin(),cows.end());
	sort(bulls.begin(),bulls.end());
	memset(taken,0,sizeof(taken));

	for(j=0;j<N;j++){
		int min=1e9;
		for(k=0;k<cows.size();k++){
			if(abs(bulls[j]-cows[k])<min){
				min=abs(bulls[j]-cows[k]);
				idx=k;
			}
		}
		sum+=min;
		cows.erase(cows.begin()+idx);
	}
	printf("%d\n",sum);

	return 0;
}