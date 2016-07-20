#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	
	int N,row,col,i,j,ara[102][102],x,y,output[10002],cnt=0;

	scanf("%d",&N);

	for(i=0;i<N;i++){
		for(j=0;j<N;j++) scanf("%d",&ara[i][j]);
	}

	for(x=0;x<N;x++){
		row=x;col=0;
		for(y=0;y<x+1;y++){
			output[cnt++]=ara[row--][col++];
		}
	}
	for(x=N-1;x>0;x--){
		row=N-1;col=N-x;
		for(y=0;y<x;y++){
			output[cnt++]=ara[row--][col++];
		}
	}

	printf("%d",output[0]);
	for(x=1;x<N*N;x++){
		printf(" %d",output[x]);
	}

	printf("\n");

	return 0;
}