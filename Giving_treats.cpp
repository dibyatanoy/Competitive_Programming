#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define MAXX 2006

using namespace std;
int N;
long long int val[MAXX];
long long int dp[MAXX][MAXX];
bool taken[MAXX][MAXX];

long long int call(int i,int j){
    if(i>j) return 0;
    if(taken[i][j]) return dp[i][j];

    long long int ret;
    ret=max(call(i+1,j)+val[i]*(i+N-j),call(i,j-1)+val[j]*(i+N-j));

    taken[i][j]=1;
    return dp[i][j]=ret;
}

int main(){

    int i,j;
    cin>>N;

    for(i=0;i<N;i++){
        cin>>val[i];
    }

    memset(taken,0,sizeof(taken));
    cout<<call(0,N-1)<<endl;

    return 0;
}

/** AC!!! **/
