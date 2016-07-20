#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

struct data{				
	int n,a;

	data(int nn,int aa){
		n=nn;
		a=aa;
		return;
	}

	int update(int k){
		return (a+k);
	}
};

int main(){

	data temp=data(1,5);

	printf("%d %d\n",temp.update(3),temp.a);

	return 0;
}