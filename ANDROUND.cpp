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
#define all(v) v.begin(),v.end()
#define PII pair <int,int >
#define ll long long
#define MAXX 22100
#define INF 10000000000LL
#define Fr first
#define Sc second

using namespace std;
int N;
long long int A[MAXX],K,seg[4*MAXX];
long long int sol[MAXX];

void build(int idx,int st,int ed){
    if(st>ed) return;
    if(st==ed){
        seg[idx]=A[st];
        return;
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;
    build(l,st,mid);
    build(r,mid+1,ed);

    seg[idx]=(seg[l]) & (seg[r]);
    return;
}

long long int query(int idx,int st,int ed,int i,int j){

    //printf("%d %d   %d %d\n",st,ed,i,j);
    if(st==i && ed==j){
        return seg[idx];
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(j<=mid) return  query(l,st,mid,i,j);
    else if(i>mid) return query(r,mid+1,ed,i,j);
    else return (query(l,st,mid,i,mid)) & (query(r,mid+1,ed,mid+1,j));

}

int main(){

    int i,j,kases;

    scanf("%d",&kases);

    while(kases--){
    scanf("%d %lld",&N,&K);

    for(i=1;i<=N;i++) scanf("%lld",&A[i]);
    build(1,1,N);

    //cout<<query(1,1,N,4,5)<<endl;
    //cout<<query(1,1,N,5,6)<<endl;

    if(K>=N/2){
        long long int ret=query(1,1,N,1,N);
        printf("%lld",ret);

        for(i=1;i<N;i++) printf(" %lld",ret);
        printf("\n");
    }else{
        for(i=1;i<=N;i++){
            if(i+K>N) sol[i]=(query(1,1,N,i,N) & query(1,1,N,1,i+K-N)) & query(1,1,N,i-K,i);
            else if(i-K<1) sol[i]=(query(1,1,N,i,i+K) & query(1,1,N,1,i)) & query(1,1,N,i-K+N,N) ;
            else sol[i]=query(1,1,N,i-K,i) & query(1,1,N,i,i+K);
        }

        printf("%lld",sol[1]);
        for(i=2;i<=N;i++) printf(" %lld",sol[i]);
        printf("\n");
    }
    }

    return 0;
}
