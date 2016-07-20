#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXX 1050

using namespace std;

long int dp[MAXX][MAXX];
bool taken[MAXX][MAXX];
char str[MAXX];

int max(int a,int b){
	if(a>b) return a;
	return b;
}

long int call(int i,int j){
	if(i>j) return 0;
	if(i==j) return 1;
	if(taken[i][j]) return dp[i][j];

	int op1,op2;

	if(str[i]==str[j]){
		op1=call(i+1,j-1)+2;
		dp[i][j]=op1;
	}else{
		op1=call(i+1,j);
		op2=call(i,j-1);
		dp[i][j]=max(op1,op2);
	}
	taken[i][j]=1;
	//printf("Returning %d ",dp[i][j]);
	return dp[i][j];
}

int main(){
	int testcases,i,length;

	scanf("%d",&testcases);
	getchar();

	for(i=1;i<=testcases;i++){
		gets(str);
		length=strlen(str);
		memset(taken,0,sizeof(taken));

		printf("%ld\n",call(0,length-1));
	}
	return 0;
}

/** AC!!! **/