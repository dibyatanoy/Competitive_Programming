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
#define ll long long
#define MAXX 500000
#define INF 10000000000000000LL
#define Fr first
#define Sc second

using namespace std;

struct data{
    int t;
    int idx,v;
};

long long int sum;
int done_c,done_r,N,P;
data ops[MAXX];
bool don_r[MAXX] ,don_c[MAXX];

int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}

int main(){

    int i,j,k;
    char temp[5];

    scanf("%d %d",&N,&P);
    CLR(don_r);
    CLR(don_c);

    for(i=0;i<P;i++){
        int x,y;

        scanf("%s %d %d",temp,&ops[i].idx,&ops[i].v);
        //printf("%s\n",temp);
        if(temp[0]=='R' && temp[1]=='O' && temp[2]=='W') ops[i].t=0;
        else ops[i].t=1;
    }
    sum=0;
    done_c=0;done_r=0;

    for(i=P-1;i>=0;i--){
            //printf("%d\n",ops[i].t);
        if(ops[i].t==0){
            if(!don_r[ops[i].idx]){
                don_r[ops[i].idx]=1;
                sum+=(ll)((ll)(N-done_c)*(ll)ops[i].v);
                done_r++;
            }
        }else{
            if(!don_c[ops[i].idx]){
                don_c[ops[i].idx]=1;
                sum+=(ll)((ll)(N-done_r)*(ll)ops[i].v);
                done_c++;
            }
        }
    }
    printf("%lld\n",sum);

    return 0;
}

/** AC!!! **/
