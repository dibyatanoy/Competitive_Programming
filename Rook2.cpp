#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define pb push_back
#define MP make_pair
#define minim(a,b) ((a)<(b)? (a):(b))
#define maxim(a,b) ((a)>(b)? (a):(b))
#define MAXX 100004

using namespace std;

__int64 C[31][31],fact[31];
 
void comb_init(){
    int m,n;
    for(m=0;m<31;m++){
        for(n=0;n<31;n++)
            C[m][n]=0;
    }
}
 
void combi(int n,int k){
    int m,l;
    for(m=1;m<=n;m++){
        for(l=1;l<m;l++)
            C[m][l]=C[m-1][l-1]+C[m-1][l];
 
    }
    /*printf("In function combi().Value is %I64d.\n",C[n][k]);*/
}
 
__int64 factorial(int k){
    int l;
    fact[0]=1;
    for(l=1;l<=k;l++)
        fact[l]=l*fact[l-1];
    return fact[k];
}
 
int main(){
 
    int testcase,n,k,i,j;
    __int64 res;
    comb_init();
 
    scanf("%d",&testcase);
 
    for(i=1;i<=testcase;i++){
       
        scanf("%d %d",&n,&k);
 
        for(j=0;j<31;j++){
            C[j][0]=1;
            C[j][j]=1;
        }
   
 
        if(k>n) printf("Case %d: 0\n",i);
        else if(n==k){
            fact[k]=factorial(k);
            printf("Case %d: %I64d\n",i,fact[k]);
        }else{
            combi(n,k);
            fact[k]=factorial(k);
 
            /*printf("%I64d\n",C[n][k]);*/
            res=C[n][k]*C[n][k]*fact[k];
            printf("Case %d: %I64d\n",i,res);
        }
    }
 
    return 0;
}