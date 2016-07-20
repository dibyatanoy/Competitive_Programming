#include <bits/stdc++.h>
#define CLEAR(a) memset(a,0,sizeof(a))
#define pb push_back
#define MAXX 1002

using namespace std;

int N,K,nums[1002][3];
long long int dp[MAXX][MAXX][9];
bool vis[MAXX][MAXX][9];

int Set(int N,int pos){return N= N|(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

long long int call(int pos,int left,int mask){
    if(left==0) return 0;
    if(pos==N) return 0;
    if(vis[pos][left][mask]) return dp[pos][left][mask];

    long long int ret=-10000000;
    int temp=0;

    if(check(mask,0)==0 && check(mask,1)==0){
        temp=Set(mask,0);temp=Set(temp,1);
        ret=max(ret,max(call(pos,left-1,temp),call(pos+1,left-1,0))+nums[pos][0]+nums[pos][1]);
    }
    if(check(mask,2)==0 && check(mask,1)==0){
        temp=Set(mask,2);temp=Set(temp,1);
        ret=max(ret,max(call(pos,left-1,temp),call(pos+1,left-1,0))+nums[pos][2]+nums[pos][1]);
    }
    if(check(mask,0)==0 && pos<N-1){
        temp=Set(mask,0);
        ret=max(ret,max(call(pos,left-1,temp),call(pos+1,left-1,Set(0,0)))+nums[pos][0]+nums[pos+1][0]);
    }
    if(check(mask,1)==0 && pos<N-1){
        temp=Set(mask,1);
        ret=max(ret,max(call(pos,left-1,temp),call(pos+1,left-1,Set(0,1)))+nums[pos][1]+nums[pos+1][1]);
    }
    if(check(mask,2)==0 && pos<N-1){
        temp=Set(mask,2);
        ret=max(ret,max(call(pos,left-1,temp),call(pos+1,left-1,Set(0,2)))+nums[pos][2]+nums[pos+1][2]);
    }
    ret=max(ret,call(pos+1,left,0));

    vis[pos][left][mask]=1;
    return dp[pos][left][mask]=ret;

}

int main(){

    int i,j;
    //long long int ans;

    freopen("domine.in.1","r",stdin);

    scanf("%d%d",&N,&K);

    for(i=0;i<N;i++) scanf("%d %d %d",&nums[i][0],&nums[i][1],&nums[i][2]);
    CLEAR(vis);

    long long int ans=call(0,K,0);
    //printf("%d %d\n",N,K);

    //for(i=0;i<N;i++) printf("%d %d %d\n",nums[i][0],nums[i][1],nums[i][2]);

    //scanf("%lld",&ans);
    printf("%lld\n",ans);

    return 0;
}
