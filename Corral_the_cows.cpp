#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define MAXX 505
#define MAXX_R 10005

using namespace std;

struct data{
    int x, y;

    bool operator <(const data &p)const{
        return (x==p.x)? y<p.y:x<p.x;
    }
};

struct seg{
    int mx,lazy;
    bool is_lazy;
};

data points[MAXX];
seg tree[4*MAXX_R];
int c,N;

void update_node(int idx,int st,int ed,int val){
    tree[idx].mx=tree[idx].mx+val;
    tree[idx].lazy+=val;
    tree[idx].is_lazy=1;
    return;
}

void update_lazy(int idx,int st,int ed){
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;
    update_node(l,st,mid,tree[idx].lazy);
    update_node(r,mid+1,ed,tree[idx].lazy);
    tree[idx].lazy=0;
    tree[idx].is_lazy=false;
    return;
}

void update(int idx,int st,int ed,int i,int j,int val){
    if(st==i && ed==j){
        update_node(idx,st,ed,val);
        return;
    }
    if(tree[idx].is_lazy) update_lazy(idx,st,ed);
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(j<=mid){
        update(l,st,mid,i,j,val);
    }else if(i>mid) update(r,mid+1,ed,i,j,val);
    else{
        update(l,st,mid,i,mid,val);
        update(r,mid+1,ed,mid+1,j,val);
    }
    tree[idx].mx=max(tree[l].mx,tree[r].mx);
    return;
}

/*int query(int idx,int st,int ed,int pos){
    if(st==pos && ed==pos){
        return tree[idx].mx;
    }
    if(tree[idx].is_lazy) update_lazy(idx,st,ed);
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(pos<=mid) return query(l,st,mid,pos);
    else return query(r,mid+1,ed,pos);
}*/

int check(int l){
    int pt=0;
    int i;
    int ans=-1;

    for(i=0;i<N;i++){
        //printf("Outside, l=%d, %d\n",l,tree[1].mx);
        //printf("%d\n",ans);
        while((points[i].x-l+1)>points[pt].x && pt<i){
            //printf("Inside, l=%d, %d\n",l,tree[1].mx);
            update(1,1,MAXX_R-1,points[pt].y,min(points[pt].y+l-1,MAXX_R-1),-1);
            pt++;
        }
        update(1,1,MAXX_R-1,points[i].y,min(points[i].y+l-1,MAXX_R-1),1);
        ans=max(ans,tree[1].mx);
    }
    return ans;
}

int main(){

    int i,j;
    scanf("%d%d",&c,&N);

    for(i=0;i<N;i++){
        scanf("%d%d",&points[i].x,&points[i].y);
    }
    sort(points,points+N);

    int lo,hi;
    lo=1;hi=MAXX_R;

    while(lo<=hi){
        int mid=(lo+hi)/2;
        //printf("Reached %d %d\n",lo,hi);
        memset(tree,0,sizeof(tree));
        int max_p=check(mid);
        //cout <<max_p<<endl;
        if(max_p>=c){
            hi=mid-1;
        }else lo=mid+1;
    }
    printf("%d\n",lo);

    return 0;
}

/** AC!!! :D **/
