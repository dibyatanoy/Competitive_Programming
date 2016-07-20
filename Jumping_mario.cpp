#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){

	char seq[140];
	bool st=0,scan=1;

	while(gets(seq)){
		if(strlen(seq)==0) printf("\n");
		st=1;
		while(1){
			

		int i,j,curr=0;
		for(i=0;i<strlen(seq);i++){
			if(seq[i]>'0'&&seq[i]<='9'){
				curr+=seq[i]-'0';
			}else if(seq[i]=='!'){
				printf("\n");
			}else{
				if(seq[i]=='b'){
					for(j=0;j<curr;j++) printf(" ");
				}else {
					for(j=0;j<curr;j++) printf("%c",seq[i]);
				}
				curr=0;
			}

		}
		printf("\n");
		}
	}

	return 0;
}