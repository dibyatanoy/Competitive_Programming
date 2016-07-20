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
#define INF 1000000000
#define eps 1e-9
#define CLR(x) memset(x,0,sizeof(x))
#define pb push_back
#define all(x) x.begin(), x.end()
#define Fr first
#define Sc second
#define MAXX 600000
#define pi 2*acos(0.0)
#define ll long long

using namespace std;

ll int N,A,B,C;
ll int best[8];

int main(){

    ll int cost,cost2;
    int i,j,kases;

    scanf("%d",&kases);

    while(kases--){
        scanf("%lld %lld %lld %lld",&N,&A,&B,&C);
        cost=0;
        cost2=0;

        ll int N2=N;

        ll int mx=max(max(A,B),C);
        ll int mn=min(min(A,B),C);



        ll int sum=A+B+C;
        ll int mid=sum-mx-mn;

        best[1]=mn;
        best[2]=max(mn,mid);
        best[3]=min(max(mn+mid,mid),mx);
        best[4]=min(max(mn*2,mx),max(mid,mn+best[3]));

        while(N>4){
            N=(ll) (roundf((double)mx/double(sum)*(double)N));
            //printf("%lld %lld\n",N,cost);
            cost+=mn;
        }

        //printf("!  %lld %lld\n",N,cost);
        cost+=best[N];

        while(N2>4){
            N2=(ll) (floor((double)mn/double(sum)*(double)N2));
            cost2+=mx;
        }

        cost2+=best[N2];

        printf("%lld\n",max(cost,cost2));
    }


    return 0;
}
