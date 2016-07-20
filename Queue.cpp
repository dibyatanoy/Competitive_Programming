#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define pb push_back
#define INF 1e7
#define MAXX 100002

using namespace std;

int maxim(int a,int b){
	return (a>b)? a:b;
}

int minim(int a,int b){
	return (a<b)? a:b;
}

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main(){

	char seq;

	//int l=strlen(seq);
	char prev_c=' ';
	int men=0,i,prev_wt=0,last_w=0,cnt=0,wait;
	//memset(s_men,0,sizeof(s_men));

	while(scanf("%c",&seq)==1&&seq!='\n'){
		if(seq=='M') men++;
		else{
			if(prev_c=='F'&&men>0){
				wait=prev_wt+1;
				prev_wt=wait;
				last_w=men;
			}else{
				last_w=men;
			}
		}
		cnt++;
		prev_c=seq;
	}
	if(men==0||men==cnt) printf("0\n");
	else{
		printf("%d\n",prev_wt+last_w);
	}

	return 0;
}