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
#define all(v) v.begin(),v.end()
#define ll long long
#define MAXX 100007
#define INF 10000000
#define Fr first
#define L 0
#define R 1
#define Sc second

using namespace std;

int main(){

    int N,a,min1=INF,min2=INF;

    int kases;

    scanf("%d",&kases);

    while(kases--){
        scanf("%d",&N);
        min1=INF;min2=INF;

        for(int i=0;i<N;i++){
            scanf("%d",&a);
            if(a<min1) {min2=min1;min1=a;}
            else if(a<min2) {min2=a;}
        }
        printf("%d\n",min1+min2);
    }
    //printf("%d\n",min1+min2);

    return 0;
}
