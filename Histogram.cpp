#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#define INF 1e9

long long int hts[100002];
long long int ans1[100002],ans2[100002];


using namespace std;

int main(){
    int i,j,n;

    while(scanf("%d",&n)==1&&n!=0){
    for(i=0;i<n;i++) scanf("%lld",&hts[i]);
    hts[i]=-INF;

    stack<long long int>small1;
    stack<long long int>pos1;
    stack<long long int>small2;
    stack<long long int>pos2;
    long long int max_r=0;
    small1.push(-INF);
    pos1.push(n);
    ans1[n]=n;

    for(j=n-1;j>=0;j--){
        while(small1.top()>=hts[j]){
                small1.pop();
                pos1.pop();
        }


        ans1[j]=pos1.top();
        small1.push(hts[j]);
        pos1.push(j);

    }
    for(i=0;i<n;i++){
            ans1[i]=(ans1[i]-i)*hts[i];
    }
    reverse(hts+0,hts+n);

    small2.push(-INF);
    pos2.push(n);
    ans2[n]=n;

    for(j=n-1;j>=0;j--){
        while(small2.top()>=hts[j]){
                small2.pop();
                pos2.pop();
        }


        ans2[j]=pos2.top();
        small2.push(hts[j]);
        pos2.push(j);

    }
    for(i=0;i<n;i++){
        ans2[i]=ans1[n-i-1]+(ans2[i]-i)*hts[i]-hts[i];
        if(ans2[i]>max_r) max_r=ans2[i];
    }

    printf("%lld\n",max_r);
    }

    return 0;
}

/** AC!!! **/