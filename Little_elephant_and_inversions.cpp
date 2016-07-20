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
#define MAXX 100010
#define INF 10000000000000000LL
#define Fr first
#define L 0
#define R 1
#define Sc second

using namespace std;
int N;
long long int K,pairs;
int temp[MAXX],low[MAXX];
int seq[MAXX];
int bit[MAXX][2];

void update(int pos,int val,int idx){
    int i;
    for(i=pos;i<MAXX;i+=(i & -i)){
        bit[i][idx]+=val;
    }
    return;
}

int query(int pos,int idx){
    if(pos==0) return 0;
    int i,sum=0;
    for(i=pos;i>0;i-= (i & -i)){
        sum+=bit[i][idx];
    }
    return sum;
}

int main(){

    int i,j,k,st,ed;
    long long int c_inv=0;

    scanf("%d %I64d",&N,&K);
    pairs=0;
    CLR(bit);

    for(i=0;i<N;i++) {scanf("%d",&temp[i]);seq[i]=temp[i];}
    sort(temp,temp+N);

    for(i=0;i<N;i++) seq[i]=lower_bound(temp,temp+N,seq[i])-temp+1;

    st=0;ed=1;
    for(i=N-1;i>0;i--) {c_inv+=(ll)(query(seq[i]-1,R));low[i]=query(seq[i]-1,R);update(seq[i],1,R);}
    update(seq[0],1,L);
    c_inv+=(ll)query(seq[i]-1,R);

    //cout<<"!"<<endl;
    //cout<<c_inv<<endl;

    while(st<N && ed<N){


        while(c_inv>K && ed<N){
            c_inv-=(ll)(query(MAXX-1,L)-query(seq[ed],L)+low[ed]);
            update(seq[ed],-1,R);
            ed++;
        }
        //cout<<c_inv<<" ed="<<ed<<endl;
        pairs+=((N-ed)>0)? (ll)(N-ed):0;
        st++;
        if(st==ed){
            c_inv-=(ll)(query(MAXX-1,L)-query(seq[ed],L)+low[ed]);
            update(seq[ed],-1,R);
            ed++;
        }

        c_inv+=(ll)(query(seq[st]-1,R)+query(MAXX-1,L)-query(seq[st],L));
        //cout<<c_inv<<endl;
        update(seq[st],1,L);
    }

    printf("%I64d",pairs);

    return 0;
}

/** AC!!! **/
