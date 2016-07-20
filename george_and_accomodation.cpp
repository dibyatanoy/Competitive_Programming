#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#define CLR(x) memset((x),0,sizeof((x)))
#define all(v) v.begin(),v.end()
#define pb push_back
#define MP make_pair
#define PII pair <int,int >
#define MAXX 100000
#define INF 100000000
#define ll long long
#define MOD 1000000007
#define Fr first
#define Sc second

using namespace std;

int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}

int main(){

    int p,q,N;

    int cnt=0;

    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%d %d",&p,&q);

        if(q-p>=2) cnt++;
    }

    printf("%d\n",cnt);

    return 0;
}

/** AC!!! **/
