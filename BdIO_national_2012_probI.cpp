#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXX 40010

using namespace std;

struct seg{
	int mods[21];
};

seg tree[4*MAXX];
int N,F;

int fact(int i){
	if(i==0) return 1;
	if(i==1) return 1;
	else return i*fact(i-1);
}

seg merge_seg(seg b,seg c){
	int i;
	seg a;
	memset(a.mods,0,sizeof(a.mods));
	for(i=0;i<F;i++){
		a.mods[i]=b.mods[i]+c.mods[i];
	}
	return a;
}

void update(int idx,int st,int ed,int pos,int val){
	if(st==pos&&ed==pos){
		int i;
		memset(tree[idx].mods,0,sizeof(tree[idx].mods));
		tree[idx].mods[val%F]=1;
		return;
	}
	int mid=(st+ed)/2;
	int l=2*idx;
	int r=l+1;
	if(pos<=mid) update(l,st,mid,pos,val);
	else update(r,mid+1,ed,pos,val);

	tree[idx]=merge_seg(tree[l],tree[r]);
}

seg query(int idx,int st,int ed,int i,int j){
	
	if(st==i&&ed==j) return tree[idx];

	int mid=(st+ed)/2;
	int l=2*idx;
	int r=l+1;

	if(j<=mid) return query(l,st,mid,i,j);
	else if(i>mid) return query(r,mid+1,ed,i,j);
	else{
		seg a,b;
		a=query(l,st,mid,i,mid);
		b=query(r,mid+1,ed,mid+1,j);
		
		return merge_seg(a,b);
	}
}

int main(){

	int testcases,i,j,M;

	scanf("%d",&testcases);

	for(i=0;i<testcases;i++){
		scanf("%d %d %d",&F,&N,&M);
		memset(tree,0,sizeof(tree));

		printf("Case #%d:\n",i+1);

		for(j=1;j<=N;j++){
			int candies;
			scanf("%d",&candies);
			update(1,1,N,j,candies);
		}
		for(j=1;j<=M;j++){
			int type,a,b;

			scanf("%d %d %d",&type,&a,&b);
			if(type==1){
				update(1,1,N,a,b);
			}else{
				seg t=query(1,1,N,a,b);
				int k1,k2,ways=0;
				for(k1=0,k2=F;k1<=k2;k1++,k2=F-k1){
					if(k1%F==k2%F&&t.mods[k1%F]>1) ways+=fact(t.mods[k1%F])/(2*fact(t.mods[k1%F]-2));
					else if(k1%F!=k2%F) ways+=t.mods[k1%F]*t.mods[k2%F];
				}

				printf("%d\n",ways);
			}
		}
	}

	return 0;
}

/** Seems like AC!!! **/