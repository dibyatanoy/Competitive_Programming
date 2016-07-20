/*
ID: dibyapo2
LANG: C++
TASK: pprime
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int a,b;
int lim1,lim2;
char prime[10];

bool is_prime(int x){
	int i,sq;
	sq=sqrt(x)+1;
	for(i=2;i<=sq+1;i++){
		if(x%i==0) return 0;
	}
	return 1;
}

void find_digits(){
	lim1=lim2=0;
	int i;
	for(i=a;i!=0;i/=10){
		lim1++;
	}
	for(i=b;i!=0;i/=10){
		lim2++;
	}
	return;
}

void process(int len){
	int i,prime_now=0;
	for(i=0;i<len;i++){
		prime_now=prime_now*10+prime[i];
	}
	if(prime_now>=a&&prime_now<=b&&is_prime(prime_now)) printf("%d\n",prime_now);
}

void generate(int pos1,int pos2,int len){
	if(pos1>pos2){
		process(len);
		return;
	}else{
		for(int i=0;i<=9;i++){
			if(pos1==0&&i==0) continue;
			prime[pos1]=i;
			prime[pos2]=i;
			generate(pos1+1,pos2-1,len);
		}
	}

}

int main(){

	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	scanf("%d %d",&a,&b);
	find_digits();

	for(int i=lim1;i<=lim2;i++) generate(0,i-1,i);

	return 0;
}