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
int X,Y,M;
string s;

int main(){

    int t,i,j,k;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&M);

        cin>>s;
        //cout<<s<<endl;
        long long int ans=1;

        for(i=0;i<s.size();i++){
            if(s[i]=='*') continue;
            X=0;Y=0;

            while(s[i]!='*') {X=X*10+s[i]-'0';i++;}

            i+=2;

            while(s[i]!='*' && i<s.size()) {Y=Y*10+s[i]-'0';i++;}

            int cur=1;
            //printf("%d %d\n",X,Y);
            for(j=1;j<=Y;j++){
                cur=(cur*X)%M;
            }

            ans=(ans*cur)%M;

        }
        printf("%lld\n",ans%M);
    }

    return 0;
}
