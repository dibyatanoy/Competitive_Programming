#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>

using namespace std;
char s1[102],s2[102],v[102];
int dp[102][102][102];
int dir[102][102][102];
bool vis[102][102][102];
int l1,l2,l3;

int maxim(int a,int b){
	return (a>b)? a:b;
}

void print(int i,int j,int pos){
	if(dir[i][j][pos]==0){
		printf("%c",s1[i]);
		print(i+1,j+1,pos+1);
	}else if(dir[i][j][pos]==1){
		print(i+1,j,pos);
	}else if(dir[i][j][pos]==2){
		print(i,j+1,pos);
	}else if(dir[i][j][pos]==3){
		printf("%c",s1[i]);
		print(i+1,j+1,1);
	}else if(dir[i][j][pos]==4){
		print(i+1,j,pos);
	}else if(dir[i][j][pos]==5){
		print(i,j+1,pos);
	}else if(dir[i][j][pos]==6){
		printf("%c",s1[i]);
		print(i+1,j+1,2);
	}
	return;
}

int call(int i,int j,int pos){
	if(pos==l3+1) return 0;
	if(i==l1||j==l2) return 0;
	if(vis[i][j][pos]) return dp[i][j][pos];

	if(s1[i]==s2[j]){
		
		if(s1[i]==v[pos-1]) {
			//printf("Here with i=%d,j=%d,pos=%d\n",i,j,pos);
			if(pos!=l3) {dp[i][j][pos]=call(i+1,j+1,pos+1)+1;dir[i][j][pos]=0;}
			else {
				//printf("Here 2\n");
				int c1,c2;
				c1=call(i+1,j,pos);
				c2=call(i,j+1,pos);
				if(c1>c2) {dir[i][j][pos]=1;dp[i][j][pos]=c1;}
				else{
					dir[i][j][pos]=2;dp[i][j][pos]=c2;
				}
			}
		}
		else{ if(s1[i]!=v[0]) {dp[i][j][pos]=call(i+1,j+1,1)+1;dir[i][j][pos]=3;}
		else {
			dp[i][j][pos]=call(i+1,j+1,2)+1;
			dir[i][j][pos]=6;
		}
		}

	}else{
	
		 int c1,c2;
		c1=call(i+1,j,pos);
		c2=call(i,j+1,pos);
		if(c1>c2) {dir[i][j][pos]=4;dp[i][j][pos]=c1;}
		else{
			dir[i][j][pos]=5;dp[i][j][pos]=c2;
		}
	}
	vis[i][j][pos]=1;
	return dp[i][j][pos];
}

int main(){
	
	
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%s",v);

	memset(vis,0,sizeof(vis));
	memset(dir,-1,sizeof(dir));
	l1=strlen(s1);
	l2=strlen(s2);
	l3=strlen(v);

	int ans=call(0,0,1);

	if(ans!=0)print(0,0,1);
	else printf("0");
	printf("\n");


	return 0;
}