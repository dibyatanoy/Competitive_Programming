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
#define ll long long
#define MAXX 55000
#define INF 10000000000000000LL
#define Fr first
#define Sc second

using namespace std;

struct data{
    int l,w;
    bool operator <(const data &p)const{
        return (p.l==l)? w>p.w: l<p.l;
    }
};
data rect[MAXX];
ll pro_l[MAXX],pro_w[MAXX];
ll b[MAXX],dp[MAXX];
int N;

vector< pair<int,ll> > dq;

ll finds(int x){
    int lo=0, hi=dq.size()-1;

    while(lo<=hi){
        if(lo==hi) return dq[lo].Fr;
        else if(hi==lo+1){
            if(dq[hi].Sc>x) return dq[lo].Fr;
            else return dq[hi].Fr;
        }

        int mid=(lo+hi)/2;

        if(dq[mid].Sc>x){
            hi=mid;
        }else lo=mid;
    }
}

void add(int idx){

    int s1,s2;

    while((int)dq.size()>=2){
        s2=dq[dq.size()-1].Fr;
        s1=dq[dq.size()-2].Fr;

        double x1= (double)(dp[idx]-dp[s1])/(double)(b[s1+1]-b[idx+1]);
        double x2= (double)(dp[s2]-dp[s1])/(double)(b[s1+1]-b[s2+1]);

        if(x1>x2) break;
        else dq.erase(dq.end()-1);
    }

    s2=dq[dq.size()-1].Fr;
    ll x2=(ll)ceil((double)(dp[idx]-dp[s2])/(double)(b[s2+1]-b[idx+1]));

    dq.pb(MP(idx,x2));
    return;
}

int main(){

    scanf("%d",&N);
    int i,j=1,k;

    for(i=0;i<N;i++) scanf("%d %d",&rect[i].w,&rect[i].l);

    sort(rect,rect+N);

    pro_l[j]=(ll)rect[0].l;
    b[j++]=(ll)rect[0].w;
    for(i=1;i<N;i++){
        while(j>1 && rect[i].w>=b[j-1]) j--;
        pro_l[j]=(ll)rect[i].l;
        b[j++]=(ll)rect[i].w;
    }

    dq.pb(MP(0,-INF));
    dp[0]=0;

    for(i=1;i<j;i++){
        int pos=finds(pro_l[i]);
        //cout<<pos<<endl;
        dp[i]=min((ll)(dp[pos]+b[pos+1]*pro_l[i]),(ll)(dp[0]+b[1]*pro_l[i]));
        add(i);
    }

    cout<<dp[j-1]<<endl;

    return 0;
}
