#include <bits/stdc++.h>
#define MAXX 110
#define CLR(X) memset(X, 0, sizeof(X))
#define all(v) v.begin(),v.end()
#define eps 1e-9
#define INF 1e6

using namespace std;
double dp[MAXX][MAXX*MAXX];
bool vis[MAXX][MAXX*MAXX];
int N, M[MAXX], target;
double p[MAXX], P_max;

double call(int pos, int val){
    if(val==0) return 0;
    if(pos>=N & val!=0) return INF;
    if(pos>=N) return 0;
    if(vis[pos][val]) return dp[pos][val];

    double ret;
    if(val-M[pos]>=0) ret=call(pos+1,val-M[pos]);
    else ret=INF;
    double ans = min(call(pos+1,val), ret+(1-ret)*p[pos]);
    //printf("! %lf\n",ans);

    vis[pos][val]=1;
    return dp[pos][val]=ans;
}

int main(){

    int kases,i,j,k;

    scanf("%d",&kases);

    for(i=0;i<kases;i++){

        int sum=0;
        scanf("%lf %d",&P_max,&N);

        for(j=0;j<N;j++) {scanf("%d %lf",&M[j],&p[j]);sum+=M[j];}

        int lo=1,hi=sum;
        int last=-2;

        for(j=0;j<=sum;j++){
            if(!vis[0][j]) {call(0,j);}
        }
        int ans=0;
        /*for(j=0;j<=sum;j++){
            printf("%lf ",dp[0][j]);
        }*/
        CLR(vis);
        for(j=0;j<=sum;j++){
            if(dp[0][j]<P_max && dp[0][j]>=0.0) ans=j;
        }

        /*while(lo<=hi){
            int mid=(lo+hi)/2;
            CLR(vis);
            target=mid;
            double min_p=call(0,0);
            //printf("%d %lf\n", mid, min_p);

            if(min_p<1.1 && min_p-P_max > 0) hi=mid-1;
            else {last=max(last,mid);lo=mid+1;}
        }*/
        printf("Case %d: %d\n", i+1, ans);
    }

    return 0;
}

/** AC!!! **/
