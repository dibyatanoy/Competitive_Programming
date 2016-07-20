#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define pb push_back
#define all(v) v.begin(),v.end()
#define CLR(x) memset(x,0,sizeof(x))
#define MAXX 110000
#define ll long long

using namespace std;
int N,K;
int votes[MAXX];
long long int inc[MAXX],decr[MAXX];
long long int inc2[MAXX],decr2[MAXX];
long long int met_i[MAXX],met_d[MAXX],ans[MAXX];

int main(){

    int i,j,k;

    scanf("%d %d",&N,&K);

    CLR(inc);CLR(decr);
    CLR(inc2);CLR(decr2);

    for(i=0;i<N;i++) scanf("%d",&votes[i]);

    inc[0]=0LL;

    for(i=1;i<N;i++){

        if(votes[i]>=votes[i-1]){
            inc[i]=inc[i-1]+1LL;
        }else inc[i]=0LL;
    }

    decr[N-1]=0LL;

    for(i=N-2;i>=0;i--){
        if(votes[i]<=votes[i+1])
            decr[i]=decr[i+1]+1LL;
        else
            decr[i]=0LL;
    }

    met_i[0]=0LL;

    for(i=1;i<K;i++) met_i[i]=met_i[i-1]+inc[i];

    for(i=K;i<N;i++){
        met_i[i]=met_i[i-1]+min((ll)K-1,inc[i]);
        met_i[i]-=min((ll)K-1,decr[i-K]);
    }

    //for(i=0;i<N;i++) printf("%d ",met_i[i]);
    //cout<<endl;

  /*  met_d[N-1]=0;

    for(i=N-2;i>N-1-K;i--) met_d[i]=met_d[i+1]+decr[i];

    for(;i>=0;i--){
        met_d[i]=met_d[i+1]+min(K-1,decr[i]);
        met_d[i]-=min(K-1,inc[i+K]);
    }*/


    reverse(votes,votes+N);

    inc2[0]=0LL;

    for(i=1;i<N;i++){

        if(votes[i]>=votes[i-1]){
            inc2[i]=inc2[i-1]+1LL;
        }else inc2[i]=0LL;
    }

    decr2[N-1]=0LL;

    for(i=N-2;i>=0;i--){
        if(votes[i]<=votes[i+1])
            decr2[i]=decr2[i+1]+1LL;
        else
            decr2[i]=0LL;
    }

    met_d[0]=0LL;

    for(i=1;i<K;i++) met_d[i]=met_d[i-1]+inc2[i];

    for(i=K;i<N;i++){
        met_d[i]=met_d[i-1]+min((ll)K-1,inc2[i]);
        met_d[i]-=min((ll)K-1,decr2[i-K]);
    }

    reverse(met_d,met_d+N);

    for(i=K-1;i<N;i++){
        ans[i]=met_i[i]-met_d[i-K+1];
    }


    for(i=K-1;i<N;i++) printf("%lld\n",ans[i]);


    return 0;
}

/** AC!!! **/
