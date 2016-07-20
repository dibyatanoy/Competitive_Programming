#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#define MAXX 1e5+2
#define pb push_back

using namespace std;

struct pt{
	int x,y;

	bool operator<(const pt&p)const{
		if(x==p.x) return (abs(y)<abs(p.y));
		else return (abs(x)<abs(p.x));
	}
};

int maxim(int a,int b){
	return (a>b)? a:b;
}

int main(){

	int n;
	vector <pt> left,rt;

	scanf("%d",&n);

	int i,j;

	for(i=0;i<n;i++){
		int x,y;

		scanf("%d %d",&x,&y);
		pt temp;
		temp.x=x;temp.y=y;
		if(x<0) left.pb(temp);
		else rt.pb(temp);
	}
	sort(left.begin(),left.end());
	sort(rt.begin(),rt.end());

	int m=0;

	for(i=0;i<left.size();i++){
		if(left[i].y==0) m+=4;
		else if(left[i].x==0) m+=4;
		else m+=6;
	}
	for(i=0;i<rt.size();i++){
		if(rt[i].y==0) m+=4;
		else if(rt[i].x==0) m+=4;
		else m+=6;
	}

	printf("%d\n",m);

	for(i=0;i<left.size();i++){
		if(left[i].y==0){
			printf("1 %d L\n",abs(left[i].x));
			printf("2\n");
			printf("1 %d R\n",abs(left[i].x));
			printf("3\n");
		}
		else {
			printf("1 %d L\n",abs(left[i].x));
			if(left[i].y<0) printf("1 %d D\n",abs(left[i].y));
			else printf("1 %d U\n",abs(left[i].y));
			printf("2\n");
			if(left[i].y<0) printf("1 %d U\n",abs(left[i].y));
			else printf("1 %d D\n",abs(left[i].y));
			printf("1 %d R\n",abs(left[i].x));
			printf("3\n");


		}
	}
	for(i=0;i<rt.size();i++){
		if(rt[i].y==0){
			printf("1 %d R\n",abs(rt[i].x));
			printf("2\n");
			printf("1 %d L\n",abs(rt[i].x));
			printf("3\n");
		}
		else if(rt[i].x==0){
			if(rt[i].y<0) printf("1 %d D\n",abs(rt[i].y));
			else printf("1 %d U\n",abs(rt[i].y));
			printf("2\n");
			if(rt[i].y<0) printf("1 %d U\n",abs(rt[i].y));
			else printf("1 %d D\n",abs(rt[i].y));
			printf("3\n");
		}
		else {
			printf("1 %d R\n",abs(rt[i].x));
			if(rt[i].y<0) printf("1 %d D\n",abs(rt[i].y));
			else printf("1 %d U\n",abs(rt[i].y));
			printf("2\n");
			if(rt[i].y<0) printf("1 %d U\n",abs(rt[i].y));
			else printf("1 %d D\n",abs(rt[i].y));
			printf("1 %d L\n",abs(rt[i].x));
			printf("3\n");
		}
	}

	return 0;
}