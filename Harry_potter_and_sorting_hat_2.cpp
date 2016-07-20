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
#define MAXX 55000
#define INF 10000000000000000LL
#define Fr first
#define Sc second

using namespace std;
int N;
string seq;
int cnt[4];

int main(){

    int i,j,k,mn;

    cin>>N;

    getchar();
    cin>>seq;
    //cout<<seq<<endl;
    CLR(cnt);

    for(i=0;i<N;i++){
        mn=1000000;
        for(j=0;j<4;j++){
            if(cnt[j]<mn) mn=cnt[j];
        }
        if(seq[i]=='G') cnt[0]++;
        if(seq[i]=='H') cnt[1]++;
        if(seq[i]=='R') cnt[2]++;
        if(seq[i]=='S') cnt[3]++;
        if(seq[i]=='?'){
            if(cnt[3]==mn){cnt[3]++;continue;}
            if(cnt[2]==mn){cnt[2]++;continue;}
            if(cnt[1]==mn){cnt[1]++;continue;}
            if(cnt[0]==mn){cnt[0]++;continue;}
        }
    }
    mn=1000000;
    for(j=0;j<4;j++){
        if(cnt[j]<mn) mn=cnt[j];
    }
    if(cnt[0]==mn) printf("Gryffindor\n");


    CLR(cnt);

    for(i=0;i<N;i++){
        mn=1000000;
        for(j=0;j<4;j++){
            if(cnt[j]<mn) mn=cnt[j];
        }
        if(seq[i]=='G') cnt[0]++;
        if(seq[i]=='H') cnt[1]++;
        if(seq[i]=='R') cnt[2]++;
        if(seq[i]=='S') cnt[3]++;
        if(seq[i]=='?'){
            if(cnt[3]==mn){cnt[3]++;continue;}
            if(cnt[2]==mn){cnt[2]++;continue;}
            if(cnt[0]==mn){cnt[0]++;continue;}
            if(cnt[1]==mn){cnt[1]++;continue;}
        }
    }
    mn=1000000;
    for(j=0;j<4;j++){
        if(cnt[j]<mn) mn=cnt[j];
    }
    if(cnt[1]==mn) printf("Hufflepuff\n");


    CLR(cnt);

    for(i=0;i<N;i++){
        mn=1000000;
        for(j=0;j<4;j++){
            if(cnt[j]<mn) mn=cnt[j];
        }
        if(seq[i]=='G') cnt[0]++;
        if(seq[i]=='H') cnt[1]++;
        if(seq[i]=='R') cnt[2]++;
        if(seq[i]=='S') cnt[3]++;
        if(seq[i]=='?'){
            if(cnt[3]==mn){cnt[3]++;continue;}
            if(cnt[1]==mn){cnt[1]++;continue;}
            if(cnt[0]==mn){cnt[0]++;continue;}
            if(cnt[2]==mn){cnt[2]++;continue;}
        }
    }
    mn=1000000;
    for(j=0;j<4;j++){
        if(cnt[j]<mn) mn=cnt[j];
    }
    if(cnt[2]==mn) printf("Ravenclaw\n");

    CLR(cnt);

    for(i=0;i<N;i++){
        mn=1000000;
        for(j=0;j<4;j++){
            if(cnt[j]<mn) mn=cnt[j];
        }
        if(seq[i]=='G') cnt[0]++;
        if(seq[i]=='H') cnt[1]++;
        if(seq[i]=='R') cnt[2]++;
        if(seq[i]=='S') cnt[3]++;
        if(seq[i]=='?'){
            if(cnt[2]==mn){cnt[2]++;continue;}
            if(cnt[1]==mn){cnt[1]++;continue;}
            if(cnt[0]==mn){cnt[0]++;continue;}
            if(cnt[3]==mn){cnt[3]++;continue;}
        }
    }
    mn=1000000;
    for(j=0;j<4;j++){
        if(cnt[j]<mn) mn=cnt[j];
    }
    if(cnt[3]==mn) printf("Slytherin\n");

    return 0;
}
