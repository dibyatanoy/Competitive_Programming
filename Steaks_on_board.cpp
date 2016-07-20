#include <bits/stdc++.h>
#define MAXX 102
#define INF 10000

using namespace std;

int n,x,k,times[MAXX];
int dp[1002][MAXX];
bool vis[1002][MAXX];

int call(int t,int pos){

    if(pos==n) return 0;
    if(vis[t][pos]) return dp[t][pos];

    int ret=INF,i,s=0;

    i=pos+1;
    if(t>=times[i]-2){
            dp[t][pos]=ret;
            return dp[t][pos];
    }

    s=0;
    for(i=pos+1;i<=n;i++){
        if(times[i]-x>t) break;
        s++;
        int c=max(2,int(ceil(s*2/k)));

        if(c+t>=times[i]) break;
        ret=min(ret,call(t+c,i)+(times[i]-1-t-c));
    }
    ret=min(t+1,pos);

    vis[t][pos]=1;
    return dp[t][pos]=ret;
}

int main(){

    cin>>x>>k;
    cin>>n;

    int i,j,k;

    for(i=1;i<=2*n;i++) {cin>>times[i];times[i++]=times[i-1];}

    memset(vis,0,sizeof(vis));

    cout<<call(0,0)<<endl;

    return 0;
}
