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
#include <cmath>
#include <utility>
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))
#define all(v) (v.begin(),v.end())
#define INF 1e8
#define MAXX 105

using namespace std;

int main(){

    int i,j,k;
    double D, A,F,B;
    int p;

    scanf("%d",&p);

    while(p--){
        scanf("%d %lf %lf %lf %lf",&i,&D,&A,&B,&F);

        printf("%d %.2lf\n",i,F*(D/(A+B)));
    }

    return 0;
}
