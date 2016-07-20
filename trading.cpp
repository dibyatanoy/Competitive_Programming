#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define MAXX 300004
#define ll long long

using namespace std;
int N,M,data[4*MAXX],lazy[4*MAXX];
bool is_lazy[4*MAXX];

void update_node(int idx,int val){
    data[idx]=max(data[idx],val);
    lazy[idx]=max(data[idx],val);
    is_lazy[idx]=1;
    return;
}

void update(int idx,int st,int ed,int i,int j,int val){
    if(st==i && ed==j){
        data[idx]=max(data[idx],val);
        lazy[idx]=max(data[idx],val);
        is_lazy[idx]=1;
        return;
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(is_lazy[idx]) {
        update_node(l,lazy[idx]);
        update_node(r,(mid+1-st)+lazy[idx]);
        lazy[idx]=0;
        is_lazy[idx]=0;
    }

    if(j<=mid) update(l,st,mid,i,j,val);
    else if(i>mid) update(r,mid+1,ed,i,j,val);
    else{
        update(l,st,mid,i,mid,val);
        update(r,mid+1,ed,mid+1,j,(mid+1-i)+val);
    }
    return;
}

int query(int idx,int st,int ed,int pos){
    if(st==pos && ed==pos){
        return data[idx];
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(is_lazy[idx]) {
        update_node(l,lazy[idx]);
        update_node(r,(mid+1-st)+lazy[idx]);
        lazy[idx]=0;
        is_lazy[idx]=0;
    }

    if(pos<=mid) return query(l,st,mid,pos);
    else return query(r,mid+1,ed,pos);
}

int main(){

    freopen("trading.in","r",stdin);
    freopen("trading.out","w",stdout);

    scanf("%d%d",&N,&M);

    int i,j,l,r,x;

    for(i=0;i<M;i++){
        scanf("%d%d%d",&l,&r,&x);
        update(1,1,N,l,r,x);
    }
    printf("%d",query(1,1,N,1));
    for(i=2;i<=N;i++){
        printf(" %d",query(1,1,N,i));
    }
    printf("\n");

    return 0;
}

/** AC!!! **/
