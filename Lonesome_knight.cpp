#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){

	int testcase,row,i,rank_no;
	char rank;

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%c",&rank);
		while(rank=='\n') scanf("%c",&rank);
		scanf("%d",&row);

		rank_no=(int)rank-'a'+1;
		int count=0;
		if(rank_no+1<=8&&row+2<=8) count++;
		if(rank_no+2<=8&&row+1<=8) count++;
		if(rank_no-1>0&&row+2<=8) count++;
		if(rank_no-2>0&&row+1<=8) count++;
		if(rank_no-2>0&&row-1>0) count++;
		if(rank_no-1>0&&row-2>0) count++;
		if(rank_no+2<=8&&row-1>0) count++;
		if(rank_no+1<=8&&row-2>0) count++;

		printf("%d\n",count);

		
	}

	return 0;
}