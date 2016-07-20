/*
ID: dibyapo2
LANG: C++
TASK: transform
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

char target[11][11],temp[11][11];
int N;

bool no_change(char src[11][11]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(src[i][j]!=target[i][j]) return 0;
		}
	}
	return 1;
}

bool rotate_90(char src[11][11]){
	int i,j,k=0,l=0;

	for(i=0;i<N;i++,k++){
		l=0;
		for(j=N-1;j>=0;j--,l++) {temp[k][l]=src[j][i];}
	}
	/*for(i=0;i<N;i++){
		printf("%s\n",src[i]);
	}
	printf("\n");
	for(i=0;i<N;i++){
		printf("%s\n",temp[i]);
	}
	printf("\n");*/
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(temp[i][j]!=target[i][j]) return 0;
		}
	}
	return 1;
}

bool rotate_180(){
	char temp180[11][11];
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++) temp180[i][j]=temp[i][j];
	}
	return rotate_90(temp180);
}

bool rotate_270(){
	char temp270[11][11];
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++) temp270[i][j]=temp[i][j];
	}
	return rotate_90(temp270);
}

bool reflect(char src[11][11]){
	int i,j;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			temp[i][N-j-1]=src[i][j];
		}
	}

	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(temp[i][j]!=target[i][j]) return 0;
		}
	}
	return 1;
	
}

bool combi(char src[11][11]){
	reflect(src);
	char tempc[11][11];
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++) tempc[i][j]=temp[i][j];
	}
	if(rotate_90(tempc)) return 1;
	else if(rotate_180()) return 1;
	else if(rotate_270()) return 1;
	else return 0;
} 

int main(){

	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);

	scanf("%d",&N);
	int i,j;
	char src[11][11];

	for(i=0;i<N;i++) scanf("%s",src[i]);
	for(i=0;i<N;i++) scanf("%s",target[i]);

	
	if(rotate_90(src)) printf("1\n");
	else if(rotate_180()) printf("2\n");
	else if(rotate_270()) printf("3\n");
	else if(reflect(src)) printf("4\n");
	else if(combi(src)) printf("5\n");
	else if(no_change(src)) printf("6\n");
	else printf("7\n");


	return 0;
}

/** AC!!! **/
	
