#include <bits/stdc++.h>
#define MAXX 1<<28
#define CLEAR(a) memset(a,0,sizeof(a));
#define pb push_back
#define all(v) v.begin(),v.end()

using namespace std;

int main(){

    int kases,i,x,N;
    long long int tri[3],mn;

    cin >> kases;

    for(i=1;i<=kases;i++){

        cin >> N;
        int mn=N/2;

        CLEAR(tri);

        for(x=1;x<=mn;x++){
            bool done=false;
            int left=N-x;
            int sub=0;
            int y_mx=N/2;
            int u=min(y_mx,left-1);
            int l=max(1,left-y_mx);
            if(left%2==0 && left/2 >=l && left/2 <=u){
                if(N%3==0 && left/2==N/3){sub++;tri[2]+=1;done=1;}
                else{sub+=1;tri[1]++;}
            }
            if(x>=l && x<=u && !done){sub+=2;tri[1]+=2;}
            tri[0]+=u-l+1-sub;

            //printf("%d %d %d %d %d %d\n",x,l,u,tri[0],tri[1],tri[2]);
        }

        printf("Case %d: %lld\n",i,tri[0]/6+tri[1]/3+tri[2]);

    }

    return 0;
}
