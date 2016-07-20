/*
ID: dibyapo2
LANG: C++
TASK: barn1
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main(){

	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);

	int M,S,C;
	bool cows[201];
	vector <int> gaps;

	memset(cows,0,sizeof(cows));

	scanf("%d %d %d",&M,&S,&C);

	int i,j,min=300,max=0;

	for(i=0;i<C;i++){
		int temp;
		scanf("%d",&temp);
		cows[temp-1]=true;
		if(temp-1>max) max=temp-1;
		if(temp-1<min) min=temp-1;
	}
	
	int gap_now=0;
	for(i=min;i<=max;i++){
		if(!cows[i]) gap_now++;
		else {
			if(gap_now!=0) gaps.push_back(gap_now);
			gap_now=0;
		}
	}
	sort(gaps.begin(),gaps.end());
	//for(i=0;i<gaps.size();i++) printf("%d ",gaps[i]);
	S=max-min+1;
	
	for(i=gaps.size()-1;i>=0;i--){
		if(M>1){
			S-=gaps[i];
			M--;
		}else break;
	}

	printf("%d\n",S);

	return 0;
}

/** AC!!! **/