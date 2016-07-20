/*
ID: dibyapo2
LANG: C++
TASK: runround
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#define LL __int64
#define mll i64

using namespace std;

int mod(int a,int b){
	if(a>=0) return a%b;
	else while(a<0){
		a+=b;
	}
	return a%b;
}

int main(){

	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	int unique[10];
	//memset();

	long long int M,i;
	char num[10];

	scanf("%lld",&M);
	//printf("%d",M);

	for(i=M+1;;i++){
		int dig,place=0,dig_cnt=0;
		bool fnd=0;
		memset(unique,0,sizeof (unique));
		for(int j=i;j!=0;j/=10,place++){
			dig=j%10;
			dig_cnt++;
			if(dig==0||unique[dig]) {
				fnd=1;
				break;
			}else{
				num[place]=dig;
				unique[dig]=1;
			}
		}
		int ini_place=place-1;
		if(!fnd){
			bool reached[10];
			memset(reached,0,sizeof(reached));
			place--;
			int re_cnt=0;
			while(!reached[place]&&re_cnt<dig_cnt){
				reached[place]=1;
				re_cnt++;
				place=(mod((place-num[place]),dig_cnt));
			}
			if(re_cnt==dig_cnt&&place==ini_place){
				printf("%lld\n",i);
				break;
			}
		}
	}

	return 0;
}

/** AC!!! **/