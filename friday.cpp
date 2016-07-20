/*
ID: dibyapo2
LANG: C++
TASK: friday
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){

	int months[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int days[8],N;
	bool is_leap;

	memset(days,0,sizeof(days));

	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);

	scanf("%d",&N);

	int curr_yr_m1,curr_m;

	curr_yr_m1=5;
	is_leap=false;

	for(int i=1900;i<1900+N;i++){
		if(is_leap){
			curr_yr_m1=(curr_yr_m1+2)%7;
			curr_m=curr_yr_m1;
			days[curr_yr_m1]++;
		}else{
			curr_yr_m1=(curr_yr_m1+1)%7;
			curr_m=curr_yr_m1;
			days[curr_yr_m1]++;
			//printf("1st day is %d ",curr_m);
		}

		if(i%400==0) is_leap=true;
		else if(i%4==0&&(i%100)!=0) is_leap=true;
		else is_leap=false;

		for(int j=2;j<=12;j++){
			if(j==3&&is_leap){
				curr_m=(curr_m+29%7)%7;
				days[curr_m]++;
			}else{
				curr_m=(curr_m+months[j-1]%7)%7;
				days[curr_m]++;
			}
		}

	}

	printf("%d ",days[6]);
	for(int cnt=0;cnt<=4;cnt++) printf("%d ",days[cnt]);
	printf("%d\n",days[5]);

	return 0;
}

/** AC!!! **/