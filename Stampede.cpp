#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))
#define all(v) v.begin(),v.end()
#define MAXX 52000
#define ll long long

using namespace std;

struct data2{
    int x,y,r;

    bool operator <(const data2 &p)const{
        return y<p.y;
    }
};

struct seg{
    long long int sum;
    long long int lazy;
    bool is_lzy;
};

seg data[4*2*MAXX];

int N;
vector <data2> cows;
int st[MAXX],ed[MAXX];
vector <int> times;

void update_node(int idx,int st,int ed,int val){
    data[idx].sum=1;
    data[idx].lazy=(long long)1;
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

    if(st>ed) return;
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
    data[idx].sum=data[l].sum && data[r].sum;
    return;
}

seg query(int idx,int st,int ed,int i,int j){
    if(st>ed){
        seg tmp;
        tmp.sum=0;
        return tmp;
    }
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
        a.sum=b.sum && c.sum;
    }
    return a;
}

int main(){

    int i,j,k;
    data2 tmp;

    freopen("stampede.in","r",stdin);
    freopen("stampede.out","w",stdout);

    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%d %d %d",&tmp.x,&tmp.y,&tmp.r);
        cows.pb(tmp);
        //printf("%d\n",cows[cows.size()-1].r);
    }
    sort(cows.begin(),cows.end());

    //printf("%d %d %d\n",cows[0].x,cows[0].y,cows[0].r);

    for(i=0;i<N;i++){
        //printf("%d %d %d\n",st[i],ed[i],cows[i].r);

        int dur=(0-cows[i].x-1)*cows[i].r;
        st[i]=dur;
        ed[i]=dur+cows[i].r;

        //printf("%d %d %d\n",st[i],ed[i],cows[i].r);
        times.pb(st[i]);
        times.pb(ed[i]);
    }
    sort(all(times));

    unique(times.begin(),times.end());

    //for(i=0;i<times.size();i++) printf("%d ",times[i]);
    //cout<<endl;

    for(i=0;i<N;i++){
        st[i]=lower_bound(times.begin(),times.end(),st[i])-times.begin()+1;
        ed[i]=lower_bound(times.begin(),times.end(),ed[i])-times.begin()+1;
    }

    CLR(data);
    int seen=0;

    //printf("%d %d %d %d %d %d\n",st[0],ed[0],st[1],ed[1],st[2],ed[2]);

    for(i=0;i<N;i++){
        if(!query(1,1,2*N,st[i]+1,ed[i]).sum){
            seen++;
        }
        inserts(1,1,2*N,st[i]+1,ed[i],1);
    }

    printf("%d\n",seen);

    return 0;
}
