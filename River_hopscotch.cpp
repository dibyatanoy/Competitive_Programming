#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXX 50005

using namespace std;

struct data{
    int dis,u,v;
    bool operator <(const data &p)const{
        return dis>p.dis;
    }
};

int L,N,M;
int dist[MAXX],prev[MAXX],next[MAXX];
bool taken[MAXX];
priority_queue<data>pq;

int main(){

    int i,j;
    data temp;

    cin>>L>>N>>M;
    dist[0]=0;
    dist[N+1]=L;

    for(i=1;i<=N;i++) cin>>dist[i];
    sort(dist,dist+N+2);
    memset(taken,0,sizeof(taken));

    for(i=1;i<=N+1;i++){
        temp.u=i-1;
        temp.v=i;
        temp.dis=dist[i]-dist[i-1];
        pq.push(temp);
        prev[i]=i-1;
        next[i-1]=i;
    }

    while(M && !pq.empty()){
        data curr=pq.top();
        pq.pop();

        if(!taken[curr.u] && !taken[curr.v]){
            M--;
            //printf("%d %d %d %d\n",dist[next[curr.v]],dist[curr.v],dist[curr.u],dist[prev[curr.u]]);
            if((dist[next[curr.v]]-dist[curr.v]<=dist[curr.u]-dist[prev[curr.u]] && curr.v!=N+1) || (curr.u==0&&curr.v!=N+1)){
                //cout << "1 "<<curr.v <<endl;
                temp.u=curr.u;
                temp.v=next[curr.v];
                temp.dis=dist[temp.v]-dist[temp.u];
                next[temp.u]=temp.v;
                prev[temp.v]=temp.u;
                taken[curr.v]=1;

                pq.push(temp);
            }else if(curr.u!=0){
                //cout<<"1 "<<curr.u<<endl;
                temp.u=prev[curr.u];
                temp.v=curr.v;
                temp.dis=dist[temp.v]-dist[temp.u];
                taken[curr.u]=1;
                prev[temp.v]=temp.u;
                next[temp.u]=temp.v;

                pq.push(temp);
            }
        }
    }
    int mn=1000000005;
    int c=0;

    for(i=1;i<=N+1;i++){
        if(!taken[i]){
            mn=min(mn,c+dist[i]-dist[i-1]);
            c=0;
        }else c+=dist[i]-dist[i-1];
    }
    //mn=min(mn,c);
    //for(i=0;i<=N+1;i++) cout << taken[i] <<endl;

    cout<<mn<<endl;

    return 0;
}

