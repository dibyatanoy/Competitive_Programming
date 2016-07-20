#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))
#define all(v) v.begin(),v.end()
#define MP make_pair
#define fr first
#define sc second
#define MAXX 110
#define INF 10000000

using namespace std;
long long int cur[15];

int main(){

    int N,D,t;
    int i,j,k;

    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&N,&D);

        CLR(cur);
        long long int ans=0,sum=0;

        while(1){

            bool fnd=true;

            for(i=0;i<N;i++){
                if(cur[i]!=D-1){fnd=false;break;}

            }
            if(fnd) break;

            long long int min_xorr=10000000000;
            int moves;

            sum++;

            for(i=0;i<N;i++){
                if(cur[i]>=D-1) continue;
                cur[i]++;
                long long int xorr=0;

                for(k=0;k<N;k++){
                    xorr=xorr^cur[k];
                }
                if(xorr<min_xorr){
                    min_xorr=xorr;
                    moves=i;
                }
                cur[i]--;
            }

            cur[moves]++;
            ans+=min_xorr*sum;
        }


        printf("%lld\n",ans);
    }

    return 0;
}
