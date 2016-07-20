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
#define ll long long
#define MAXX 100005
#define INF 10000000000000000LL
#define Fr first
#define Sc second

using namespace std;
int n;
ll a[MAXX],b[MAXX];
ll dp[MAXX];
vector < pair<int,ll> >dq;

ll finds(int x){
    int lo=0, hi=dq.size()-1;

    while(lo<=hi){
        if(lo==hi) return dq[lo].Fr;
        else if(hi==lo+1){
            if(dq[hi].Sc>x) return dq[lo].Fr;
            else return dq[hi].Fr;
        }

        int mid=(lo+hi)/2;

        if(dq[mid].Sc>x){
            hi=mid;
        }else lo=mid;
    }
}

void add(int idx){

    int s1,s2;

    while((int)dq.size()>=2){
        s2=dq[dq.size()-1].Fr;
        s1=dq[dq.size()-2].Fr;

        double x1= (double)(dp[idx]-dp[s1])/(double)(b[s1]-b[idx]);
        double x2= (double)(dp[s2]-dp[s1])/(double)(b[s1]-b[s2]);

        if(x1>x2) break;
        else dq.erase(dq.end()-1);
    }

    s2=dq[dq.size()-1].Fr;
    ll x2=(ll)ceil((double)(dp[idx]-dp[s2])/(double)(b[s2]-b[idx]));

    dq.pb(MP(idx,x2));
    return;
}

int main(){

    int i,j,k;
    scanf("%d",&n);

    for(i=0;i<n;i++) scanf("%I64d",&a[i]);
    for(i=0;i<n;i++) scanf("%I64d",&b[i]);

    dq.pb(MP(0,-INF));

    for(i=1;i<n;i++){
        int pos=finds(a[i]);
        dp[i]=(ll)(b[pos]*a[i]+dp[pos]);
        add(i);
    }

    printf("%I64d\n",dp[n-1]);

    return 0;
}
