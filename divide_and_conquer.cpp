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
#define MAXX 100004
#define ll long long

using namespace std;

struct data{
    long long int diff;
    int pos;

    bool operator <(const data &p)const{
        return diff<p.diff;
    }
    bool operator ==(const data &p)const{
        return diff==p.diff;
    }
};

int N,x[MAXX],g[MAXX],d[MAXX];
long long int sum[MAXX],sum_g[MAXX];
vector <data> prefs;

int main(){

    int i,j;

    freopen("divide.in","r",stdin);
    freopen("divide.out","w",stdout);

    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%d%d%d",&x[i],&g[i],&d[i]);
        sum[i]=d[i]+((i==0)? 0:sum[i-1]);
        sum_g[i]=g[i]+((i==0)? 0:sum_g[i-1]);
    }


    long long int ans=0;
    data temp;
    temp.diff=0;temp.pos=-1;
    prefs.push_back(temp);

    for(i=0;i<N;i++){
        long long int c=x[i]-sum[i];
        if(d[i]==1) ans=max(ans,(long long)(g[i]));
        //cout<<c<<" ";
        temp.diff=c;

        int l=lower_bound(prefs.begin(),prefs.end(),temp)-prefs.begin();

        if(l!=prefs.size()){
            //cout<<l<<endl;
            if(prefs[l].pos==-1) ans=max((ll)(ans),sum_g[i]);
            else ans=max((ans),sum_g[i]-sum_g[prefs[l].pos]);
        }

        c=x[i+1]-sum[i];
        if(c>prefs[prefs.size()-1].diff){
            temp.diff=c;
            temp.pos=i;
            prefs.push_back(temp);
        }
    }

    cout<<ans<<endl;

    return 0;
}

/** AC!!! **/
