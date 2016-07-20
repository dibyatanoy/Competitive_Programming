#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define MAXX 100005
#define INF 1e8
#define CLEAR(x) memset((x),0,sizeof((x))
#define pb push_back
#define ll long long int
#define ALL(v) v.begin(),v.end()

using namespace std;
int g[7][7];
int seq[]={0,1,2,3,4};

int main(){

    int i,j,ans=-1000;

    for(i=0;i<5;i++){
        for(j=0;j<5;j++) cin>>g[i][j];
    }

    do{
        int temp;
        temp=g[seq[0]][seq[1]]+g[seq[1]][seq[0]]+g[seq[2]][seq[3]]+g[seq[3]][seq[2]];
        temp+=g[seq[1]][seq[2]]+g[seq[2]][seq[1]]+g[seq[3]][seq[4]]+g[seq[4]][seq[3]];
        temp+=g[seq[2]][seq[3]]+g[seq[3]][seq[2]];
        temp+=g[seq[3]][seq[4]]+g[seq[4]][seq[3]];

        ans=max(ans,temp);
    }while(next_permutation(seq,seq+5));

    cout<<ans<<endl;

    return 0;
}
