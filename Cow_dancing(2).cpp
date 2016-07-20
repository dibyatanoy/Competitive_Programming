#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> cows;
vector <int> bulls;
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

	for(j=0;j<N;j++){
		int temp=1e7;
		for(k=idx+1;k<=j+diff;k++){
			if(abs(bulls[j]-cows[k])<temp){
				temp=abs(bulls[j]-cows[k]);
				idx=k;
			}
		}
		sum+=temp;
	}
	printf("%d\n",sum);

	return 0;
}