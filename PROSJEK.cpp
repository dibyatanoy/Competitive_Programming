#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <utility>
#include <set>
#define pb push_back
#define ll long long int
#define all(v) v.begin(),v.end()
#define MP make_pair
#define PII pair<int, int >
#define CLR(x) memset(x,0,sizeof(x));
#define MAXX 105

using namespace std;

int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}

int main(){

    long long int A[MAXX],B[MAXX],sum[MAXX];

    int i,j,k,N;
    scanf("%d",&N);

    sum[0]=0;

    for(i=1;i<=N;i++){
        scanf("%lld",&B[i]);
    }

    for(i=1;i<=N;i++){
        A[i]=B[i]*i-sum[i-1];
        sum[i]=sum[i-1]+A[i];
    }
    printf("%lld",A[1]);
    for(i=2;i<=N;i++){
        printf(" %lld",A[i]);

    }
    printf("\n");

    return 0;
}
