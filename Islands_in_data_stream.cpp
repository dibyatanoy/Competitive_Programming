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

    int i,j,k,x;
    int p;

    scanf("%d",&p);

    while(p--){
        scanf("%d",&k);
        int arr[20];
        int ans=0;


        for(i=0;i<15;i++) scanf("%d",&arr[i]);

        for(i=1;i<14;i++){
            for(j=i;j<14;j++){
                int mn=100;
                for(x=i;x<=j;x++){
                    mn=min(mn,arr[x]);
                }

                if(mn>arr[i-1] && mn>arr[j+1]) ans++;
            }
        }
        printf("%d %d\n",k,ans);
    }

    return 0;
}
