#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

struct pt{
	double x,y;
	int id;
};

bool cmp(pt a,pt b){
	return (a.x < b.x || a.x==b.x && a.y<b.y)||(a.x==b.x && a.y==b.y && a.id<b.id);
}

bool cw(pt a,pt b,pt c){
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a,pt b,pt c){
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector <pt> &a){
	if(a.size()==1) return;
	sort(a.begin(),a.end(),&cmp);

	pt p1,p2;
	p1=a[0];p2=a.back();

	vector<pt> up,down;
	up.push_back(p1);
	down.push_back(p1);
	size_t i;

	for( i=1; i<a.size();++i){
		if(i==a.size()-1 || cw(p1,a[i],p2)){
			while(up.size()>=2 && !cw(up[up.size()-2],up[up.size()-1],a[i]))
				up.pop_back();
			up.push_back(a[i]);
		}
		if(i==a.size()-1 || ccw(p1,a[i],p2)){
			while(down.size()>=2 && !ccw(down[down.size()-2],down[down.size()-1],a[i]))
				down.pop_back();
			down.push_back(a[i]);
		}
	}
	a.clear();
	for( i=0;i<down.size();i++){
		a.push_back(down[i]);
	}
	for( i=up.size()-2;i>0;--i){
		a.push_back(up[i]);
	}
}

int main(){

	int n;
	int kases,k;
	scanf("%d",&kases);
	k=kases;

	while(kases--){
	
	
	scanf("%d",&n);

	int i,j;

	vector <pt> a(n);

	for(i=0;i<n;i++){
		pt temp;
		scanf("%lf %lf",&temp.x,&temp.y);
		temp.id=i+1;
		a[i]=temp;
	}
	convex_hull(a);
	int lowest;
	double low_y=100000.0;

	for(i=0;i<a.size();i++){
		if(a[i].y<low_y){
			low_y=a[i].y;
			lowest=i;
		}
	}
	double perim=0.00;

	if(a.size()!=1){
		for(i=0;i<a.size()-1;i++){
			perim+=sqrt((a[i+1].x-a[i].x)*(a[i+1].x-a[i].x)+(a[i+1].y-a[i].y)*(a[i+1].y-a[i].y));
		}	
		perim+=sqrt((a[a.size()-1].x-a[0].x)*(a[a.size()-1].x-a[0].x)+(a[a.size()-1].y-a[0].y)*(a[a.size()-1].y-a[0].y));
	}
	if(kases<k) printf("\n");
	
	printf("%.2lf\n",perim);
	printf("%d",a[lowest].id);

	for(i=1;i<a.size();i++){
		printf(" %d",a[(lowest+i)%a.size()].id);
	}
	printf("\n");
	}

	return 0;
}

/** AC!!! **/