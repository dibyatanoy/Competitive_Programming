#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	vector <int> pop;
	int g,no;

	scanf("%d",&g);

	for(int i=0;i<g;i++){
		scanf("%d",&no);
		pop.push_back(no);
	}

	sort(pop.begin(),pop.end());

	int count=0;

	for(int j=0;j<g/2+1;j++){
		count+=pop[j]/2+1;

	}

	printf("%d\n",count);

	return 0;
}
/* AC!!! */