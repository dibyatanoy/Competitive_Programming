#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXX 252
#define INF 1000000

using namespace std;

int moves[MAXX*MAXX];
int seq[MAXX*MAXX],L[MAXX*MAXX];
vector <int> I;
int p,q,n;

int lis(int l){
    int i,j,lo,hi,mx=0;
    I.clear();
    I.push_back(-INF);
    for(i=1;i<l;i++) I.push_back(INF);

    for(i=0;i<l;i++){
        if(seq[i]>=0){
        int pos=lower_bound(I.begin(),I.end(),seq[i])-I.begin();
        I[pos]=seq[i];
        L[i]=pos;
        if(pos>mx) mx=pos;
        }
    }
    return mx;
}

int main(){

    int kases,i,j,curr;
    cin >> kases;

    for(i=1;i<=kases;i++){
        cin >> n >> p >> q;
        p++;
        q++;
        memset(moves,-1,sizeof(moves));

        for(j=0;j<p;j++){
            cin>>curr;
            moves[curr]=j+1;
        }
        for(j=0;j<q;j++){
            cin>>curr;
            seq[j]=moves[curr]-1;
        }

        int ans=lis(q);

        printf("Case %d: %d\n",i,ans);
    }

    return 0;
}

/** AC!!! **/
