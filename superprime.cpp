/*
ID: dibyapo2
LANG: C++
TASK: sprime
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;

bool is_prime(int a){
	int i,sq;
	sq=sqrt(a);
	for(i=2;i<sq+1;i++){
		if(a%i==0) return 0;
	}
	return 1;
}

void make(int num,int pos){
	int temp=num*10;
	int i,j;
	if(pos==N){
		printf("%d\n",num);
		return;
	}
	for(i=1;i<=9;i+=2){
		if(is_prime(temp+i)) make(temp+i,pos+1);
	}
	return;
}

int main(){

	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);

	scanf("%d",&N);
	
	make(2,1);
	make(3,1);
	make(5,1);
	make(7,1);

	return 0;
}