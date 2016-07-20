#include <bits/stdc++.h>
#define eps 1e-9

using namespace std;
double ken[1003],naomi[1003];
bool vis[1003];

int main(){

    int t,i,j,k,N;

    //freopen("D-small-attempt1.in.","r",stdin);
    //freopen("out2.txt","w",stdout);

    cin>>t;

    for(i=1;i<=t;i++){
        cin>>N;
        int pt=N;

        for(j=0;j<N;j++) cin>>naomi[j];
        for(j=0;j<N;j++) cin>>ken[j];

        sort(naomi,naomi+N);
        sort(ken,ken+N);

        for(j=0;j<N;j++) cout<<naomi[j]<<" ";
        cout<<endl;
        for(i=0;i<N;i++) cout<<ken[i]<<" ";
        cout<<endl;

        memset(vis,0,sizeof(vis));

        k=0;
        int ans=0;


            pt=0;
            for(k=0;k<N && pt<N;k++){
                while(ken[k]-naomi[pt]>eps && pt<N){
                    pt++;
                }
                pt++;
                if(pt>N) break;
            }

            ans=k;

        //cout<<ans<<endl;

        /*bool fnd=false;
        for(j=N-1;j>=0;j--){
            if(-naomi[j]+ken[j]>eps) {pt=j;break;}
        }

        for(j=0;j<=pt;j++){
            if(naomi[j]-ken[pt-j]>eps) break;
        }*/
        int pt2=0;

        for(k=0;k<N && pt2<N;k++){

            while(naomi[k]-ken[pt2]>eps && pt2<N){
                pt2++;
            }
            pt2++;
            if(pt2>=N) break;
        }

        printf("Case #%d: ",i);
        cout<<ans<<" "<<N-(k+1)<<endl;


    }

    return 0;
}
