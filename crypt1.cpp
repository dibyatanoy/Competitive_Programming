/*
ID: dibyapo2
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

vector <int> valid;
int N;

bool is_val(int num){
	
	int i,j,k;
	bool fnd=false;
	for(i=num;i!=0;i/=10){
		j=i%10;
		fnd=false;
		for(k=0;k<N;k++){
			if(valid[k]==j) {fnd=true;break;}
		}
		if(!fnd) return 0;
	}
	return 1;
}

int check(int top,int down){
	int num1,num2,num3;
	num1=top*(down%10);
	num2=top*(int)(down/10);
	num3=top*down;

	if(num1>=1000||num2>=1000||num3>=10000) return 0;
	if(is_val(num1)&&is_val(num2)&&is_val(num3)) {return 1;}
	else return 0;
}

int call(int top,int down){
	int i;
	if(top>=100&&down>=10){
		if(check(top,down)) {return  1;}
		else return 0;
	}
	else if(top<100){
		int ans=0;
		for(i=0;i<N;i++)ans+=call(top*10+valid[i],down);
		return ans;
	}else if(down<10){
		int ans=0;
		for(i=0;i<N;i++)ans+=call(top,down*10+valid[i]);
		return ans;
	}
}

int main(){

	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a;
		scanf("%d",&a);
		valid.push_back(a);
	}

	printf("%d\n",call(0,0));

	return 0;
}

/** AC!!! **/