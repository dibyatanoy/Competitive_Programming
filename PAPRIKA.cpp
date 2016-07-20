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
#include <utility>
#define INF 100000000
#define pb push_back
#define MP make_pair
#define all(v) v.begin(),v.end()
#define Fr first
#define Sc second
#define CLR(x) memset(x,0,sizeof(x))

using namespace std;
int N,X;
int a[1200],b[1200];

int main(){

    int i,j,k,tmp;

    scanf("%d %d",&N,&X);

    for(i=0;i<N;i++) scanf("%d %d",&a[i],&b[i]);

    for(i=0;i<N-1;i++){

        if(a[i]>a[i+1] && b[i]==1 && b[i+1]==0){
            tmp=a[i];
            a[i]=a[i+1];
            a[i+1]=tmp;
        }
        if(a[i]<a[i+1] && b[i]==0 && b[i+1]==1){
            tmp=a[i];
            a[i]=a[i+1];
            a[i+1]=tmp;
        }
    }

    int ans=0;
    for(i=0;i<N;i++){
        if(a[i]<=X && b[i]==1) ans++;
        else if(a[i]>X && b[i]==0) ans++;
    }
    printf("%d\n",ans);

    return 0;
}
