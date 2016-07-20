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
#define MAXX 32000
#define INF 10000000000LL
#define Fr first
#define Sc second

using namespace std;

struct seg{
    int l_unpair,r_unpair;
};

int N,M;
seg data[4*MAXX];
char str[MAXX];

void build(int idx,int st,int ed){
    if(st>ed) return;
    if(st==ed){
        if(str[st-1]=='('){
                data[idx].l_unpair=1;
                data[idx].r_unpair=0;
        }else{
            data[idx].r_unpair=1;
            data[idx].l_unpair=0;
        }
        return;
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    build(l,st,mid);
    build(r,mid+1,ed);


    data[idx].l_unpair=max(0,data[l].l_unpair-data[r].r_unpair)+data[r].l_unpair;
    data[idx].r_unpair=max(0,data[r].r_unpair-data[l].l_unpair)+data[l].r_unpair;

    return;
}

void update(int idx,int st,int ed,int pos){
    if(st>ed) return;
    if(st==pos && ed==pos){
        if(str[pos-1]=='('){
            data[idx].l_unpair=0;
            data[idx].r_unpair=1;
            str[pos-1]=')';
        }else{
            data[idx].r_unpair=0;
            data[idx].l_unpair=1;
            str[pos-1]='(';
        }
        return;
    }

    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(pos<=mid) update(l,st,mid,pos);
    else update(r,mid+1,ed,pos);

    data[idx].l_unpair=max(0,data[l].l_unpair-data[r].r_unpair)+data[r].l_unpair;
    data[idx].r_unpair=max(0,data[r].r_unpair-data[l].l_unpair)+data[l].r_unpair;

    return;
}

int main(){

    int i,j,k,kases,tmp;

    for(kases=1;kases<=10;kases++){

        scanf("%d",&N);

        scanf("%s",str);

        scanf("%d",&M);

        build(1,1,N);

        printf("Test %d:\n",kases);

        for(i=0;i<M;i++){

            scanf("%d",&tmp);

            if(tmp>0){
                update(1,1,N,tmp);
            }else{
                if(data[1].l_unpair==0 && data[1].r_unpair==0 ) printf("YES\n");
                else printf("NO\n");
            }
        }
    }

    return 0;
}


/** AC!!! **/
