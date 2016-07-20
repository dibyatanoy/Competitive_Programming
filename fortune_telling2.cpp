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
#define MAXX 200010
#define llINF 10000000000000000LL
#define INF 1000000005
#define Fr first
#define all(v) v.begin(),v.end()
#define L 0
#define R 1
#define Sc second

using namespace std;

int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}

struct seg{
    ll sum;
    int mn;
};

seg data[4*MAXX];
int A[MAXX],B[MAXX],N,K;

void build(int idx,int st,int ed){
    if(st>ed) return;
    if(st==ed){
        data[idx].sum=(ll)A[st];
        data[idx].mn=A[st];
        return;
    }

    build(2*idx,st,(st+ed)/2);
    build(2*idx+1,(st+ed)/2+1,ed);

    data[idx].sum=data[2*idx].sum+data[2*idx+1].sum;
    data[idx].mn=min(data[2*idx].mn,data[2*idx+1].mn);

    return;
}

void flip(int idx,int st,int ed,int t){

    if(st>ed) return;
    if(st==ed){
        if(data[idx].sum==(ll)A[st]){
            data[idx].sum=(ll)B[st];
            data[idx].mn=B[st];
        }else{
            data[idx].sum=(ll)A[st];
            data[idx].mn=A[st];
        }
        return;
    }

    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(data[l].mn<=t) flip(l,st,mid,t);
    if(data[r].mn<=t) flip(r,mid+1,ed,t);

    data[idx].sum=data[l].sum+data[r].sum;
    data[idx].mn=min(data[l].mn,data[r].mn);

    return;
}

int main(){

    int i,j;

    scanf("%d %d",&N,&K);

    for(i=0;i<4*MAXX;i++){
        data[i].sum=0;
        data[i].mn=INF;
    }

    for(i=1;i<=N;i++) scanf("%d %d",&A[i],&B[i]);

    build(1,1,N);

    for(i=1;i<=K;i++){
        int tmp;
        scanf("%d",&tmp);

        flip(1,1,N,tmp);
    }

    printf("%lld\n",data[1].sum);

    return 0;
}
