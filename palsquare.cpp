/*
ID: dibyapo2
LANG: C++
TASK: palsquare
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int base;
string trgt,trgt2;

bool convert(int src,int num){
	trgt="",trgt2="";
	int i,j;
	for(i=num;i!=0;i/=base){
		int digit=i%base;
		if(digit<10) trgt+='0'+digit;
		else {
			trgt+='A'+digit-10;
		}
	}
	bool fnd=false;

	for(i=0,j=trgt.length()-1;i<=j;i++,j--){
		if(trgt[i]!=trgt[j]){
			//printf("Reached!trgt[%d]=%c & trgt[%d]=%c ",i,trgt[i],j,trgt[j]);
			fnd=1;
			break;
		}
	}
	if(!fnd){
		for(i=src;i!=0;i/=base){
			int digit=i%base;
			if(digit<10) trgt2+='0'+digit;
			else {
			trgt2+='A'+digit-10;
			}
		}
		for(i=trgt2.length()-1;i>=0;i--) printf("%c",trgt2[i]);
		printf(" ");
		for(i=trgt.length()-1;i>=0;i--) printf("%c",trgt[i]);
		printf("\n");
		
		return 1;
	}else return 0;
}

int main(){

	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);

	scanf("%d",&base);

	int i,j;

	for(i=1;i<=300;i++){
		(convert(i,i*i)); 
	}

	return 0;
}

/* AC!!! */