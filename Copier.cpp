#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#define pb push_back
#define ll long long int
#define MP make_pair
#define CLR(a) memset(a,0,sizeof(a))
#define READ(x) freopen(x,"r",stdin)
#define WRITE(x) freopen(x,"w",stdout)
#define INF 1e8
#define MAXX 100005

using namespace std;

int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}
bool taken[MAXX];
vector <int> ans;

int main(){

    READ("c2.in");
    WRITE("c2.out");

    int kases,i,j;

    scanf("%d",&kases);

    while(kases--){
        int n,curr;
        cin>>n;
        ans.clear();
        CLR(taken);

        while(n--){
            cin>>curr;
            if(!taken[curr]){
                taken[curr]=1;
                ans.pb(curr);
            }
        }
        cout<<ans[0];
        for(i=1;i<ans.size();i++) cout<<" "<<ans[i];
        cout<<endl;
    }

    return 0;
}
