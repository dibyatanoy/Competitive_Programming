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
#define MP make_pair
#define INF 1e8
#define MAXX 22

using namespace std;

double fact[MAXX];
int N,K;

double comb(int n, int r){
    return fact[n]/(fact[r]*fact[n-r]);
}

int main(){

    int i,j,k;

    fact[0]=1.0;
    for(i=1;i<MAXX;i++) fact[i]=fact[i-1]*i;

    int p;

    scanf("%d",&p);

    while(p--){
        scanf("%d %d %d",&k,&N,&K);

        if(K==1) printf("%d %.0lf\n",k,fact[N-K]);
        else{
            double sum=0.0;

            for(i=0;i<K-1;i++){
                sum+=comb(K-2,i)*fact[i+1]*fact[N-2-i];
            }
            printf("%d %0.lf\n",k,sum);
        }
    }

    return 0;
}
