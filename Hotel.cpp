#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){

	int ara[101][101],N,row,col;

	scanf("%d",&N);

	int num=1;

	for(int i=N-1;i>=0;i--){
		row=0,col=i;
		for(int j=1;j<=N-i;j++){
			ara[row++][col++]=num;
			num++;
		}
	}

	for(int a=0;a<N-1;a++){
		row=a+1;col=0;
		for(int b=1;b<=N-a-1;b++){
			ara[row++][col++]=num;
			num++;
		}
	}

	for(int x=0;x<N;x++){
		int started=0;
		for(int y=0;y<N;y++){
			if(!started){
				started=1;
				printf("%d",ara[x][y]);
			}else printf(" %d",ara[x][y]);
		}

		printf("\n");
	}

	return 0;
}