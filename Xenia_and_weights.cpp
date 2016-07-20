#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main(){

	char weights[12];
	int M;

	scanf("%s",weights);
	scanf("%d",&M);

	bool wt[12];
	vector <int> sols;
	memset(wt,0,sizeof wt);

	int i,j;
	for(i=0;i<10;i++){
		if(weights[i]=='1') wt[i+1]=1;
	}
	int last=-1,min=1;
	int st[2];
	st[1]=0;st[0]=0;
	int turn=0;
	bool fnd=0,yes=1;

	for(i=0;i<M;i++){
		fnd=0;
		for(j=min;j<11;j++){
			if(wt[j]&&j!=last){
				sols.push_back(j);
				last=j;
				st[turn]+=j;
				min=st[turn]-st[(turn+1)%2]+1;
				fnd=1;
				break;
			}
		}
		turn=(turn+1)%2;
		if(fnd==0) {
			yes=0;
			break;
		}
	}
	if(yes==0) printf("NO\n");
	else{
		printf("YES\n");
		printf("%d",sols[0]);
		for(i=1;i<sols.size();i++) printf(" %d",sols[i]);

		printf("\n");
	}

	return 0;
}