#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define INF 1e7
#define MAXX 100010
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define all(v) v.begin(),v.end()
#define MP make_pair
#define PII pair<int,int >
#define ll long long

using namespace std;

struct data{
    long long int x,y;

    bool operator <(const data &p)const{
        return x<p.x;
    }
};

long long int a[MAXX],b[MAXX],data_r[MAXX],data_l[MAXX];
data temp[MAXX];
int N;
int affects[MAXX];

int data[4*MAXX];

void update(int idx,int st,int ed,int pos,int val){
    if(st>ed) return;

    if(st==pos && ed==pos){
        data[idx]=val;
        return;
    }
    int l=2*idx;
    int r=l+1;
    int mid=(st+ed)/2;

    if(pos<=mid) update(l,st,mid,pos,val);
    else update(r,mid+1,ed,pos,val);

    data[idx]=max(data[l],data[r]);

    return;
}

int query(int idx,int st,int ed,int i,int j){

    if(i>j) return 0;

    if(st==i && ed==j){
        return data[idx];
    }
    int l=2*idx;
    int r=l+1;
    int mid=(st+ed)/2;

    if(j<=mid) return query(l,st,mid,i,j);
    else if(i>mid) return query(r,mid+1,ed,i,j);
    else return max(query(l,st,mid,i,mid),query(r,mid+1,ed,mid+1,j));
}

int main(){

    int i,j,k;
    int T;

    scanf("%d",&T);


    for(i=0;i<T;i++){

        scanf("%d",&N);
        CLR(data_r);


        for(j=1;j<=N;j++){
            scanf("%lld %lld",&temp[j].x,&temp[j].y);

        }

        sort(temp+1,temp+N+1);

        for(j=1;j<=N;j++) {data_r[j]=temp[j].x;b[j]=temp[j].y;}

        a[1]=0;
        for(j=2;j<=N;j++) a[j]=a[j-1]+data_r[j]-data_r[j-1];

        memset(affects,0,sizeof(affects));
        CLR(data_l);
        memset(data,0,sizeof(data));

        //for(j=1;j<=N;j++) cout<<a[j]<<" "<<endl;
        //cout<<endl;

        int pos,range;

        for(j=N;j>=1;j--){

            pos=upper_bound(a+1,a+N+1,a[j]+b[j])-(a);
            //cout<<pos<<endl;
            pos--;

            //printf("* %d %d\n",j+1,pos);
            range=max(query(1,1,N,j+1,pos),pos);
            //cout<<range<<endl;

            affects[j]+=range-j+1;
            //cout<<affects[j]<<endl;
            //cout<<"!"<<endl;
            update(1,1,N,j,range);
        }

        memset(data,0,sizeof(data));

        data_l[N]=0;

        for(j=N-1;j>=1;j--) data_l[j]=data_l[j+1]+a[j+1]-a[j];
        reverse(data_l+1,data_l+N+1);
        reverse(b+1,b+N+1);
        reverse(affects+1,affects+N+1);

        for(j=N;j>=1;j--){
            pos=upper_bound(data_l+1,data_l+N+1,data_l[j]+b[j])-data_l;
            pos--;

            //printf("%d !\n",pos);

            //printf("* %d %d\n",j+1,pos);
            range=max(query(1,1,N,j+1,pos),pos);
            //cout<<range-j+1<<endl;
            affects[j]+=range-j+1;
            //cout<<"!"<<endl;
            update(1,1,N,j,range);
        }

        int mn=INF;

        for(j=1;j<=N;j++) affects[j]--;

        for(j=1;j<=N;j++) mn=min(mn,affects[j]);

        printf("%d\n",mn);

    }

    return 0;
}
