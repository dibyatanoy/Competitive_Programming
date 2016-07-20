#include <iostream>
#include <cstdio>
#include <cstring>
#define MX 100100

using namespace std;

typedef struct seg{
    int suff;
    int pref;
    int msum;
    int sum;
};

seg data[4*MX];

int maxim(int a,int b,int c){
    if(a>=b&&a>=c) return a;
    else if(c>=b&&c>=a) return c;
    return b;
}

seg merge_seg(seg a,seg b){
    seg c;
    c.sum=a.sum+b.sum;
    c.pref=max(b.pref+a.sum,a.pref);
    c.suff=max(b.suff,b.sum+a.suff);
    c.msum=maxim(a.msum,b.msum,a.suff+b.pref);

    return c;
}

void insert(int idx,int st,int ed,int pos,int val){

    if(st==pos&&ed==pos){
        data[idx].msum=val;
        data[idx].sum=val;
        data[idx].pref=val;
        data[idx].suff=val;
        return ;
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;
    if(pos<=mid) insert(l,st,mid,pos,val);
    else insert(r,mid+1,ed,pos,val);

    data[idx]=merge_seg(data[l],data[r]);
}

seg query(int idx,int st,int ed,int i,int j){
    if(st==i&&ed==j) return data[idx];
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;
    if(j<=mid)return query(l,st,mid,i,j);
    else if(i>mid) return query(r,mid+1,ed,i,j);
    else{
            seg a=query(l,st,mid,i,mid);
            seg b=query(r,mid+1,ed,mid+1,j);
            seg c=merge_seg(a,b);
            return c;
    }
}

int main(){
    int n,q,cmd,i,j,v,kase=0;


        memset(data,0,sizeof(data));
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&v);
            insert(1,1,n,i,v);
        }


        scanf("%d",&q);
        for(int k=1;k<=q;k++){
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",query(1,1,n,x,y).msum);
        }




    return 0;
}

/*sufs[1]=nums[1];
        for(i=2;i<n;i++){
            sufs[i]=max(sufs[i-1]+nums[i],nums[i]);
        }
        prefs[n]=nums[n];
        for(i=n;i>0;i--){
            prefs[i]=max(prefs[i+1]+nums[i],nums[i]);
        }*/