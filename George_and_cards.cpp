#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#define pb push_back
#define MP make_pair
#define CLR(x) memset(x,0,sizeof(x));
#define ll long long
#define MAXX 1000100
#define INF 10000000000000000LL
#define Fr first
#define all(rem) rem.begin(),rem.end()
#define Sc second

using namespace std;

struct data{
    int val,pos;
};

int N,K,M;
long long int s;
vector <int> full,no_rem;
vector < pair<int,int> > rem;
int l[MAXX],r[MAXX];
int hist[MAXX];
bool is_rem[MAXX];

int bit[MAXX];

void update(int pos,int val){
    int i;
    for(i=pos;i<MAXX;i+=(i & -i)){
        bit[i]+=val;
    }
    return;
}

int query(int pos){
    if(pos==0) return 0;
    int i,sum=0;
    for(i=pos;i>0;i-= (i & -i)){
        sum+=bit[i];
    }
    return sum;
}

void buildhist(){
    stack<data>now;
    data temp;
    int i,ans=0;

    while(!now.empty()) now.pop();

    l[0]=-1;
    temp.val=hist[0];
    temp.pos=0;
    now.push(temp);


    for(i=1;i<M;i++){
        while(!now.empty() && (now.top().val>=hist[i] || is_rem[now.top().pos])) now.pop();

        if(!now.empty()) l[i]=now.top().pos;
        else l[i]=-1;

        temp.val=hist[i];
        temp.pos=i;

        now.push(temp);

    }

    while(!now.empty()) now.pop();

    r[M-1]=M;
    temp.val=hist[M-1];
    temp.pos=M-1;
    now.push(temp);

    for(i=M-2;i>=0;i--){
        while(!now.empty() && (now.top().val>=hist[i] || is_rem[now.top().pos])) now.pop();

        if(!now.empty()) r[i]=now.top().pos;
        else r[i]=M;

        temp.val=hist[i];
        temp.pos=i;
        now.push(temp);
    }

    /*for(i=0;i<M;i++){
        printf("%d %d ",l[i],r[i]);
    }
    cout<<endl;*/

    //printf("*%d %d %d %d\n",l[0],r[0],l[1],r[1]);
    return;
}

int main(){

    int i,j,k,tmp;

    scanf("%d %d",&N,&K);

    for(i=0;i<N;i++){

        scanf("%d",&tmp);
        full.pb(tmp);
    }
    for(i=0;i<K;i++){
        tmp;
        scanf("%d",&tmp);
        no_rem.pb(tmp);
    }
    j=0;
    CLR(is_rem);
    for(i=0;i<N && j<K;i++){
        if(full[i]==no_rem[j]) j++;
        else {rem.pb(MP(full[i],i));is_rem[i]=1;}
    }
    for(;i<N;i++){
        rem.pb(MP(full[i],i));is_rem[i]=1;
    }

    for(i=0;i<N;i++) hist[i]=full[i];

    sort(all(rem));

    M=N;
    buildhist();

    CLR(bit);

    for(i=0;i<M;i++) printf("%d ",r[i]);
    cout<<endl;
    s=0;


    //printf("%d %d\n",l[2],r[2]);

    for(i=0;i<rem.size();i++){
        int w=r[rem[i].Sc]-l[rem[i].Sc]-1;
        cout<<w;
        w-=query(r[rem[i].Sc])-query(l[rem[i].Sc]+1);

        cout<<" "<<w<<endl;
        s+=(ll)w;

        update(rem[i].Sc+1,1);
    }

    printf("%I64d",s);

    return 0;
}
