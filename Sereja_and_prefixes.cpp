#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define MAXX 100005
#define pb push_back

using namespace std;
int m,n,x[MAXX];
vector <int> type,l,c;
vector<long long> chain;

int main(){

    int i,j;
    int tmp;
    cin >> m;
    while(scanf("%d",&tmp) && tmp!=1){
        m--;
        continue;
    }
    scanf("%d",&x[0]);
    type.pb(1);
    c.pb(0);
    l.pb(0);
    chain.pb(1);
    for(i=1;i<m;i++){

        scanf("%d",&tmp);
        if(tmp==1){
            scanf("%d",&x[i]);
            type.pb(1);
            c.pb(0);
            l.pb(0);
            chain.pb(chain[i-1]+1);
        }else{
            int t_l,t_c;
            scanf("%d %d",&t_l,&t_c);
            type.pb(2);
            c.pb(t_c);
            l.pb(t_l);
            chain.pb(chain[i-1]+t_c*t_l);
        }
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        long long int qry;
        int now;
        cin >> qry;
        now=lower_bound(chain.begin(),chain.end(),qry)-chain.begin();
        while(type[now]!=1){
            qry=((qry-chain[now-1])%l[now]==0)? l[now]:(qry-chain[now-1])%l[now];
            now=lower_bound(chain.begin(),chain.end(),qry)-chain.begin();
        }
        if(i==1) cout<<x[now];
        else printf(" %d",x[now]);
    }
    printf("\n");

    return 0;
}

/** AC!!! **/
