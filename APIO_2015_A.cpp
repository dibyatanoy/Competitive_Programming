#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#define MAXX 60
#define INF 1000000000000000LL
#define pb push_back
#define MP make_pair
#define all(v) v.begin(),v.end()
#define Fr First
#define Sc Second
#define CLR(x) memset(x,0,sizeof(x))

using namespace std;
int N,A,B;
long long int mn;
long long int val[MAXX];

void recurse(int pos,int parts, long long int sum, long long int orval){
    if(pos==N-1){

        if((parts+1) >=A && (parts+1) <=B){
            if((orval|sum) <mn){
                //printf("! %d %lld\n",parts+1, mn);
                mn=(orval|sum);
            }
        }
        return;
    }

    recurse(pos+1,parts,sum+val[pos],orval);
    if(parts<B && !(sum==0 && pos>0)) recurse(pos+1,parts+1,0,orval|sum);

    return;

}

int main(){

    int i,j,k;

    scanf("%d %d %d", &N, &A, &B);
    mn=INF;

    for(i=0;i<N;i++) scanf("%lld",&val[i]);

    recurse(0,0,0,0);
    printf("%lld\n",mn);


    return 0;
}
