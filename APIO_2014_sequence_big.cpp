#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define INF 1e12
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define all(v) v.begin(),v.end()
#define MAXX 205
#define MAXXN 10004
#define PII pair <int,int >
#define ll long long
#define MP make_pair

using namespace std;

int N,K;
int seq[MAXXN];
long long int dp[MAXXN][MAXX];
bool vis[MAXXN][MAXX];
long long int sums[MAXXN];
int dir[MAXXN][MAXX];

void print(int last,int left){
    if(left==0) return;
    print(dir[last][left],left-1);

        if(left==K) printf("%d",dir[last][left]);
        else printf("%d ",dir[last][left]);
        return;
}

long long int call(int last,int left){
    if(left==0) return 0;
    if(last==1) return -INF;

    if(vis[last][left]) return dp[last][left];

    long long ret=-INF;
    long long int temp;

    int i;

    for(i=1;i<last;i++){
        temp=call(i,left-1)+sums[i]*(sums[last]-sums[i]);
        if(temp>=ret){
            ret=temp;
            dir[last][left]=i;
        }
    }
    vis[last][left]=1;
    return dp[last][left]=ret;
}

int main(){

    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);

    scanf("%d %d",&N,&K);

    int i,j;
    sums[0]=0;
    memset(vis,0,sizeof(vis));
    memset(dir,0,sizeof(dir));

    for(i=1;i<=N;i++){
        scanf("%d",&seq[i]);
        sums[i]=sums[i-1]+seq[i];
    }

    cout<<call(N,K)<<endl;
    print(N,K);
    cout<<endl;

    return 0;
}
