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
#define MAXX 1005
#define INF 10000000000LL
#define Fr first
#define Sc second

using namespace std;
int k,n[3],t1,t2,t3;
long long int mac[3][MAXX];

int main(){

    int i,j,x,mn_pos[3];
    long long int mn=INF;
    int c=0;
    long long int tmp;
    long long int t=0;

    scanf("%d %d %d %d %d %d %d",&k,&n[0],&n[1],&n[2],&t1,&t2,&t3);
    CLR(mac);

    for(i=0;i<k;i++){

            mn=INF;
            for(x=0;x<n[0];x++){
                if((ll)mac[0][x]<mn){
                    mn=(ll)mac[0][x];
                    mn_pos[0]=x;
                }
            }
            tmp=mn+(ll)t1;
            mn=INF;

            for(x=0;x<n[1];x++){
                if((ll)mac[1][x]<mn){
                    mn=(ll)mac[1][x];
                    mn_pos[1]=x;
                }
            }
            tmp=max(tmp,mn);
            tmp+=(ll)t2;
            mn=INF;

            for(x=0;x<n[2];x++){
                if((ll)mac[2][x]<mn){
                    mn=(ll)mac[2][x];
                    mn_pos[2]=x;
                }
            }
            tmp=max(tmp,mn)+(ll)t3;
            t=max(t,tmp);
            mac[0][mn_pos[0]]=tmp-(ll)(t2+t3);
            mac[1][mn_pos[1]]=tmp-(ll)t3;
            mac[2][mn_pos[2]]=tmp;

            //printf("%d\n",tmp-t1-t2-t3);
    }

    printf("%I64d\n",t);

    return 0;
}
