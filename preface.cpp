/*
ID: dibyapo2
LANG: C++
TASK: preface
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main(){

	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	
	map<string,int> letters;
	char num[]={' ','I','V','X','L','C','D','M'};
	letters["I"]=1; letters["V"]=2; letters["X"]=3; letters["L"]=4; letters["C"]=5; letters["D"]=6; letters["M"]=7;

	int N,i,j;
	int count[8];
	scanf("%d",&N);

	memset(count,0,sizeof(count));

	for(i=1;i<=N;i++){
		int place=0;
		for(j=i,place=0;j!=0;j/=10,place++){
			int curr_digit=j%10;
			int place_val=pow(10,place);
			//printf("%d\n",place_val);
			if(place_val==1){
				if(curr_digit<4){
					//printf("%d",letters["I"]);
					count[letters["I"]]+=curr_digit;
				}
				if(curr_digit==4) {count[letters["V"]]++;count[letters["I"]]++;}
				if(curr_digit>=5&&curr_digit<=8) count[letters["V"]]++;
				if(curr_digit>=6&&curr_digit<=8) count[letters["I"]]+=curr_digit-5;
				if(curr_digit==9){count[letters["I"]]++;count[letters["X"]]++;}
				//printf("Here\n");

			}else if(place_val==10){
				if(curr_digit<4){
					count[letters["X"]]+=curr_digit;
				}
				if(curr_digit==4) {count[letters["L"]]++;count[letters["X"]]++;}
				if(curr_digit>=5&&curr_digit<=8) count[letters["L"]]++;
				if(curr_digit>=6&&curr_digit<=8) count[letters["X"]]+=curr_digit-5;
				if(curr_digit==9){count[letters["X"]]++;count[letters["C"]]++;}
			}
			else if(place_val==100){
				if(curr_digit<4){
					count[letters["C"]]+=curr_digit;
				}
				if(curr_digit==4) {count[letters["C"]]++;count[letters["D"]]++;}
				if(curr_digit>=5&&curr_digit<=8) count[letters["D"]]++;
				if(curr_digit>=6&&curr_digit<=8) count[letters["C"]]+=curr_digit-5;
				if(curr_digit==9){count[letters["C"]]++;count[letters["M"]]++;}
			}
			else if(place_val==1000){
				if(curr_digit<=4){
					count[letters["M"]]+=curr_digit;
				}
				/*if(curr_digit==4) count[letters["D"]]++;
				if(curr_digit>=5&&curr_digit<=8) count[letters["D"]]++;
				if(curr_digit>=6&&curr_digit<=8) count[letters["L"]]+=curr_digit-5;
				if(curr_digit==9){count[letters["L"]]++;count[letters["M"]]++;}*/
			}
		}
		//printf("Here!");
	}
	for(int k=1;k<=7;k++){
		if(count[k]>0) { 
			printf("%c %d\n",num[k],count[k]);
			
		}
	}

	

	return 0;
}
/** AC!!! **/