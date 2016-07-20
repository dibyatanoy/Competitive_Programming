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
#define MAXX 500000
#define INF 10000000000000000LL
#define Fr first
#define Sc second

using namespace std;

int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}

int main(){

    int N,i,j,ans=0;

    scanf("%d",&N);
    N++;

    for(i=1;i<=(int)(N/2);i++){
        if(gcd(i,N)==1) ans++;
    }
    if((N-1)!=1) printf("%d\n",2*ans);
    else printf("%d\n",ans);

    return 0;
}

/** AC!!! **/
