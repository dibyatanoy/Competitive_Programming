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
#define MAXX 1000005
#define INF 10000000000000000LL
#define Fr first
#define Sc second
#define off 2*MAXX

using namespace std;

int cnt[5*MAXX];
int N;
char tmp;

int main(){

    int i,j,k;

    scanf("%d",&N);
    CLR(cnt);
    getchar();

    int sum=0;
    ll ans=0;
    cnt[0+off]=1;

    for(i=0;i<N;i++){
        scanf("%c",&tmp);
        //cout<<tmp<<endl;
        if(tmp=='C') sum+=1;
        else sum-=2;

        //cout<<cnt[sum+off]<<endl;

        ans+=(ll)cnt[sum+off];
        cnt[sum+off]++;
    }

    printf("%lld\n",ans);
    return 0;
}

/** AC!!! **/
