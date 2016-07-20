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
#define INF 1e7
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define all(v) v.begin(),v.end()
#define MAXX 205
#define MAXXN 205
#define PII pair <int,int >
#define ll long long
#define MP make_pair

using namespace std;

int N,K;
int seq[MAXXN];
long long int dp[MAXXN][MAXXN][MAXX];
bool vis[MAXXN][MAXXN][MAXX];
long long int sums[MAXXN];
bool dir[MAXXN][MAXXN][MAXX];

void print(int pos,int last,int left){
    if(left==0) return;
    if(dir[pos][last][left]){
        print(pos-1,pos,left-1);
        if(left==K) printf("%d",pos);
        else printf("%d ",pos);
        return;
    }else {
        print(pos-1,last,left);
        return;
    }

}

long long int call(int pos,int last,int left){
    if(left==0) return 0;
    if(pos==0) return -INF;

    if(vis[pos][last][left]) return dp[pos][last][left];

    long long int ret1=call(pos-1,pos,left-1)+sums[pos]*(long long)(sums[last]-sums[pos]);
    long long int ret2=call(pos-1,last,left);

    if(ret1>=ret2){
        dir[pos][last][left]=1;

    }else dir[pos][last][left]=0;

    vis[pos][last][left]=1;
    return dp[pos][last][left]=max(ret1,ret2);
}

int main(){

    //freopen("sequence.in","r",stdin);
    //freopen("sequence.out","w",stdout);

    scanf("%d %d",&N,&K);

    int i,j;
    sums[0]=0;
    memset(vis,0,sizeof(vis));
    memset(dir,0,sizeof(dir));

    for(i=1;i<=N;i++){
        scanf("%d",&seq[i]);
        sums[i]=sums[i-1]+seq[i];
    }

    cout<<call(N-1,N,K)<<endl;
    print(N-1,N,K);
    cout<<endl;

    return 0;
}
