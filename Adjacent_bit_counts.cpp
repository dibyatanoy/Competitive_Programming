#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))
#define all(v) (v.begin(),v.end())
#define INF 1e8
#define MAXX 105

using namespace std;
int dp[MAXX][MAXX][2];
bool vis[MAXX][MAXX][2];
int N,K;

int call(int pos, int cnt, int flag){
    //if(cnt<=0) return 1;
    if(pos<=1) return (cnt)? 0:1;
    if(vis[pos][cnt][flag]) return dp[pos][cnt][flag];

    int ret=0;

    if(cnt>0){
        if(flag){
            ret=call(pos-1,cnt-1,1)+call(pos-1,cnt,0);
        }else ret=call(pos-1,cnt,0)+call(pos-1,cnt,1);
    }else{
        if(flag){
            ret=call(pos-1,cnt,0);
        }else{
            ret=call(pos-1,cnt,0)+call(pos-1,cnt,1);
        }
    }


    vis[pos][cnt][flag]=1;

    return dp[pos][cnt][flag]=ret;

}


int main(){

    int i,j,k;
    int p;

    scanf("%d",&p);
    CLR(vis);

    while(p--){
        scanf("%d %d %d",&i,&N,&K);

        printf("%d %d\n",i,call(N,K,0)+call(N,K,1));
    }
    return 0;
}

/** AC!!! **/
