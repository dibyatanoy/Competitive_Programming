#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int maxim(int a,int b){
	return (a>b)? a:b;
}

int main(){

	int n,m;

	int corr[101],inc[101];

	scanf("%d %d",&n,&m);
	int i;

	for(i=0;i<n;i++){
		scanf("%d",&corr[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d",&inc[i]);
	}
	sort(corr,corr+n);
	sort(inc,inc+m);

	if(corr[n-1]>=inc[0]) printf("-1\n");
	else{
		if(corr[0]*2>=inc[0]) printf("-1\n");
		else{
			printf("%d\n",maxim(corr[n-1],2*corr[0]));
		}
	}


	return 0;
}