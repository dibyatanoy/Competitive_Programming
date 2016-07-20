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
#define INF 1e6
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define all(v) v.begin(),v.end()
#define MAXX 1004
#define PII pair <int,int >
#define ll long long
#define MP make_pair

using namespace std;
char a[MAXX],b[MAXX];
int sat,dis;

int main(){

    int i,j,k;

    scanf("%d %d",&sat,&dis);

    scanf("%s",a);
    scanf("%s",b);
    int l1=strlen(a);
    int l2=strlen(b);

    int mx=-INF,curr=0;

    for(i=0;i<l1;i++){
        curr=0;
        for(j=0;j<l2 && j+i<l1;j++){
            if(a[j+i]==b[j]) curr+=sat;
            else curr+=dis;
        }
        mx=max(curr,mx);
    }
    for(i=0;i<l2;i++){
        curr=0;
        for(j=0;j<l1 && j+i<l2;j++){
            if(b[j+i]==a[j]) curr+=sat;
            else curr+=dis;
        }
        mx=max(curr,mx);
    }

    cout<<mx<<endl;

    return 0;
}
