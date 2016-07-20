#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int main(){

	int N;
	int trains[1010];
	while(scanf("%d",&N)==1&&N!=0){
		int i,j,k;
		while(scanf("%d",&trains[0])&&trains[0]!=0){
			for(i=1;i<N;i++) scanf("%d",&trains[i]);
			stack<int>wait;
			k=0;
			for(j=1;j<=N;j++){
				if(j==trains[k]){
					k++;
					while(!wait.empty()&&trains[k]==wait.top()){
						k++;
						wait.pop();
					}
				}
				else{
					wait.push(j);
				}
			}
			while(!wait.empty()&&k<=N){
				if(trains[k]==wait.top()){
					k++;
					wait.pop();
				}else{
					printf("No\n");
					break;
				}
			}
			if(wait.empty()) printf("Yes\n");
		}
		printf("\n");
	}

	return 0;
}

/** AC!!! **/
