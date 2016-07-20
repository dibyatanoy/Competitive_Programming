#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#define INF 1000000000
#define eps 1e-9
#define CLR(x) memset(x,0,sizeof(x))
#define pb push_back
#define all(x) x.begin(), x.end()
#define Fr first
#define Sc second
#define MAXX 200000
#define pi 2*acos(0.0)

using namespace std;

int ara[MAXX];
int inv,N;
int reduced,a,b;

int main(){

    int i,j,k;

    scanf("%d",&N);

    for(i=0;i<N;i++){

        scanf("%d",&ara[i]);
    }

    inv=0;

    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            if(ara[j]<ara[i]) inv++;
        }
    }

    int l,s;

    reduced=inv;
    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            int tmp=inv;
            l=0;s=0;

            for(k=i+1;k<=j;k++){
                if(ara[k]>ara[i]) l++;
            }
            tmp+=l-(j-i-l);

            l=0;s=0;

            for(k=j-1;k>i;k--){
                if(ara[k]<ara[j]) l++;
            }

            tmp+=l-(j-i-1-l);

            if(tmp<reduced){
                reduced=tmp;
                a=i;b=j;
            }

        }

    }

    if(reduced==inv) printf("Cool Array\n");
    else printf("%d %d\n",a+1,b+1);

    return 0;
}
