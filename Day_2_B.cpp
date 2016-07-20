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
#define INF 1e10
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define all(v) v.begin(),v.end()
#define MAXX 2050
#define PII pair <int,int >
#define ll long long
#define MP make_pair

using namespace std;

int M[MAXX],x,pow2[15],p[MAXX];
int st[MAXX],ed[MAXX];
int temp_p[MAXX];

long long int dp[MAXX][MAXX];
bool vis[MAXX][MAXX];

long long int call(int idx,int bought){

    if(st[idx]==ed[idx]){
        if(x-bought<=M[st[idx]]) return 0;
        else return INF;
    }
    if(vis[idx][bought]) return dp[idx][bought];

    long long int ret;



    /*if(c1<c2){
        printf("%d %d %d %d\n",idx,bought,c1,1);
    }else{
        printf("%d %d %d %d\n",idx,bought,c2,2);
    }*/

    ret=min(p[idx]+call(2*idx,bought+1)+call(2*idx+1,bought+1),call(2*idx,bought)+call(2*idx+1,bought));
    vis[idx][bought]=1;

    return dp[idx][bought]=ret;
}

int main(){

    int i,j,k;

    int T;

    scanf("%d",&T);
    pow2[0]=1;

    for(i=1;i<14;i++){
        pow2[i]=pow2[i-1]*2;
    }

    for(i=1;i<=T;i++){
        scanf("%d",&x);

        for(j=0;j<pow2[x];j++){
            scanf("%d",&M[j]);
        }

        memset(st,0,sizeof(st));
        CLR(ed);
        CLR(temp_p);
        CLR(p);


        st[1]=0;ed[1]=pow2[x]-1;

        j=1;

        while(st[j]!=ed[j]){
            int l=2*j;
            int r=l+1;

            int mid=((st[j]+ed[j])/2);
            st[l]=st[j];ed[l]=mid;
            st[r]=mid+1;ed[r]=ed[j];
            j++;
        }
        int curr=1;
        int st=1;
        for(j=x;j>=1;j--){
            for(k=1;k<=pow2[j-1];k++){
                scanf("%d",&temp_p[curr]);
                curr++;
            }
            reverse(temp_p+st,temp_p+curr);
            st=curr;
        }
        //cout<<curr<<endl;
        curr--;
        //int st=1;


        for(j=curr;j>=1;j--){
            p[curr-j+1]=temp_p[j];
        }
        //for(j=1;j<=7;j++) printf("%d ",p[j]);

        //printf("\n");
        memset(vis,0,sizeof(vis));

        //for(j=1;j<=7;j++) printf("%d ",p[j]);
        //cout<<endl;

        printf("%lld\n",call(1,0));

    }


    return 0;
}

/** AC!!! **/
