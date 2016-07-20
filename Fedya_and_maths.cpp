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
#define PII pair <int,int >
#define ll long long
#define MAXX 120000
#define INF 10000000000LL
#define Fr first
#define Sc second

using namespace std;

string s;
int d[3][4];

int main(){

    int i,j,last;

    d[0][0]=1;d[0][1]=2;d[0][2]=4;d[0][3]=3;
    d[2][0]=1;d[2][1]=3;d[2][2]=4;d[2][3]=2;
    d[1][0]=1;d[1][1]=4;

    cin>>s;
    int sz=s.size();

    last=s[sz-1]-'0';
    if (sz>1) last+=(s[sz-2]-'0')*10;
    //printf("%d\n",last);

    int ans=1+d[0][last%4]+d[2][last%4]+d[1][last%2];

    printf("%d\n",ans%5);

    return 0;
}
