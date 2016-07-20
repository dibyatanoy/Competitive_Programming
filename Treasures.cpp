#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define MAXX 1005
#define INF 1e8

using namespace std;

struct data{
    int tx,ty,lx,rx,p,r_id;

    bool operator <(const data&p)const{
        return lx<p.lx;
    }
};

int rt[MAXX];
data T[MAXX];
int dp[MAXX][MAXX],N;
bool vis[MAXX][MAXX];

int call(int pos,int r){
    if(pos==N) return 0;
    if(vis[pos][r]) return dp[pos][r];

    int cost;

    if(T[pos].lx>rt[r]){
        cost=T[pos].p-T[pos].ty*T[pos].ty;
        dp[pos][r]=max(call(pos+1,r),call(pos+1,T[pos].r_id)+cost);
    }else if(T[pos].rx<=rt[r]) dp[pos][r]=call(pos+1,r)+T[pos].p;
    else{
        int l=T[pos].rx-rt[r]+1;
        if(l%2==0) cost=T[pos].ty*T[pos].ty-(l*l/4+l/2);
        else cost=T[pos].ty*T[pos].ty-(l+1)*(l+1)/4;

        cost=T[pos].p-cost;
        dp[pos][r]=max(call(pos+1,r),call(pos+1,T[pos].r_id)+cost);
    }

    vis[pos][r]=1;
    return dp[pos][r];
}

int main(){

    int i,j,rt_cnt=1;

    scanf("%d",&N);

    for(i=0;i<N;i++){
        cin >> T[i].tx >> T[i].ty >> T[i].p;
        T[i].ty=-T[i].ty;
        T[i].lx=T[i].tx-T[i].ty+1;
        T[i].rx=T[i].tx+T[i].ty-1;
        T[i].r_id=rt_cnt;
        rt[rt_cnt++]=T[i].rx;
    }

    rt[0]=-INF;
    sort(T,T+N);

    int ans=max(call(0,0),0);

    cout << ans <<endl;

    return 0;
}
