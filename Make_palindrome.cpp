#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long int dp[1002][1002];
int dir[1002][1002];
bool taken[1002][1002];
char str[1002],output[2002];
int pos1=0,pos2=2001;

int prt_pal(int i,int j){
	if(i>j) return 0;
	if(i==j){
		printf("%c",str[i]);
		return 0;
	}else{
		if(dir[i][j]==0){
			printf("%c",str[i]);
			prt_pal(i+1,j-1);
			printf("%c",str[j]);
		}else if(dir[i][j]==1){
			printf("%c",str[i]);
			prt_pal(i+1,j);
			printf("%c",str[i]);

		}else{
			printf("%c",str[j]);
			prt_pal(i,j-1);
			printf("%c",str[j]);

		}
	}
	return 0;
}
/*int prt_pal(int i,int j){
	if(i>j) return 0;
	if(i==j){output[pos1++]=str[i];return 0;}

	if(dir[i][j]==0){
		output[pos1++]=str[i];
		output[pos2--]=str[j];
		prt_pal(i+1,j-1);
	}else if(dir[i][j]==1){
		output[pos1++]=str[i];
		output[pos2--]=str[i];
		prt_pal(i+1,j);
	}else{
		output[pos1++]=str[j];
		output[pos2--]=str[j];
		prt_pal(i,j-1);
	}
	return 0;
}*/

long int call(int i,int j){
	if(i>j) return 0;
	if(i==j) {dir[i][j]=0;return 0;}
	if(taken[i][j]) return dp[i][j];

	long int op1=10000,op2=10000;
	if(str[i]==str[j]){
		op1=call(i+1,j-1);
		dir[i][j]=0;
		dp[i][j]=op1;
	}else{
		op1=call(i+1,j)+1;	//insert char same as ith after jth;
		op2=call(i,j-1)+1;
		if(op1<op2){
			dp[i][j]=op1;
			dir[i][j]=1;
		}else{
			dp[i][j]=op2;
			dir[i][j]=2;
		}
	}
	taken[i][j]=1;
	//printf("Returning %d",dp[i][j]);
	return dp[i][j];

}

int main(){

	while(gets(str)){
		pos1=0,pos2=2001;
		int length=strlen(str);
		memset(taken,0,sizeof(taken));
		long int ans=call(0,length-1);
		printf("%ld ",ans);
		prt_pal(0,length-1);
		//for(int i=0;i<pos1;i++) printf("%c",output[i]);
		//for(int j=pos2+1;j<=2001;j++)printf("%c",output[j]);
		printf("\n");
	}
	return 0;
}

/** AC!!! **/