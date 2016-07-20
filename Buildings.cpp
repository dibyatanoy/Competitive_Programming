#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#define pb push_back
#define MP make_pair
#define CLR(x) memset(x,0,sizeof(x));
#define ll long long
#define MAXX 100007
#define INF 10000000000000000LL
#define Fr first
#define L 0
#define R 1
#define Sc second

using namespace std;

int hist[MAXX],M;
int l[MAXX],r[MAXX];

struct seg{
    ll sum,lazy_a,lazy_d;
    bool is_lazy;
};
struct data2{
    int val,pos;
};

seg data[4*MAXX];

void update_node(int idx,int st,int ed,ll a,ll d){
    data[idx].lazy_a+=a;
    data[idx].lazy_d+=d;
    ll n=(ll)(ed-st+1);
    data[idx].sum+=n*(2*a+(n-1)*d)/(ll)2;
    data[idx].is_lazy=1;

    return;
}

void update_lazy(int idx,int st,int ed){
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    update_node(l,st,mid,data[idx].lazy_a,data[idx].lazy_d);
    update_node(r,mid+1,ed,data[idx].lazy_a+data[idx].lazy_d*(ll)(mid+1-st),data[idx].lazy_d);

    data[idx].is_lazy=0;
    data[idx].lazy_a=0;
    data[idx].lazy_d=0;
    return;
}

void inserts(int idx,int st,int ed,int i,int j,ll a,ll d){

    if(i>j) return;
    if(st>ed) return;
    if(st==i && ed==j){
        update_node(idx,st,ed,a,d);
        return;
    }
    if(data[idx].is_lazy){
        update_lazy(idx,st,ed);
    }

    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(j<=mid) inserts(l,st,mid,i,j,a,d);
    else if(i>mid) inserts(r,mid+1,ed,i,j,a,d);
    else{
        inserts(l,st,mid,i,mid,a,d);
        inserts(r,mid+1,ed,mid+1,j,a+(ll)(mid+1-i)*d,d);
    }
    data[idx].sum=data[l].sum+data[r].sum;
    return;
}

ll query(int idx,int st,int ed,int pos){
    if(st>ed) return 0;
    if(st==pos && ed==pos){
        return data[idx].sum;
    }
    if(data[idx].is_lazy){
        update_lazy(idx,st,ed);
    }

    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;
    ll ans;

    if(pos<=mid) ans=query(l,st,mid,pos);
    else ans=query(r,mid+1,ed,pos);

    data[idx].sum=data[l].sum+data[r].sum;
    return ans;
}

void buildhist(){
    stack<data2>now;
    data2 temp;
    int i,ans=0;

    while(!now.empty()) now.pop();

    l[1]=0;
    temp.val=hist[1];
    temp.pos=1;
    now.push(temp);


    for(i=2;i<=M;i++){
        while(!now.empty() && (now.top().val>hist[i])) now.pop();

        if(!now.empty()) l[i]=now.top().pos;
        else l[i]=0;

        temp.val=hist[i];
        temp.pos=i;

        now.push(temp);

    }

    while(!now.empty()) now.pop();

    r[M]=M+1;
    temp.val=hist[M];
    temp.pos=M;
    now.push(temp);

    for(i=M-1;i>0;i--){
        while(!now.empty() && now.top().val>=hist[i]) now.pop();    //Note difference: <= operator

        if(!now.empty()) r[i]=now.top().pos;
        else r[i]=M+1;

        temp.val=hist[i];
        temp.pos=i;
        now.push(temp);
    }

    return;
}


int main(){

    int i,j,k;

    scanf("%d",&M);

    for(i=1;i<=M;i++) scanf("%d",&hist[i]);
    buildhist();

    for(i=1;i<=M;i++) printf("%d ",l[i]);
    cout<<endl;
    for(i=1;i<=M;i++) printf("%d ",r[i]);
    cout<<endl;

    CLR(data);

    for(i=1;i<=M;i++){
        inserts(1,1,M,i,r[i]-1,(ll)(hist[i]*(r[i]-i)),-(ll)hist[i]);
        //printf("OK!\n");
        inserts(1,1,M,l[i]+1,i-1,(ll)hist[i],(ll)hist[i]);
        //printf("OK!\n");
    }

    printf("%lld",query(1,1,M,1));
    for(i=2;i<=M;i++){
        printf(" %lld",query(1,1,M,i));
    }
    printf("\n");

    return 0;
}
