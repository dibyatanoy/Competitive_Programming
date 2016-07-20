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
#define MAXX 24

using namespace std;

int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}

int N;

int main(){

    int i,j,k;
    int l=200,r=0,u=0,d=200;

    scanf("%d",&N);

    for(i=0;i<N;i++){
        int x,y;
        scanf("%d %d",&x,&y);

        if(x<l) l=x;
        if(x>r) r=x;
        if(y>u) u=y;
        if(y<d) d=y;
    }

    printf("%d\n",max(r-l,u-d)*max(r-l,u-d));


    return 0;
}
