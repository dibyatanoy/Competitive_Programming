#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define MAXX 100005
#define INF 1e8
#define CLEAR(x) memset((x),0,sizeof((x))
#define pb push_back
#define ll long long int
#define ALL(v) v.begin(),v.end()

using namespace std;
char s[MAXX];

int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}

int main(){

    long long int a[4];

    int i,j;
    long long int ans=0;

    for(i=0;i<4;i++) cin>>a[i];

    scanf("%s",s);

    for(i=0;i<strlen(s);i++){
        ans+=a[s[i]-'1'];
    }
    cout<<ans<<endl;

    return 0;
}
