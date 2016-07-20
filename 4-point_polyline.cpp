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
#define MAXX 100005
#define INF 100000000
#define Fr first
#define Sc second

using namespace std;

int main(){

    int n,m;
    double d1,d2,d3,d4,d5;

    scanf("%d %d",&n,&m);



    if(n==0){
        printf("0 1\n0 %d\n0 0\n0 %d\n",m,m-1);
    }else if(m==0){
        printf("1 0\n%d 0\n0 0\n%d 0\n",n,n-1);
    }/*else if(n==1){
        d1=
        d5=2*sqrt(n*n+m*m)+max(n,m);

        printf("0 0\n");
        printf("%d %d\n",n,m);
        printf("0 1\n");
        printf("1 %d\n",m-1);
    }else if(m==1){
        d5=2*sqrt(n*n+m*m)+max(n,m);
        printf("0 0\n");
        printf("%d %d\n",n,m);

        printf("1 0\n");
        printf("%d %d\n",n-1,m);

    }*/else{
        d1=sqrt(m*m+(n-1)*(n-1))+sqrt((n-1)*(n-1)+(m-1)*(m-1));
        d2=sqrt(m*m+(n-1)*(n-1))+sqrt((n-2)*(n-2)+(m-0)*(m-0));
        d3=sqrt((m-1)*(m-1)+(n-0)*(n-0))+sqrt((n-1)*(n-1)+(m-1)*(m-1));
        d4=sqrt((m-1)*(m-1)+(n-0)*(n-0))+sqrt((n-0)*(n-0)+(m-2)*(m-2));
        d5=sqrt(n*n+m*m)+max(n,m);

        //printf("%.6lf,%.6lf,%.6lf,%.6lf",d1,d2,d3,d4);
        //printf("%.6lf %.6lf\n",d2,d5);

        if(d1>d2 && d1>d3 && d1>d4 && d1>d5){
            printf("0 0\n%d %d\n1 0\n%d %d\n",n,m,n,m-1);
        }else if(d2>d3 && d2>d4 &&d2>d5){
            printf("0 0\n%d %d\n1 0\n%d %d\n",n,m,n-1,m);
        }else if(d3>d4 && d3>d5){
            printf("0 0\n%d %d\n0 1\n%d %d\n",n,m,n-1,m);
        }else if(d4>d5) printf("0 0\n%d %d\n0 1\n%d %d\n",n,m,n,m-1);
        else{
            if(n>m) printf("0 0\n%d %d\n0 %d\n%d 0\n",n,m,m,n);
            else printf("0 0\n%d %d\n%d 0\n0 %d\n",n,m,n,m);
        }

    }

    return 0;
}
