#include <bits/stdc++.h>
#define MAXX 100010

using namespace std;

struct seg{
    long long int sum;
    long long int lazy;
    bool is_lzy;
};

seg data[4*MAXX];
int n,q;

int gcd(long long int a,long long int b){
    return (b==0)? a:gcd(b,a%b);
}

/*void build(int idx,int st,int ed){
    if(st==ed){
        data[idx].sum=nums[st];
        return;
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;
    build(l,st,mid);
    build(r,mid+1,ed);
    return;
}*/

void update_node(int idx,int st,int ed,long long int val){
    data[idx].sum=(long long)(ed-st+1)*val;
    data[idx].lazy=(long long)val;
    data[idx].is_lzy=true;
    return;
}

void update_lazy(int idx,int st,int ed){
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;
    update_node(l,st,mid,data[idx].lazy);
    update_node(r,mid+1,ed,data[idx].lazy);
    data[idx].lazy=(long long)0;
    data[idx].is_lzy=false;
    return;
}

void inserts(int idx,int st,int ed,int i,int j,int val){
    //printf("!\n");
    if(st==i && ed==j){
        update_node(idx,i,j,val);
        return;
    }
    if(data[idx].is_lzy==true) update_lazy(idx,st,ed);//printf("Here!\n");}
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;
    if(j<=mid) inserts(l,st,mid,i,j,val);
    else if(i>mid) inserts(r,mid+1,ed,i,j,val);
    else{
        inserts(l,st,mid,i,mid,val);
        inserts(r,mid+1,ed,mid+1,j,val);
    }
    data[idx].sum=data[l].sum+data[r].sum;
    return;
}

seg query(int idx,int st,int ed,int i,int j){
    if(st==i && ed==j){
        return data[idx];
    }
    if(data[idx].is_lzy==true) update_lazy(idx,st,ed);
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;
    seg a,b,c;
    if(j<=mid) a=query(l,st,mid,i,j);
    else if(i>mid) a=query(r,mid+1,ed,i,j);
    else{
        b=query(l,st,mid,i,mid);
        c=query(r,mid+1,ed,mid+1,j);
        a.sum=b.sum+c.sum;
    }
    return a;
}

int main(){

    int kases,i,j,k;
    scanf("%d",&kases);

    for(i=1;i<=kases;i++){
        scanf("%d%d",&n,&q);
        memset(data,0,sizeof(data));

        //for(j=1;j<=n;j++) scanf("%d",&nums[j]);
        //build(1,1,n);

        int op,x,y,v;
        printf("Case %d:\n",i);

        for(j=0;j<q;j++){
            scanf("%d",&op);
            if(op==1){
                scanf("%d %d %d",&x,&y,&v);
                inserts(1,1,n,x+1,y+1,v);
            }else{
                scanf("%d %d",&x,&y);
                long long int ans=query(1,1,n,x+1,y+1).sum;
                //printf("%d\n",ans);
                int div=gcd(ans,(long long)(y-x+1));
                ans/=div;

                if((y-x+1)==div) printf("%lld\n",ans);
                else printf("%lld/%d\n",ans,(y-x+1)/div);
            }
        }
    }

    return 0;
}
