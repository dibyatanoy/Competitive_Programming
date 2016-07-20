#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#define MAXX 110
#define INF 10000000

using namespace std;

long long int my_pow(int k, int c){

    long long int ans = 1;

    for(int i = 1; i <= c; i++){

        ans *= (long long int)k;
    }

    return ans;
}

int main(){

    int j, t, kases;
    long long int i;

    int K, C, S;

    freopen("Documents/C++_programs/io/D-small-attempt0.in","r",stdin);
    freopen("Documents/C++_programs/io/Fractiles_small_out.txt","w",stdout);

    scanf("%d",&kases);

    for(t =  1; t <= kases; t++){

        scanf("%d %d %d", &K, &C, &S);

        long long int interval = my_pow(K, C-1);

        for(i = 1LL; i <= interval * (long long) K; i+=interval){

            if(i==1LL) printf("Case #%d: %lld", t, i);
            else printf(" %lld", i);
        }
        printf("\n");
    }

    return 0;
}
