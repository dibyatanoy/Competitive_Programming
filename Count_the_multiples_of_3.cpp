#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MX 100100

using namespace std;

typedef struct seg{
	int mod0;
	int mod1;
	int mod2;
	int lazy;
};

seg data[4*MX];

void tree_init(int idx,int st,int ed){
	if(st==ed){
		data[idx].mod0=1;
		return;
	}
	int mid=(st+ed)/2;
	int l=2*idx;
	int r=l+1;
	tree_init(l,st,mid);
	tree_init(r,mid+1,ed);
	data[idx].mod0=data[l].mod0+data[r].mod0;
	
}

void update_node(int idx,int val){
	int temp1,temp2,temp3;
	if((val%3)==1){
		temp2=data[idx].mod2;
		temp1=data[idx].mod1;
		temp3=data[idx].mod0;
		data[idx].mod0=temp2;
		data[idx].mod1=temp3;
		data[idx].mod2=temp1;
	}else if((val%3)==2){
		temp2=data[idx].mod2;
		temp1=data[idx].mod1;
		temp3=data[idx].mod0;
		data[idx].mod0=temp1;
		data[idx].mod1=temp2;
		data[idx].mod2=temp3;
	}

	
	data[idx].lazy+=val;
	return;
}


void update_lazy(int idx,int val){
	//printf("Entered!");
	int l=2*idx;
	int r=l+1;
	update_node(l,val);
	return;
	update_node(r,val);
}

seg merge_seg(seg a,seg b){
	seg c;
	c.mod0=a.mod0+b.mod0;//printf("c.mod0=%d, a.mod0=%d, b.mod0=%d \n",c.mod0,a.mod0,b.mod0);
	c.mod1=a.mod1+b.mod1;//printf("c.mod1=%d, a.mod1=%d, b.mod1=%d \n",c.mod1,a.mod1,b.mod1);
	c.mod2=a.mod2+b.mod2;//printf("c.mod2=%d, a.mod2=%d, b.mod2=%d \n",c.mod2,a.mod2,b.mod2);
	c.lazy=0;

	return c;
}

void insert(int idx,int st,int ed,int i,int j,int val){
	if(st==i&&ed==j){
		update_node(idx,val);
		//printf("Changed from %d to %d\n",st,ed);
		return;
	}
	if(data[idx].lazy!=0) update_lazy(idx,data[idx].lazy);
	data[idx].lazy=0;

	int mid=(st+ed)/2;
	int l=2*idx;
	int r=l+1;

	if(j<=mid) insert(l,st,mid,i,j,val);
	else if(i>mid) insert(r,mid+1,ed,i,j,val);
	else{
		insert(l,st,mid,i,mid,val);
		insert(r,mid+1,ed,mid+1,j,val);
	}
	data[idx]=merge_seg(data[l],data[r]);
	return;
}

seg query(int idx,int st,int ed,int i,int j){
	//printf("Reached with %d and %d and %d and %d\n",st,ed,i,j);
	if(st==i&&ed==j){

		return data[idx];
	}
	
	if(data[idx].lazy) update_lazy(idx,data[idx].lazy);
	int mid=(st+ed)/2;
	//printf("mid=%d \n",mid);
	int l=2*idx;
	int r=l+1;
	seg a;
	if(j<=mid) a=query(l,st,mid,i,j);
	else if(i>mid) a=query(r,mid+1,ed,i,j);
	else {
		seg c=query(l,st,mid,i,mid);
		seg b=query(r,mid+1,ed,mid+1,j);
		a=merge_seg(b,c);
	}
	return a;
	
}

int main(){
	int testcases,i,n,q;
	scanf("%d",&testcases);
	for(i=1;i<=testcases;i++){
		scanf("%d %d",&n,&q);
		memset(data,0,sizeof(data));
		int j;
		tree_init(1,1,n);
		printf("Case %d:\n",i);
		for(j=1;j<=q;j++){
			int op,m,x;
			scanf("%d",&op);
			if(op==0){
				scanf("%d %d",&m,&x);
				insert(1,1,n,m+1,x+1,1);
			}else{
				scanf("%d %d",&m,&x);
				printf("%d\n",query(1,1,n,m+1,x+1).mod0);
			}
		}
	}
	return 0;
}