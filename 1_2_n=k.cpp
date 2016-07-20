#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){

	char h1,h2,m1,m2;
	int h,hh,m,mm;
	int t;
	scanf("%d",&t);

	while(t--){
		scanf("%c%c:%c%c",h1,h2,m1,m2);
		h=h1-'0';
		hh=h2-'0';
		m=m1-'0';
		mm=m2-'0';
		if(h1=='0'&&h2=='0'){
			if(m1=='0'){
				if(m2=='9'){
					printf("00:11\n");
					continue;
				}else{
					printf("00:0%d",m2-'0'+1);
				}
			}else{
				if(m>mm){
					printf("00:%d%d\n",m,m);
					continue;
				}else{
					if(m==5){
						printf("%d");
					}
				}
			}
		}
	}
			
	return 0;
}
