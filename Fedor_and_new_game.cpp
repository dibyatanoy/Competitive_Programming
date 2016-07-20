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
#define MAXX 1005
#define INF 100000000
#define ll long long
#define MOD 1000000007
#define Fr first
#define Sc second

using namespace std;

int n,m,k,cnt=0;
string fed,curr;
int idx[MAXX];

int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}

void solve(int pos){
    int diff=0;
    int tmp=idx[pos];
    curr.clear();

    while(tmp!=0){
        curr+= (tmp%2)? "1":"0";
        tmp/=2;
    }

    while(curr.size()<n){
        curr+="0";
    }
    //cout<<curr<<endl;

    for(int i=0;i<n;i++){
        if(fed[i]!=curr[i]){
            diff++;
        }
    }
    if(diff<=k) cnt++;
    return;
}

int main(){

    scanf("%d %d %d",&n,&m,&k);
    int i,j,k;

    for(i=1;i<=m+1;i++){
        scanf("%d",&idx[i]);
    }

    int tmp=idx[m+1];
    fed.clear();

    while(tmp!=0){
        fed+= (tmp%2)? "1":"0";
        tmp/=2;
    }

    while(fed.size()<n){
        fed+="0";
    }



    for(i=1;i<=(m);i++){
        solve(i);
    }

    printf("%d\n",cnt);

    return 0;
}
