#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char brackets[30050];
int num;

int check(){
	int cnt=0;
	for(int j=0;j<num;j++){
		if(brackets[j]=='('){cnt++;}
		else {cnt--;}
	}

	if(cnt==0) return 1;
	else return 0;
}

int main(){

	int testcases,op,pos,correct;

	for(testcases=0;testcases<10;testcases++){
		scanf("%d",&num);
		scanf("%s",brackets);
		scanf("%d",&op);
		printf("Test %d:\n",testcases+1);
		for(int i=0;i<op;i++){
			scanf("%d",&pos);
			if(pos==0){
				correct=check();
				if(correct) printf("YES\n");
				else printf("NO\n");
			}else{
				if(brackets[pos-1]=='(') brackets[pos-1]=')';
				else brackets[pos-1]='(';
			}
		}
	}

	return 0;
}