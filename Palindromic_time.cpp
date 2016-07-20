#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool is_pal(int time){
	int h1,h2,m1,m2;
	m2=time%10;
	m1=(time%100)/10;
	h2=(time%1000)/100;
	h1=time/1000;

	if(h1==0&&h2==0&&m1==0){
		printf("%d%d:%d%d\n",h1,h2,m1,m2);
		return true;
	}else if(h1==0&&h2==0){
		if(m1==m2) {printf("%d%d:%d%d\n",h1,h2,m1,m2);
		return true;}
	}else if(h1==0){
		if(h2==m2) {
			printf("%d%d:%d%d\n",h1,h2,m1,m2);
			return true;
		}
	}else if(h1==m2&&h2==m1){
		printf("%d%d:%d%d\n",h1,h2,m1,m2);
		return true;	
	
	}
	return false;
}

void make_pal(int time){
	int i,j,k;
	for(i=time+1;;i++){
		if((i%100)>=60){
			i=(i/100+1)*100;
		}
		if(i>=2400){
			i-=2400;
		}
		if(is_pal(i)) return;
	}
}

int main(){

	int h1,h2,m1,m2;
	char seq[6];
	scanf("%s",seq);

	h1=seq[0]-'0';
	h2=seq[1]-'0';
	m1=seq[3]-'0';
	m2=seq[4]-'0';

	make_pal(h1*1000+h2*100+m1*10+m2);

	return 0;
}
