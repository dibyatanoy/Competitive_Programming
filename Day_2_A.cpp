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
#define INF 1e8
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define all(v) v.begin(),v.end()
#define MAXX 100010
#define PII pair <int,int >
#define ll long long
#define MP make_pair

using namespace std;

int s[MAXX],original[MAXX];
int N;
int data[4*MAXX],lazy[4*MAXX];
bool is_lazy[4*MAXX];

void update_node(int idx,int val){
    data[idx]+=(val);
    lazy[idx]+=(val);
    is_lazy[idx]=1;
    return;
}

void update(int idx,int st,int ed,int i,int j,int val){
    if(st==i && ed==j){
        data[idx]+=val;
        lazy[idx]+=val;
        is_lazy[idx]=1;
        return;
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(is_lazy[idx]) {
        update_node(l,lazy[idx]);
        update_node(r,lazy[idx]);
        lazy[idx]=0;
        is_lazy[idx]=0;
    }

    if(j<=mid) update(l,st,mid,i,j,val);
    else if(i>mid) update(r,mid+1,ed,i,j,val);
    else{
        update(l,st,mid,i,mid,val);
        update(r,mid+1,ed,mid+1,j,val);
    }
    return;
}

int query(int idx,int st,int ed,int pos){
    if(st==pos && ed==pos){
        return data[idx];
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(is_lazy[idx]) {
        update_node(l,lazy[idx]);
        update_node(r,lazy[idx]);
        lazy[idx]=0;
        is_lazy[idx]=0;
    }

    if(pos<=mid) return query(l,st,mid,pos);
    else return query(r,mid+1,ed,pos);
}


int main(){

    int i,j,ans=0;

    scanf("%d",&N);

    for(i=1;i<=N;i++){
        scanf("%d",&s[i]);
        original[s[i]]=i;
    }

    int st=1,ed=N;
    int pos,temp,curr;

    for(i=1;i<=N;i++){
        /*for(j=1;j<=N;j++){
            printf("%d ",query(1,1,N,j));
        }
        cout<<endl;*/
        if(i%2){
            pos=original[st];
            temp=pos;
            curr=query(1,1,N,original[st]);
            pos+=curr;

            //printf("%d %d %d\n",st,temp,pos);
            if(pos>st){

                printf("%d\n",pos-st);
                ans+=pos-st;

                update(1,1,N,1,temp-1,+1);
            }else if(pos<st){
                printf("%d\n",st-pos);
                ans+=st-pos;
                update(1,1,N,temp+1,N,-1);
            }
            else printf("0\n");
            st++;

        }else{
            pos=original[ed];
            temp=pos;
            //if(ed==5) printf("! %d\n",pos);
            curr=query(1,1,N,original[ed]);
            pos+=curr;

            //printf("%d %d %d\n",ed,temp,pos);
            if(pos>ed){
                printf("%d\n",pos-ed);
                ans+=pos-ed;
                update(1,1,N,1,temp-1,+1);
            }else if(pos<ed){
                ans+=ed-pos;
                printf("%d\n",ed-pos);
                update(1,1,N,temp+1,N,-1);
            }
            else printf("0\n");

            ed--;
        }
    }

    //printf("%d\n",ans);

    return 0;
}

/** AC!!! **/
