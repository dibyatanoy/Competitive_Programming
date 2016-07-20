#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#define eps 1e-9

int N,cap;
double dp[60000][20002];
bool taken[60000][20002];
int stones[20002];

using namespace std;

double max(double a,double b){

	if(a>b) return a;
	return b;
}

double call(int used,int i){
	if(used==cap) return 0;
	if(i==N) return 0;
	if(taken[used][i]) return dp[used][i];
	
	double gain1=0,gain2=0;
	if(used+stones[i]<=cap) gain1=call(used+stones[i],i+1)+stones[i];
	gain2=call(used,i+1);

	dp[used][i]=max(gain1,gain2);
	taken[used][i]=1;
	return dp[used][i];
}

int main(){

	int sum=0,marbles[6],k,l,kase=0;

	for(k=0;k<6;k++) scanf("%d",&marbles[k]);
	while(!(marbles[0]==0&&marbles[1]==0&&marbles[2]==0&&marbles[3]==0&&marbles[4]==0&&marbles[5]==0)){
	
	l=0;
	int z=0;

	memset(taken,0,sizeof(taken));

	for(int i=0;i<6;i++){
		for(l=0;l<marbles[i];l++){
			stones[z]=i+1;
			z++;
			sum+=stones[z-1];
		}
	}
	N=z;
	double ans;
	cap=(int)sum/2;
	ans=call(0,0);

	if(((double)sum/2.0-ans)<eps) printf("Collection #%d:\nCan be divided.\n\n",++kase);
	else printf("Collection #%d:\nCan't be divided.\n\n",++kase);
	for(k=0;k<6;k++) scanf("%d",&marbles[k]);
	
	}
	return 0;
}
