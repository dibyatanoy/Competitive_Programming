#include <bits/stdc++.h>
#define eps 1e-9

using namespace std;

int main(){

    int t,i,j,k;
    double C,F,X;

    //freopen("B-large.in","r",stdin);
    //freopen("out2.txt","w",stdout);

    cin>>t;

    for(i=1;i<=t;i++){
        cin>>C>>F>>X;

        double ans=0.0;
        int n=ceil(X/C-(F+2)/F);

        for(j=0;j<n;j++){
            ans+=C/(2+j*F);
        }
        ans+=X/(2+j*F);

        printf("Case #%d: %.8lf\n",i,ans);
    }

    return 0;
}
