#include <iostream>
#include <cstdio>
#include <cstring>
#define MX 200100
#define minim(a,b) (a<b)? a:b
 
using namespace std;
 
struct seg{
    __int64 mn;
    __int64 lazy;

};
 
seg data[MX*4];
int seq[MX];

void build(int idx,int st,int ed,int i,__int64 val){
	//printf("!");
	if(st==ed){
		data[idx].mn=val;
		data[idx].lazy=0;
		return;
	}
	int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;
    if(i<=mid) build(l,st,mid,i,val);
    else if(i>mid) build(r,mid+1,ed,i,val);
    //else {insert(l,st,mid,i,mid,val);insert(r,mid+1,ed,mid+1,j,val);}
 
    data[idx].mn=minim(data[l].mn,data[r].mn);
	return;
}
 
void update_node(int idx,int st,int ed,__int64 val){
    data[idx].mn=data[idx].mn+val;
    data[idx].lazy+=val;
    return;
}
 
void update_lazy(int idx,int st,int ed){
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;
    update_node(l,st,mid,data[idx].lazy);
    update_node(r,mid+1,ed,data[idx].lazy);
    data[idx].lazy=0;
    return;
}
 
void insert(int idx,int st,int ed,int i,int j,__int64 val){
 
    if(st==i&&ed==j){
        update_node(idx,st,ed,val);
        return;
    }
    if(data[idx].lazy) update_lazy(idx,st,ed);
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;
    if(j<=mid) insert(l,st,mid,i,j,val);
    else if(i>mid)insert(r,mid+1,ed,i,j,val);
    else {insert(l,st,mid,i,mid,val);insert(r,mid+1,ed,mid+1,j,val);}
 
    data[idx].mn=minim(data[l].mn,data[r].mn);
    return;
}
 
seg query(int idx,int st,int ed,int i,int j){
    if(st==i&&ed==j){
        return data[idx];
    }
    if(data[idx].lazy) update_lazy(idx,st,ed);
 
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;
    seg a,b,c;
    if(j<=mid) a = query(l,st,mid,i,j);
    else if(i>mid) a = query(r,mid+1,ed,i,j);
    else{b=query(l,st,mid,i,mid);
    c=query(r,mid+1,ed,mid+1,j);
    a.mn=minim(b.mn,c.mn);}
 
 
    return a;
}
 
int main(){
    int testcases,i,j,k,n,q;
	bool op;
	//char doit[100];
    //scanf("%d",&testcases);
 
    //for(i=1;i<=testcases;i++){
        scanf("%d",&n);
        for(i=0;i<MX;i++) {
			data[i].mn=100000000;
			data[i].lazy=0;
		}
        //printf("Case %d:\n",i);
		for(j=1;j<=n;j++){
			scanf("%d",&seq[j]);
			build(1,1,n,j,seq[j]);
		}
		//printf("!");
		scanf("%d",&q);
		bool prev=0;
        for(j=1;j<=q;j++){
            //scanf("%d %d",&x,&y);
			//scanf("%[^\n]s",doit);
			if(j==1 ) getchar();
			char doit[100];
			gets(doit);
			//printf("%s\n",doit);
			int x=0,y=0,v=0;
			//printf("!");
			for(k=0;doit[k]!=' ';k++){
				x=x*10+doit[k]-'0';
			}
			k++;
			op=0;
			for(;doit[k]!=' '&& k<strlen(doit);k++) {
					y=y*10+doit[k]-'0';
			}
			if(k==strlen(doit)) op=1;
			else{
				op=0;
				bool minus=0;
				k++;
				for(;k<strlen(doit);k++) {
					if(doit[k]=='-') minus=1;
					else v=v*10+(doit[k]-'0');
				}
				if(minus) v=-v;
			}
			//printf("%d %d %d\n",x,y,v);
			
            if(op==0){
 
                //scanf("%d %d %d",&x,&y,&v);
				if(x<=y) insert(1,1,n,x+1,y+1,v);
				else{
					insert(1,1,n,x+1,n,v);
					insert(1,1,n,1,y+1,v);
				}
            }else{
                __int64 ret;
                //scanf("%d%d",&x,&y);
				if(x<=y){
					ret=query(1,1,n,x+1,y+1).mn;	
				}else{
					ret=minim(query(1,1,n,x+1,n).mn,query(1,1,n,1,y+1).mn);
				}
                printf("%I64d\n",ret);
            }
			prev=op;
        }
 
    
 
    return 0;
}