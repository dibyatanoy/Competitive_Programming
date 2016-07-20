#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))
#define all(v) v.begin(),v.end()
#define INF 1e8
#define MAXX 1005

using namespace std;

int main(){

    int p,q,r,i,j,k,P;
    scanf("%d",&P);

    while(P--){
        cin>>k>>p>>q>>r;

        if((p+q+r)%2==1) cout<<k<<" L"<<endl;
        else cout<<k<<" W "<<p<<" 1"<<endl;
    }

    return 0;
}
