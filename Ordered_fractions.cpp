/*
ID: dibyapo2
TASK: frac1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define MAXX 51

using namespace std;

struct data{
	int num;
	int denom;

	bool operator <(const data&p)const{
		int temp1=num;
		int temp2=denom;
		return (temp1*p.denom)<(p.num*temp2 );
	}
};

vector <data> fractions;

int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main(){

	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	int N;
	scanf("%d",&N);

	int i,j;
	printf("0/1\n");

	for(i=1;i<N;i++){
		for(j=N;j>0&&j>i;j--){
			if(gcd(i,j)==1){
				data temp;
				temp.num=i;
				temp.denom=j;
				fractions.push_back(temp);
			}
		}
	}
	sort(fractions.begin(),fractions.end());
	for(i=0;i<fractions.size();i++) printf("%d/%d\n",fractions[i].num,fractions[i].denom);
	printf("1/1\n");


	return 0;
}