#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <utility>
#include <map>
#define pb push_back
#define all(v) v.begin(),v.end()
#define MP make_pair
#define Fr first
#define Sc second
#define ll long long int
#define CLR(x) memset(x,0,sizeof(x))
#define MAXX 10000
#define MAXXW 100005

using namespace std;
int h[MAXX],w[MAXX],N;
int dp_i[MAXX],dp_d[MAXX];
int seg[4*100000];

void update(int idx,int st,int ed,int pos,int val){
    if(st>ed) return;
    if(st==pos && ed==pos){
        seg[idx]=max(val,seg[idx]);
        return;
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(pos<=mid) update(l,st,mid,pos,val);
    else update(r,mid+1,ed,pos,val);

    seg[idx]=max(seg[l],seg[r]);

    return;
}

int query(int idx,int st,int ed,int i,int j){
    if(st>ed) return 0;

    if(st==i && ed==j){
        return seg[idx];
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(j<=mid) return query(l,st,mid,i,j);
    else if(i>mid) return query(r,mid+1,ed,i,j);
    else return max(query(l,st,mid,i,mid),query(r,mid+1,ed,mid+1,j));
}

int main(){

    int kases,i,j,k,t;
    scanf("%d",&kases);

    for(t=1;t<=kases;t++){

        scanf("%d",&N);
        int inc=0,dec=0;

        for(i=0;i<N;i++) scanf("%d",&h[i]);
        for(i=0;i<N;i++) scanf("%d",&w[i]);

        memset(dp_i,0,sizeof(dp_i));memset(dp_d,0,sizeof(dp_d));

        CLR(seg);

        dp_i[0]=w[0];update(1,1,MAXXW,h[0],dp_i[0]);
        inc=max(inc,dp_i[0]);
        for(i=1;i<N;i++){

            dp_i[i]=query(1,1,MAXXW,1,h[i]-1)+w[i];
            update(1,1,MAXXW,h[i],dp_i[i]);
            inc=max(inc,dp_i[i]);
        }
        CLR(seg);

        dp_d[N-1]=w[N-1];update(1,1,MAXXW,h[N-1],dp_d[N-1]);
        dec=max(dec,dp_d[N-1]);
        for(i=N-2;i>=0;i--){

            //printf(": %d\n",query(1,1,MAXXW,1,h[i]-1));

            dp_d[i]=query(1,1,MAXXW,1,h[i]-1)+w[i];
            update(1,1,MAXXW,h[i],dp_d[i]);
            dec=max(dec,dp_d[i]);
        }

        if(inc>=dec) printf("Case %d. Increasing(%d). Decreasing(%d).\n",t,inc,dec);
        else printf("Case %d. Decreasing(%d). Increasing(%d).\n",t,dec,inc);


    }

    return 0;
}
