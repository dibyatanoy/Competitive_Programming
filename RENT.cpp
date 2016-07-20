#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define MAXX 200010

using namespace std;

typedef struct data{
	int st,ed,p;

	bool operator <(const data &v)const{
		return st<v.st;
	}
};

vector <data> orders;
vector <int> uniq_t;
int seg[4*MAXX];
int sz;
int dp[10005];

int maxim(int a,int b){
	if(a>b) return a;
	return b;
}

int bin_srch(int time){
	int l,h,mid;
	l=0;h=sz-1;

	while(l<=h){
		mid=(l+h)/2;
		if(uniq_t[mid]==time) return mid;
		else if(uniq_t[mid]>time) h=mid;
		else l=mid+1;
	}
	return -1;
}

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
	if(st>ed) return 0;
	if(st==i&&ed==j) return seg[idx];

	int mid=(st+ed)/2;
	int l=2*idx+1;
	int r=l+1;

	if(j<=mid) return query(l,st,mid,i,j);
	else if(i>mid) return query(r,mid+1,ed,i,j);
	else return maxim(query(l,st,mid,i,mid),query(r,mid+1,ed,mid+1,j));
}

int main(){

	int kases;

	scanf("%d",&kases);

	int i,j,k;
	for(i=0;i<kases;i++){
		sz=0;
		memset(seg,0,sizeof(seg));
		orders.clear();
		uniq_t.clear();

		int s,d,p,order;
		scanf("%d",&order);

		for(j=0;j<order;j++){

			scanf("%d %d %d",&s,&d,&p);
			int ed=s+d-1;
			data temp;
			temp.st=s;
			temp.ed=ed;
			temp.p=p;
			orders.push_back(temp);
			uniq_t.push_back(s);
			uniq_t.push_back(s+d-1);
			sz+=2;
		}
		
		

		sort(uniq_t.begin(),uniq_t.end());
		sort(orders.begin(),orders.end());
		


		int sz2=0,ans=0;
		for(j=0;j<sz;j++){

			if(uniq_t[j]!=uniq_t[sz2]){
				uniq_t[++sz2]=uniq_t[j];
			}

		}
		sz=sz2+1;


		dp[0]=orders[0].p;

		update(0,0,sz-1,bin_srch(orders[0].ed),dp[0]);
		
		
		for(j=1;j<order;j++){

			dp[j]=orders[j].p+query(0,0,sz-1,0,bin_srch(orders[j].st)-1);
			update(0,0,sz-1,bin_srch(orders[j].ed),dp[j]);
		
			if(dp[j]>ans) ans=dp[j];
		}

		printf("%d\n",ans);


	}
	

	return 0;
}

/** AC!!! **/