#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define MAXX 100005

using namespace std;

struct data{
    int x;
    char b;
    bool operator <(const data &p)const{
        return x<p.x;
    }
};
int more_g[MAXX],more_h[MAXX],N,sum_g[MAXX],sum_h[MAXX];
data cows[MAXX];

int main(){

    freopen("fairphoto.in","r",stdin);
    freopen("fairphoto.out","w",stdout);
    cin>>N;
    int i;
    for(i=0;i<N;i++){
        cin>>cows[i].x>>cows[i].b;
    }
    sort(cows,cows+N);
    memset(more_g,-1,sizeof(more_g));
    memset(more_h,-1,sizeof(more_h));
    more_h[0]=-2;
    more_g[0]=-2;
    for(i=0;i<N;i++){
        if(cows[i].b=='G') {sum_g[i]+=1+((i)? sum_g[i-1]:0);sum_h[i]=((i)? sum_h[i-1]:0);}
        else {sum_h[i]+=1+((i)? sum_h[i-1]:0);sum_g[i]=((i)? sum_g[i-1]:0);}

        if(sum_g[i]>sum_h[i]){
            //printf("1 %d %d\n",sum_g[i],sum_h[i]);
            if(more_g[sum_g[i]-sum_h[i]]==-1) more_g[sum_g[i]-sum_h[i]]=i;
            //printf("%d\n",more_g[i]);
        }else if(sum_g[i]<sum_h[i]){
            //printf("2\n");
            if(more_h[sum_h[i]-sum_g[i]]==-1) more_h[sum_h[i]-sum_g[i]]=i;
        }/*else{
            //printf("3\n");
            if(more_g[sum_g[i]-sum_h[i]]==-1) more_g[sum_g[i]-sum_h[i]]=i;
            if(more_h[sum_h[i]-sum_g[i]]==-1) more_h[sum_h[i]-sum_g[i]]=i;
        }*/
    }

    int ans=0;
    for(i=1;i<N;i++){
        int diff=sum_g[i]-sum_h[i];
        //cout<<i<<" "<<diff<<endl;
        if(diff<0){
            diff=-diff;
            //printf("1: %d %d %d\n",more_h[diff],cows[more_h[diff]+1].x,cows[i].x);
            ans=max(ans,((more_h[diff]==-1)? 0:cows[i].x-cows[more_h[diff]+1].x));
        }else if(diff>0){

            ans=max(ans,((more_g[diff]==-1)? 0:cows[i].x-cows[more_g[diff]+1].x));
        }
        if(diff==0) ans=max(ans,cows[i].x-cows[0].x);
    }
    //printf("%d\n",ans);
    sum_g[0]=0 ;
    for(i=1;i<N;i++){
        if(cows[i].b==cows[i-1].b) sum_g[i]=sum_g[i-1]+cows[i].x-cows[i-1].x;
        else sum_g[i]=0;
        ans=max(ans,sum_g[i]);
    }
    cout <<ans<<endl;

    return 0;
}
