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

	char sum[200];
	scanf("%s",sum);

	int i,j;
	vector <int> a;
	

	int ones=0,twos=0,threes=0;
	for(i=0;i<strlen(sum);i++){
		if(sum[i]=='1') ones++;
		if(sum[i]=='2') twos++;
		if(sum[i]=='3') threes++;
	}
	for(i=0;i<ones;i++){
		a.push_back(1);
	}
	for(i=0;i<twos;i++){
		a.push_back(2);
	}
	for(i=0;i<threes;i++){
		a.push_back(3);
	}
	for(i=0;i<a.size()-1;i++){
		printf("%d+",a[i]);;
	}
	printf("%d\n",a[i]);

	return 0;
}