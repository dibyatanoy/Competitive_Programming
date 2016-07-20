#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#define MAXX 15000
#define ll long long
#define MAXLG 17
#define INF 1000

using namespace std;

struct entry{
    int nr[2];
    int p;
}L[MAXX];

char A[MAXX];
int P[21][MAXX];
int N,stp,cnt,i,len;

bool cmp(struct entry a,struct entry b){
    return a.nr[0]==b.nr[0]? (a.nr[1]<b.nr[1]? 1: 0) : (a.nr[0]<b.nr[0] ? 1: 0);
}

int LCP(int x,int y){
    int ans=0;

    for(int k=cnt-1;k>=0 && x<len && y<len;k--){
        if(P[k][x]!=-1 && P[k][y]!=-1 && P[k][x]==P[k][y]) {
            ans+=(1<<k);

            x+=(1<<k);
            y+=(1<<k);
        }
    }
    return ans;
}

int main(){

    int kases,j,a,b,c=1;
    cin>>kases;

    while(kases--){


    scanf("%s",A);
    cin>>a>>b;

    //cout<<A<<endl;
    len=strlen(A);
    memset(P,-1,sizeof(P));
    //cout<<len<<endl;

    for(i=0;i<len;i++) P[0][i]=A[i]-'a';

    for(stp=1,cnt=1;cnt/2<len;stp++,cnt*=2){

        for(i=0;i<len;i++){
            L[i].nr[0]=P[stp-1][i];
            L[i].nr[1]= (i+cnt < len)? P[stp-1][i+cnt]: -1;
            L[i].p=i;
        }

        sort(L,L+len,cmp);

        for(i=0;i<len;i++){
            P[stp][L[i].p]= (i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1])? P[stp][L[i-1].p]: i;
        }


    }
    long long int ans=(ll)(min(b,len-L[0].p)-(a-1));
    //cout<<ans<<endl;
    //for(i=0;i<len;i++) cout<<L[i].p<<endl;
    for(i=1;i<len;i++){
        //cout<<LCP(L[i].p,L[i-1].p)<<endl;
        ans+=(ll)(min(b,len-L[i].p)-max(a-1,LCP(L[i-1].p,L[i].p)));
    }
    printf("Case %d: %lld\n",c++,ans);
    }

    return 0;
}
