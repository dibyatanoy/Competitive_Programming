#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <utility>
#include <set>
#define pb push_back
#define ll long long int
#define all(v) v.begin(),v.end()
#define MP make_pair
#define PII pair<int, int >
#define CLR(x) memset(x,0,sizeof(x));
#define MAXX 105

using namespace std;

int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}

char str[1000005];
ll app[1000005][28];
ll N,K,l;

int main(){

    int i,j,k;

    scanf("%lld",&N);

    scanf("%s",str);
    l=strlen(str);

    CLR(app);

    for(i=1;i<=l;i++){
        for(j=0;j<26;j++){
            if(str[i-1]-'A'==j){
                app[i][j]=app[i-1][j]+1;
                //printf("Here!\n");
            }else{
                app[i][j]=app[i-1][j];
            }
        }
    }

    scanf("%lld",&K);
    for(i=0;i<K;i++){

        ll row;
        char c;
        scanf("%lld %c",&row,&c);

        int ch=int(c-'A');


        ll up,down;
        up=row*(row-1)/2;
        down=row*(row+1)/2;

        ll left, wholes,right;
        left=l-(up)%l;
        wholes=min((row-left),0LL)/l;
        right=min(row-left-wholes*l,0LL);

        //printf("%d %d %d\n",left,wholes,right);

        ll ans;
        if(row%2==0) switch(left,right);
        if(left>row) ans=app[row][ch];

       else ans=app[l][ch]-app[l-left][ch]+app[l][ch]*wholes+app[right][ch];

        printf("%lld\n",ans);
    }

    return 0;
}
