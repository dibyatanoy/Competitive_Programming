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
#define ll long long
#define MAXX 100007
#define INF 10000000
#define Fr first
#define L 0
#define R 1
#define Sc second

using namespace std;

int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}

int a[MAXX];

int main(){

    int N,i,j,k;
    ll cnt=0;

    scanf("%d",&N);

    for(i=0;i<N;i++) scanf("%d",&a[i]);

    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            for(k=j+1;k<N;k++){
                if(gcd(a[i],gcd(a[k],a[j]))==1) cnt++;
            }
        }
    }
    printf("%lld\n",cnt);

    return 0;
}
