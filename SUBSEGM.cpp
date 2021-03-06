#include <bits/stdc++.h>
#define MAXX 400005

using namespace std;

struct seg{
    int ans,pref,suff,l,r,nums;
};

int n,m;
int vals[MAXX];
seg data[MAXX];

seg merge_seg(seg a,seg b){
    seg c;

    c.l=a.l;
    c.r=b.r;
    c.nums=a.nums+b.nums;

    if(a.r+1==b.l){
        c.ans=max(a.ans,max(b.ans,a.suff+b.pref));

        if(a.pref==a.nums) c.pref=a.ans+b.pref;
        else c.pref=a.pref;

        if(b.suff==b.nums) c.suff=b.ans+a.suff;
        else c.suff=b.suff;

    }else {
        c.ans=max(a.ans,b.ans);
        c.pref=a.pref;
        c.suff=b.suff;
    }

    return c;
}

void update(int idx,int st,int ed,int pos,int val){
    if(st==pos && ed==pos){
        data[idx].ans=1;
        data[idx].suff=1;
        data[idx].pref=1;
        data[idx].nums=1;
        data[idx].l=val;
        data[idx].r=val;
        return;
    }

    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(pos<=mid) update(l,st,mid,pos,val);
    else update(r,mid+1,ed,pos,val);

    data[idx]=merge_seg(data[l],data[r]);
    return;
}

seg query(int idx,int st,int ed,int i,int j){
    if(st==i && ed==j){
        return data[idx];
    }

    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;
    seg c,a,b;

    if(j<=mid) c=query(l,st,mid,i,j);
    else if(i>mid) c=query(r,mid+1,ed,i,j);
    else{
        a=query(l,st,mid,i,mid);
        b=query(r,mid+1,ed,mid+1,j);
        c=merge_seg(a,b);
    }

    return c;
}

int main(){

    int i,j,k;

    scanf("%d %d",&n,&m);

    for(i=0;i<n;i++) {
        int c;
        scanf("%d",&vals[i+1]);
        update(1,1,n,i+1,vals[i+1]);
        //update(1,1,n,i+1,c);
    }

    //create(1,1,n);
    printf("%d\n",data[1].ans);
    for(i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        update(1,1,n,x,y);
        printf("%d\n",query(1,1,n,1,n));
    }


    return 0;
}

/** AC!!! **/
