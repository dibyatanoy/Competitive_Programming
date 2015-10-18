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
#define MAXX 30
#define pi 2*acos(0.0)

using namespace std;
int ara[MAXX],N;
int ans;
int dp[40][100000];
bool vis[40][100000];
int sum[40];

int call(int pos,int xor_val){
    //printf("Here: %d %d\n",pos,xor_val);
    if(pos==N){
        if(xor_val==0) return 1;
        return 0;
    }
    if(vis[pos][xor_val]) return dp[pos][xor_val];

    int ways=0;

    for(int i=pos;i<N;i++){

        //printf("Calling %d %d",i+1,(sum[i]-(pos==0? 0: sum[pos-1]))^xor_val);

        ways+=call(i+1,(sum[i]-(pos==0? 0: sum[pos-1]))^xor_val);

    }

    vis[pos][xor_val]=1;
    return dp[pos][xor_val]=ways;

}

void solve(int pos, int prev, int xor_sum){

    if(pos==N){
        if(prev) xor_sum^=prev;
        if(!xor_sum) {ans++;}
        return;
    }


    solve(pos+1,prev+ara[pos],xor_sum);

    solve(pos+1,0,xor_sum^(prev+ara[pos]));

    return;
}

int main(){

    int i,j,k;

    scanf("%d",&N);

    CLR(sum);
    for(i=0;i<N;i++){
        scanf("%d",&ara[i]);
        sum[i]= ((i==0)? 0:sum[i-1])+ara[i];
    }

    ans=0;
    CLR(vis);
    if(N<=20) {solve(0,0,0);ans/=2;}
    ans=call(0,0);

    printf("%d\n",ans);

    return 0;
}
