#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <utility>
#include <deque>
#define pb push_back
#define all(v) v.begin(), v.end()
#define MP make_pair
#define CLR(x) memset((x),0,sizeof((x)))
#define INF 1000000
#define MAXX 71
#define MOD 1000000007
#define ll long long

using namespace std;
char grid[MAXX][MAXX];
ll int dp[MAXX][MAXX][MAXX][MAXX];
bool vis[MAXX][MAXX][MAXX][MAXX];
int N;

int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}

ll int call(int x1, int y1,int x2, int y2){
    if(x1>=N || y1>=N || x2<0 || y2<0) return 0;
    if(vis[x1][y1][x2][y2]) return dp[x1][y1][x2][y2];
    if((x1==x2)&(y1==y2)) return 1;
    if((x2==x1+1 && y1==y2) || (x1==x2) && (y2==y1+1)) return 1;
    if(x2<x1 || y2<y1) return 0;

    ll int ret=0;

    if(grid[x1+1][y1]==grid[x2-1][y2]) ret=(ret+call(x1+1,y1,x2-1,y2))%MOD;
    if(grid[x1+1][y1]==grid[x2][y2-1]) ret=(ret+call(x1+1,y1,x2,y2-1))%MOD;
    if(grid[x1][y1+1]==grid[x2-1][y2]) ret=(ret+call(x1,y1+1,x2-1,y2))%MOD;
    if(grid[x1][y1+1]==grid[x2][y2-1]) ret=(ret+call(x1,y1+1,x2,y2-1))%MOD;

    dp[x1][y1][x2][y2] = ret;
    vis[x1][y1][x2][y2] = 1;
    return dp[x1][y1][x2][y2];
}

int main(){

    int i,j,k;

    freopen("palpath.in","r",stdin);
    freopen("palpath.out","w",stdout);

    CLR(vis);

    scanf("%d",&N);

    for(i=0;i<N;i++) scanf("%s",grid[i]);

    if(grid[0][0]!=grid[N-1][N-1]) printf("0\n");
    else printf("%d\n",call(0,0,N-1,N-1));


    return 0;
}
