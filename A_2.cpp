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
#include <sstream>
#define INF 1e8
#define MAXX 500100
#define pb push_back
#define MP make_pair
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a));
#define PII pair<int,int >

using namespace std;

struct data{
    long long int val;
    int num;
};

long long int H[MAXX];
int N;

long long int solve(){
    int i,j;
    long long int ans=0;

    vector<data>now;

    data temp;


    temp.val=H[N-1];

    temp.num=1;
    now.push_back(temp);

    for(i=N-2;i>=0;i--){

        int len=1;

        while(!now.size()==0){
            int sz=now.size();
            if(now[sz-1].val==H[i]){

                ans+=(long long)(now[sz-1].num);
                len=now[sz-1].num+1;

                now.pop_back();
            }else if(now[sz-1].val<H[i]){
                ans+=(long long )(now[sz-1].num);
                now.pop_back();
            }else break;

        }
        if(!now.size()==0) ans++;

        temp.val=H[i];

        temp.num=len;
        now.push_back(temp);
    }



    return ans;
}

int main(){

    scanf("%d",&N);

    int i,j;

    for(i=0;i<N;i++){
        scanf("%lld",&H[i]);
    }

    printf("%lld\n",solve());

    return 0;
}

