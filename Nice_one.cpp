#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
#include <cmath>
#define pb push_back
#define MP make_pair
#define maxim(a,b) ((a)>(b)? (a):(b))
#define INF 1e7
#define MAXX 9
#define all(v) v.begin(),v.end()

using namespace std;
int ants[1000004];

int main(){

	int kases,i,j,minl,maxl,length;

	scanf("%d",&kases);

	for(i=0;i<kases;i++){
		int n;
		scanf("%d %d",&length,&n);
		minl=1000003;maxl=0;
		for(j=0;j<n;j++){
			scanf("%d",&ants[j]);
		}
		sort(ants,ants+n);

		maxl=length-ants[0];
		for(j=0;j<n;j++){
			if(maxim(ants[j],length-((j==n-1)? length:ants[j+1]))>maxl){
				maxl=maxim(ants[j],length-((j==n-1)? length:ants[j+1]));
			}
			if(maxim(ants[j],length-((j==n-1)? length:ants[j+1]))<minl){
				minl=maxim(ants[j],length-((j==n-1)? length:ants[j+1]));
			}
		}
		printf("%d %d\n",minl,maxl);
	}

	return 0;
}