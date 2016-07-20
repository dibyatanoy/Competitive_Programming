#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#define INF 100000000
#define eps 1e-9
#define CLR(x) memset(x,0,sizeof(x))
#define pb push_back
#define all(x) x.begin(), x.end()
#define Fr first
#define Sc second
#define MAXX 120
#define pi 2*acos(0.0)

using namespace std;
int N;
string s;

int pow(int p,int k){

    int ans=1;

    while(k--) ans*=p;

    return ans;
}

int main(){

    int i,j,k;
    s="";

    cin>>N;

    int l=(int) ((log2((double)(N-1)*25.0/26.0+1.0))/(log2(26.0)));
    //cout<<l<<endl;
    l++;
    //cout<<l<<endl;
    N-=26*(pow(26,l-1)-1)/25;



    for(i=l;i>1;i--){
        //cout
        //cout<<N/pow(26,i-1)<<endl;

        int x=N/pow(26,i-1);
        if(x*pow(26,i-1)==N) x--;
        s+=(char)('A'+x);

        N-=x*(pow(26,i-1));
    }
    s+=(char)('A'+N/pow(26,i-1) - 1);

    cout<<s<<endl;

    return 0;
}
