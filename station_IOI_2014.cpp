#include<bits/stdc++.h>
#include "station.h"
#define MAXX 500005
#define INF 10000000

using namespace std;

int st_cnt,dist[MAXX],days[MAXX];

int findMinDays(int n, int k, int lodge[]){
    int i,j,curr;

    dist[1]=0;st_cnt=2;
    curr=0;
    for(i=1;i<=n;i++){

        //printf("%d %d\n",i,lodge[i]);
        if(lodge[i-1]==1 && i!=1){

            dist[st_cnt]=dist[st_cnt-1]+curr+1;
            //printf("%d %d %d\n",i,lodge[i],dist[st_cnt]);

            //printf("%d %d %d\n",i,lodge[i],dist[st_cnt]);
            st_cnt++;
            curr=0;
        }else if(i!=1) curr++;
    }

    int st=1,ed=2;
    for(i=0;i<=n;i++) days[i]=-INF;
    //printf("%d\n",st_cnt);

    //for(i=0;i<st_cnt;i++) printf("%d\n",dist[i]);
    days[1]=0;

    for(ed=2;ed<st_cnt;ed++){
        while(dist[ed]-dist[st]>k && st<ed) st++;
        days[ed]=days[st]+1;
    }

    if(days[st_cnt-1]<0) return -1;
    else return days[st_cnt-1];
}

/*int main(){

    int l[]={1,1,1,1,1,0,1,1,0,1};
    printf("%d\n",findMinDays(10,4,l));
    return 0;
}*/

/** AC!!! **/
