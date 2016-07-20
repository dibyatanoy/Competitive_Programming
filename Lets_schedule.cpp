#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
#include <cmath>
#define pb push_back
#define MP make_pair
#define minim(a,b) ((a)<(b)? (a):(b))
#define INF 1e7
#define MAXX 9
#define all(v) v.begin(),v.end()

using namespace std;

struct data{
	double st,ed;
	
};
int n,seq[MAXX];
data planes[MAXX];

double maxim(double a,double b){
	if((a-b)>=1e-3) return a;
	else return b;
}

bool is_valid(double gap){
	int i;
	double prev=planes[seq[0]].st;
	for(i=1;i<n;i++){
		if((prev+gap)>planes[seq[i]].ed) {return 0;}
		else prev=maxim(prev+gap,planes[seq[i]].st);
	}
	return bool(prev-planes[seq[i]].ed );
}

int main(){

	int i,j,kases=0;
	while(scanf("%d",&n) && n!=0){
		kases++;
		for(i=0;i<n;i++){
			scanf("%lf %lf",&planes[i].st,&planes[i].ed);
			planes[i].st*=60;
			planes[i].ed*=60;
			seq[i]=i;
		}
		//sort(planes,planes+n);

		double temp=0.0;
		do{
			double hi=(double)(2*1440*60+100),lo=0.0;

			while((hi-lo)>=1e-3){
				double mid=(hi+lo)/2.0;
				if(is_valid(mid)){
				//printf("%d\n",mid);
					if((mid-temp)>=1e-3) temp=mid;
					lo=mid;
				}else {
					hi=mid;
				}
			}
		
		}while(next_permutation(seq,seq+n));

		int ans;
		ans=(int)(temp+0.5); 
		//if(temp%60==0) printf("Case %d: %d:00\n",kases,temp/60);
		 printf("Case %d: %d:%.2d\n",kases,ans/60,ans%60);
	}

	return 0;
}