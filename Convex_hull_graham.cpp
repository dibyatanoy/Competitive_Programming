#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct pt{
	double x,y;
};

bool cmp(pt a,pt b){
	return a.x < b.x || a.x==b.x && a.y<b.y;
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
	scanf("%d",&n);

	int i,j;

	vector <pt> a(n);

	for(i=0;i<n;i++){
		pt temp;
		scanf("%lf %lf",&temp.x,&temp.y);
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

	for(i=0;i<a.size();i++){
		printf("%lf %lf\n",a[(lowest+i)%a.size()].x,a[(lowest+i)%a.size()].y);
	}

	return 0;
}