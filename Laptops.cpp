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
#define PII pair <int,int >
#define ll long long
#define MAXX 120000
#define INF 10000000000LL
#define Fr first
#define Sc second

using namespace std;

struct data{
    int a,b;

    bool operator <(const data &p)const{
        return a<p.a;
    }
};

int N;
data p[MAXX];

int gcd(int a,int b){
    return (b==0)? (a):gcd(b,a%b);
}

int main(){

    int i,j,k;
    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%d %d",&p[i].a,&p[i].b);
    }
    sort(p,p+N);

    bool ok=0;

    for(i=1;i<N;i++){
        if(p[i].b<p[i-1].b) {

            printf("Happy Alex\n");
            ok=1;
            break;
        }
    }
    if(!ok){
        printf("Poor Alex\n");
    }

    return 0;
}
