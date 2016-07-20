#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define INF 1e7
#define MAXX 100010
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define all(v) v.begin(),v.end()
#define MP make_pair
#define PII pair<int,int >
#define ll long long

using namespace std;

struct data{
    long long int x,y;

    bool operator <(const data &p)const{
        return x<p.x;
    }
};

long long int a[MAXX],b[MAXX],data_r[MAXX],data_l[MAXX];
int left_most[MAXX],right_most[MAXX];
data temp[MAXX];
int N;

int main(){

    int i,j,k;
    int T;

    scanf("%d",&T);


    for(i=0;i<T;i++){

        scanf("%d",&N);
        CLR(data_r);


        for(j=1;j<=N;j++){
            scanf("%lld %lld",&temp[j].x,&temp[j].y);

        }

        sort(temp+1,temp+N+1);
        for(j=1;j<=N;j++) {data_r[j]=temp[j].x;b[j]=temp[j].y;}

        a[1]=0;
        for(j=2;j<=N;j++) a[j]=a[j-1]+data_r[j]-data_r[j-1];

        for(j=1;j<=N;j++){
            right_most[j]=upper_bound(a+1,a+N+1,a[j]+b[j])-a-1;
            left_most[j]=lower_bound(a+1,a+N+1,a[j]-b[j])-a;
        }

        int mn=INF;
        int l1,l2,r1,r2,new_r2,new_l2;

        for(j=1;j<=N;j++){
            int r1=j-1;l1=j+1;r2=j;l2=j;
            new_r2=-INF;new_l2=INF;

            while(!(l1<=1 && r1>=N)){
            for(k=r1+1;k<=r2;k++){
                new_r2=max(new_r2,right_most[k]);
                new_l2=min(new_l2,left_most[k]);
            }
            for(k=l1-1;k>=l2;k--){
                new_r2=max(new_r2,right_most[k]);
                new_l2=min(new_l2,left_most[k]);
            }
            r1=r2;l1=l2;
            r2=new_r2;l2=new_l2;
            if(r1==r2 && l1==l2) break;
            }

            mn=min(mn,r1-l1+1);
        }
        cout<<mn<<endl;
    }


    return 0;
}
