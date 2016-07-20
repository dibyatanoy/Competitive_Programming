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
#define MOD 1000000007
#define MAXX 32
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define all(v) v.begin(),v.end()
#define MP make_pair
#define PII pair<int,int >
#define ll long long

using namespace std;
int N,seq[MAXX],d;
long long int dp[MAXX][150][150][2];
bool vis[MAXX][150][150][2];

long long int call(int pos,int odd,int even,int par){
    if(pos>=N){
        if(abs(odd-even)<=d) return 1;
        else return 0;
    }
    if(vis[pos][odd][even][par]) return dp[pos][odd][even][par];

    long long int ret=0;
    if(par){
        ret=call(pos+1,odd^seq[pos],even,1-par)%1000000007;
    }else ret=call(pos+1,odd,even^seq[pos],1-par)%1000000007;

    ret=(ret+call(pos+1,odd,even,par))%1000000007;

    vis[pos][odd][even][par]=1;
    return dp[pos][odd][even][par]=ret;
}

int main(){

    int i,j,k;

    scanf("%d %d",&N,&d);


    for(i=0;i<N;i++) cin>>seq[i];
    memset(vis,0,sizeof(vis));

    cout<<call(0,0,0,1)<<endl;

    return 0;
}
