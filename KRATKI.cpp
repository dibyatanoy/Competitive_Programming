#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#define INF 100000000
#define pb push_back
#define MP make_pair
#define all(v) v.begin(),v.end()
#define Fr first
#define Sc second
#define CLR(x) memset(x,0,sizeof(x))
#define MAXX 3100
using namespace std;

int main(){

    int N,K,i,j;
    scanf("%d %d",&N,&K);

    int grp=ceil(double(N)/double(K));

    if(grp>K) printf("-1\n");
    else{
        int rem=N%K;
        rem=N-rem+1;

        if(rem<=N){
            printf("%d",rem);
            for(i=rem+1;i<=N;i++) printf(" %d",i);

            int grp=int(N/K);
            int st=rem;

            //printf("\n%d %d\n",st,grp);

            for(i=1;i<=grp;i++){
                st=st-K;

                for(j=st;j<st+K;j++) printf(" %d",j);
            }
            printf("\n");
        }else{
            grp=N/K;
            int st=N+1-K;
            printf("%d",st);

            for(i=st+1;i<=N;i++) printf(" %d",i);

            for(i=1;i<=grp-1;i++){
                st=st-K;

                for(j=st;j<st+K;j++) printf(" %d",j);
            }
            printf("\n");
        }
    }

    return 0;
}
