#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#define INF 1000000000
#define eps 1e-9
#define CLR(x) memset(x,0,sizeof(x))
#define pb push_back
#define all(x) x.begin(), x.end()
#define Fr first
#define Sc second
#define MAXX 600000
#define pi 2*acos(0.0)

using namespace std;

int ara[MAXX];
int inv_u[MAXX],inv_d[MAXX],N;
int reduced,a,b;
int bit[MAXX];

void update(int pos,int val){
    int i;

    for(i=pos;i<MAXX;i+=i&-i){
        bit[i]+=val;
    }
    return;
}

int query(int pos){
    int i,ret=0;
    if(pos<1) return 0;

    for(i=pos;i>0;i-=i&-i){
        ret+=bit[i];
    }
    return ret;
}

int main(){

    int i,j,k;

    scanf("%d",&N);

    for(i=0;i<N;i++){

        scanf("%d",&ara[i]);
    }

    CLR(bit);CLR(inv_u);CLR(inv_d);

    for(i=N-1;i>=0;i--){
        inv_u[i]=query(ara[i]-1);
        update(ara[i],1);
    }

    CLR(bit);

    for(i=0;i<N;i++){

        inv_d[i]=i-query(ara[i]-1);
        update(ara[i],1);
    }

    int max_u=-1,max_d=-1;
    int pos_u,pos_d;

    int prev_inv=0;
    int new_inv=0;

    for(i=0;i<N;i++){
        if(max_d<=inv_d[i]){
            max_d=inv_d[i];
            pos_d=i;
        }
        if(max_u<inv_u[i]){
            max_u=inv_u[i];
            pos_u=i;
        }
        prev_inv+=inv_d[i];
    }

    /*for(i=0;i<N;i++){
        printf("%d %d\n",inv_u[i],inv_d[i]);
    }*/


    if(pos_u!=pos_d) swap(ara[pos_u],ara[pos_d]);


    CLR(bit);CLR(inv_u);CLR(inv_d);

    for(i=N-1;i>=0;i--){
        inv_u[i]=query(ara[i]-1);
        update(ara[i],1);
        new_inv+=inv_u[i];
    }



    if(prev_inv<=new_inv) printf("Cool Array\n");
    else printf("%d %d\n",min(pos_u+1,pos_d+1),max(pos_u+1,pos_d+1));

    return 0;
}
