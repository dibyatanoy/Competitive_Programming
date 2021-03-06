#include <bits/stdc++.h>
#define MAXX 100005
#define INF 1e9

using namespace std;
int d[MAXX],D,N,c[MAXX],far[MAXX],tot_d[MAXX];
int L;

bool check(int cost){
    int next,days=0;
    for(int i=0;i<N;){
        next=far[i];

        while(next!=i && c[next]>cost){
            next--;
        }
        //printf("Here %d %d %d\n",cost,i,next);
        if(next==i) return 0;
        else {i=next;days++;}
    }
    return (days<=L)? 1:0;
}

int main(){

    int t,i,j,mn=INF+5,max_c=0;

    cin>>t;

    while(t--){

        cin>>N>>D;
        d[0]=0;
        for(i=1;i<=N;i++) {cin>>d[i]>>c[i];max_c=max(c[i],max_c);tot_d[i]=tot_d[i-1]+d[i];}

        c[N]=0;
        L=1;
        int c=0;
        for(i=0;i<N;i++){
            if(c+d[i+1]>D){
                L++;
                c=d[i+1];
            }else c+=d[i+1];
        }
        c=0;
        int pt=0;

        for(i=0;i<N;i++) far[i]=N;

        for(i=0;i<N;i++){
            while(c+d[i+1]>D){
                far[pt]=i;
                c-=d[pt+1];
                pt++;
            }
            c+=d[i+1];
        }

        //cout<<L;
        //for(i=0;i<N;i++) printf("%d ",far[i]);
        //cout<<endl;

        int lo=0;
        int hi=max_c+2;
        int mid;
        while(lo<=hi){
                //cout <<lo<<" "<<hi<<endl;
            mid=(lo+hi)/2;
            bool fnd=check(mid);
            if(!fnd){
                lo=mid+1;
            }else hi=mid-1;
        }
        cout <<L<<" "<<lo<<endl;
    }

    return 0;
}

/** AC!!! **/
