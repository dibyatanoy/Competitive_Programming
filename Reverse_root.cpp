#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#define long long int _int64

using namespace std;

int main(){

	vector <double> ara;
	double in;
	int j=0;
	
	while(scanf("%lf",&in)==1){
		ara.push_back(in);
		j++;
	}
	for(int i=j-1;i>=0;i--){
		
		printf("%.5lf\n",sqrt(double(ara[i])));
	}

	return 0;
}