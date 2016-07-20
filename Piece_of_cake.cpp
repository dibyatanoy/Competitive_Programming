#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))
#define all(v) v.begin(),v.end()
#define MP make_pair
#define fr first
#define sc second
#define MAXX 110
#define INF 10000000

using namespace std;
int cnt[100];

int main(){

    string s;
    int n;
    cin>>n;

    while(n--){
    cin>>s;

    CLR(cnt);

    int i;
    bool fnd=false;
    for( i=0;i<s.size();i++){
        cnt[s[i]-'a']++;
    }

    for(i=0;i<s.size();i++){
        if(cnt[s[i]-'a']==s.size()-cnt[s[i]-'a']){
            fnd=true;
            break;
        }
    }
    if(fnd) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }

    return 0;
}
