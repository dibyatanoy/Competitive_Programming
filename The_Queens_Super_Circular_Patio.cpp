#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#define pi 2*acos(0.0)

using namespace std;

int main(){

    int i,j,k;
    int p,N,M;
    double theta, r0,r1,a,b,c;

    scanf("%d",&p);

    while(p--){
        scanf("%d %d %d",&i,&N,&M);

        theta=pi/(double)N;
        r0=1.0;
        r0=sin(theta)/(1-sin(theta));
        r1=r0;

        M--;

        while(M--){
            a=sin(theta)*sin(theta);
            b=-(2*r0*sin(theta)*tan(theta)*(1+sin(theta)*tan(theta)));
            c=r0*r0*sin(theta)*sin(theta);

            r1=(-b+sqrt(b*b-4*a*c))/(2*a);
            r0=r1;
        }

        printf("%d %.3lf %.3lf\n",i,r1,2*r1*((double)N + pi));
    }

    return 0;
}
