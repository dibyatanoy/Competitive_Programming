#include <iostream>				// Working code, run on ideone!
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
#define px second
#define py first
#define mp make_pair
#define eps 1e-9
typedef pair<long long,long long > pairll;

int n;
pairll pnts[100000];
set< pairll > box;
double best;

int compx(pairll a,pairll b){return a.px<b.px;}

double dmin(double a,double b){
	if(a-b<eps) {return a;}
	else return b;
}

int main(){

	scanf("%d",&n);

	int i;
	for(i=0;i<n;i++) scanf("%lld %lld",&pnts[i].px,&pnts[i].py);

	sort(pnts,pnts+n,compx);
	best=1500000000;
	
	
	box.insert(pnts[0]);
	int left=0;

	for(i=1;i<n;i++){
		while(left<i && pnts[i].px-pnts[left].px>best) box.erase(pnts[left++]);
		for(typeof(box.begin()) it=box.lower_bound(mp(pnts[i].py-best, pnts[i].px-best));it!=box.end() && pnts[i].py+best>=it->py;it++){
			best=dmin(best,sqrt(pow(pnts[i].py - it->py,2.0)+pow(pnts[i].px - it->px,2.0)));
			//printf("%.2f,%.2f\n",it->px,it->py);
		}
		box.insert(pnts[i]);
	}
	printf("%.2f\n",best);

	return 0;
}