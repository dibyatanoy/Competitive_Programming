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
#define all(v) v.begin(),v.end()
#define PII pair <int,int >
#define ll long long
#define MAXX 100005
#define INF 1000000000000LL
#define Fr first
#define Sc second

using namespace std;

int seq[MAXX],a[MAXX],cnt[MAXX],N;
long long int dp[MAXX];
bool vis[MAXX];

long long int call(int pos){
    if(pos<0) return 0;
    if(pos==0) return cnt[0]*a[0];

    if(vis[pos]) return dp[pos];

    if(a[pos]==a[pos-1]+1){
        dp[pos]=max(call(pos-1),call(pos-2)+(long long)cnt[pos]*(long long)a[pos]);
    }else{
        dp[pos]=call(pos-1)+(long long)(a[pos])*(long long)cnt[pos];
    }

    vis[pos]=1;
    return dp[pos];
}

int main(){

    int i,j,k;

    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%d",&seq[i]);
    }
    sort(seq,seq+N);

    int c_cnt=0,idx=0;
    c_cnt=1;

    for(i=1;i<N;i++){
        if(seq[i]==seq[i-1]){
            c_cnt++;
        }else{
            a[idx]=seq[i-1];
            cnt[idx++]=c_cnt;
            c_cnt=1;
        }
    }


        a[idx]=seq[N-1];
        cnt[idx++]=c_cnt;


    memset(dp,-1,sizeof(dp));
    memset(vis,0,sizeof(vis));

    //for(i=0;i<N;i++) printf("%d %d\n",a[i],cnt[i]);

    printf("%I64d\n",call(idx-1));

    return 0;
}
