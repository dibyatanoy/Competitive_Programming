#include <bits/stdc++.h>
#define MAXX 100005
#define INF 1e7

using namespace std;

struct c{
    int pos;
    char col;

    bool operator <(const c &p)const{
        return pos<p.pos;
    }
};

int data[2][8*MAXX];
int N,pos[MAXX],w_sum[MAXX],s_sum[MAXX];
c cow[MAXX];

void update(int idx,int t,int st,int ed,int pos,int val){
    if(st==pos && ed==pos){
        data[t][idx]=min(data[t][idx],val);
        return;
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(pos<=mid) update(l,t,st,mid,pos,val);
    else update(r,t,mid+1,ed,pos,val);

    data[t][idx]=min(data[t][l],data[t][r]);
    return;
}

int query(int idx,int t,int st,int ed,int i,int j){
    if(st==i && ed==j){
        return data[t][idx];
    }
    int mid=(st+ed)/2;
    int l=2*idx;
    int r=l+1;

    if(j<=mid) return query(l,t,st,mid,i,j);
    else if(i>mid) return query(r,t,mid+1,ed,i,j);
    else return min(query(l,t,st,mid,i,mid),query(r,t,mid+1,ed,mid+1,j));
}

int main(){

    cin>>N;

    int i,j,k;
    w_sum[0]=0;
    s_sum[0]=0;

    for(i=1;i<=N;i++){
        cin>>cow[i].pos>>cow[i].col;

    }

    sort(cow+1,cow+N+1);

    for(i=1;i<=N;i++){
        if(cow[i].col=='W'){
            w_sum[i]=1+w_sum[i-1];
            s_sum[i]=s_sum[i-1];
        }else{
            w_sum[i]=w_sum[i-1];
            s_sum[i]=s_sum[i-1]+1;
        }
    }

    for(i=0;i<8*MAXX;i++) {data[0][i]=INF;data[1][i]=INF;}
    int ans=0;

	update(1,0,1,2*N+1,N+1,0);

    for(i=1;i<=N;i++){
        //if(w_sum[i]<s_sum[i]){
            int diff=s_sum[i]-w_sum[i];
            int p=query(1,(i%2),1,2*N+1,diff+N+1,2*N+1);
            //cout << p <<endl;

            if(p!=INF){
                ans=max(ans,cow[i].pos-cow[p+1].pos);
            }
            update(1,i%2,1,N,s_sum[i]-w_sum[i]+N+1,i);
        /*}else{
            ans=max(ans,cow[i].pos-cow[1].pos);
        }*/
		//update(1,i%2,1,N,s_sum[i]-w_sum[i]+N+1,i);
    }
    cout<<ans<<endl;

    return 0;
}
