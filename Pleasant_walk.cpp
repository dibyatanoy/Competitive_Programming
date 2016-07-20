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
#define INF 100000000
#define eps 1e-9
#define CLR(x) memset(x,0,sizeof(x))
#define pb push_back
#define all(x) x.begin(), x.end()
#define Fr first
#define Sc second
#define MAXX 120
#define pi 2*acos(0.0)

using namespace std;
int R,C;
int dp[MAXX][MAXX];
bool vis[MAXX][MAXX];
int down[MAXX][MAXX],rt[MAXX][MAXX];

int call(int i,int j){
    if(i==R && j==C) return 0;
    if(i>R || j>C) return -INF;
    if(vis[i][j]) return dp[i][j];

    int ret=0;

    ret=max(call(i+1,j)+down[i][j],call(i,j+1)+rt[i][j]);

    vis[i][j]=1;

    return dp[i][j]=ret;
}

int main(){

    int i,j,k;

    scanf("%d %d",&R,&C);

    CLR(vis);CLR(down);CLR(rt);

    for(i=0;i<R;i++){


            for(j=0;j<C;j++){
                scanf("%d",&rt[i][j]);
            }

            for(j=0;j<=C;j++){
                scanf("%d",&down[i][j]);
            }

    }
    for(j=0;j<C;j++) scanf("%d",&rt[i][j]);

    printf("%d\n",call(0,0));

    return 0;
}
