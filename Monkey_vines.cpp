#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define MAXX 155
#define minim(a,b) (a<b)? a:b
#define maxim(a,b) ((a)>(b))? (a):(b)

using namespace std;
char seq[MAXX];
int dp[MAXX][MAXX],n;
bool vis[MAXX][MAXX];

long long int call(int i,int j){
	if(i==j) return 0;
	if(i==j-1){
		return 2;
	}

	long long int gain1,gain2;
	int x,next_i=-1,next_j=-1;
	int o_cnt=0,c_cnt=0;

	for(x=i+1;x<j;x++){
		if(seq[x]=='[') {if(next_i==-1) next_i=x;o_cnt++;}
		if(seq[x]==']') {
			o_cnt--;
			if(o_cnt==0) {next_j=x;break;}
		}
	}
	x++;
	gain1=call(next_i,next_j);
	for(;x<j;x++){
		if(seq[x]=='[') {if(o_cnt==0) next_i=x;
			o_cnt++;
		}
		if(seq[x]==']') {
			o_cnt--;
			if(o_cnt==0) {next_j=x;break;}
		}
	}
	if(next_i==-1) gain2=2;
	else gain2=call(next_i,next_j);

	//printf("%d %d %d %d\n",i,j,gain1,gain2);
	long long int ret=maxim(gain1,gain2);
	return (2*ret);
}

int main(){

	int kases,i,j;
	scanf("%d",&kases);
	getchar();

	for(i=1;i<=kases;i++){

		gets(seq);
		//scanf("%s",seq);
		//memset(vis,0,sizeof(vis));
		//printf("%s",seq);

		n=strlen(seq)-1;
		if(n==-1) printf("%d %d\n",i,1);
		else printf("%d %lld\n",i,call(0,n));

	}

	return 0;
}