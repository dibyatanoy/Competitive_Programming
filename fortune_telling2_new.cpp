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
int A[MAXX],B[MAXX],T[MAXX];
vector <ll> nums;
int N,K,last[MAXX],flip[MAXX];
bool init_flip[MAXX],fin[MAXX];
int qry[8*MAXX];
vector < pair<int,int> > sorted;
int bit[MAXX];

void update_bit(int pos,int val){
    int i;
    for(i=pos;i<MAXX;i+=(i & -i)){
        bit[i]+=val;
    }
    return;
}

int query_bit(int pos){
    int i,ret=0;
    if(pos<1) return 0;
    for(i=pos;i>0;i-=(i & -i)){
        ret+=bit[i];
    }

    return ret;
}

void update1(int idx,int st,int ed,int pos,int val){
    if(st>ed) return;
    if(st==pos && ed==pos){
        qry[idx]=val;
        return;
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(pos<=mid) update1(l,st,mid,pos,val);
    else update1(r,mid+1,ed,pos,val);

    qry[idx]=max(qry[l],qry[r]);
    return;
}

int query_mx(int idx,int st,int ed,int i,int j){
    if(st>ed) return;
    if(st==i && ed==j){
        return qry[idx];
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(j<=mid) return query_mx(l,st,mid,i,j);
    else if(i>mid) return query_mx(r,mid+1,ed,i,j);
    else return max(query_mx(l,st,mid,i,mid),query_mx(r,mid+1,ed,mid+1,j));
}

int main(){

    int i,j;

    scanf("%d %d",&N,&K);

    for(i=0;i<N;i++){
        scanf("%d %d",&A[i],&B[i]);
        nums.pb(A[i]);
        nums.pb(B[i]);
    }

    for(i=0;i<K;i++){
        scanf("%d",&T[i]);
        nums.pb(T[i]);
    }
    sort(all(nums));

    for(i=0;i<N;i++){
        A[i]=lower_bound(all(nums),A[i])-nums.begin()+1;
        B[i]=lower_bound(all(nums),B[i])-nums.begin()+1;
    }
    for(i=0;i<K;i++){
        T[i]=lower_bound(all(nums),T[i])-nums.begin()+1;
    }
    memset(qry,-1,sizeof(qry));

    for(i=0;i<K;i++) update1(1,1,MAXX,T[i],i+1);

    for(i=0;i<N;i++){
        if(A[i]>B[i]){
            init_flip[i]=1;
            swap(A[i],B[i]);
        }
    }

    for(i=0;i<N;i++){
        last[i]=query_mx(1,1,MAXX,A[i],B[i]-1);
        sorted.pb(MP(last[i],i));
    }
    sort(all(sorted));
    reverse(all(sorted));

    int q=K+1;

    for(i=0;i<sorted.size();i++){
        while(q>sorted[i].Fr+1){
            q--;
            update_bit(T[q],1);
        }
        flip[sorted[i].Sc]=query(MAXX)-query(B[i]-1);
    }

    for(i=0;i<N;i++){
        int p;
        if(last[i]==-1){
            p=flip[i]%2;
            if(!p) fin[i]=A[i];
            else fin[i]=B[i];
        }else{
            p=flip[i]%2;
            if(init_flip[i]){
                if(!p) fin[i]=A[i];
                else fin[i]=B[i];
            }else{
                if(!p) fin[i]=B[i];
                else fin[i]=A[i];
            }
        }
    }

    int ans=0;
    for(i=0;i<N;i++){
        ans+=fin[i];
    }

    printf("%d\n",ans);

    return 0;
}
