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
#define pb push_back
#define MP make_pair
#define maxim(a,b) ((a)>(b)? (a):(b))
#define minim(a,b) ((a)<(b)? (a):(b))
#define INF 1e7
#define MAXX 30005
#define all(v) v.begin(),v.end()

using namespace std;
struct data{
	int st;
	int ed;
	int dur;
	int cost;

	bool operator <(const data &p)const{
		return st<p.st;
	}
};
int N,seg[4*200004];
data orders[MAXX];

void update(int idx,int st,int ed,int pos,int val){
	if(st==pos&&ed==pos){
		if(seg[idx]<val) seg[idx]=val;
		return;
	}
	int mid=(st+ed)/2;
	int l=2*idx+1;
	int r=l+1;

	if(pos<=mid) update(l,st,mid,pos,val);
	else update(r,mid+1,ed,pos,val);

	seg[idx]=maxim(seg[l],seg[r]);
	return;
}

int query(int idx,int st,int ed,int i,int j){
	if(i<1 || j<1) return 0;
	if(st>ed) return 0;
	if(st==i&&ed==j) return seg[idx];

	int mid=(st+ed)/2;
	int l=2*idx+1;
	int r=l+1;

	if(j<=mid) return query(l,st,mid,i,j);
	else if(i>mid) return query(r,mid+1,ed,i,j);
	else return maxim(query(l,st,mid,i,mid),query(r,mid+1,ed,mid+1,j));
}

int gcd(int a,int b){
	return (b==0)? a:gcd(b,a%b);
}

int main(){

	int kases,i,j;
	scanf("%d",&kases);

	for(i=1;i<=kases;i++){
		scanf("%d",&N);
		memset(orders,0,sizeof(orders));
		for(j=0;j<N;j++){
			scanf("%d %d %d",&orders[j].st,&orders[j].dur,&orders[j].cost);
			orders[j].st++;
			orders[j].ed=orders[j].st+orders[j].dur-1;
		}
		sort(orders,orders+N);
		memset(seg,0,sizeof(seg));
		int ans=0;

		for(j=0;j<N;j++){
			int temp=query(1,1,200004,1,orders[j].st-1)+orders[j].cost;
			if(temp>ans) ans=temp;
			update(1,1,200004,orders[j].ed,temp);
		}
		printf("Case %d: %d\n",i,ans);

	}

	return 0;
}
