#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#define INF 100000000
#define pb push_back
#define MP make_pair
#define all(v) v.begin(),v.end()
#define Fr first
#define Sc second
#define CLR(x) memset(x,0,sizeof(x))
#define MAXX 1100
using namespace std;

struct data{
    int val,pos;
};

int mat[MAXX][MAXX];
int ht[MAXX][MAXX];
int R,S;
int M;

int hist[MAXX];

int buildhist(){
    stack<data>now;
    data temp;
    int l[MAXX],r[MAXX],i,ans=0;

    while(!now.empty()) now.pop();

    l[0]=-1;
    temp.val=hist[0];
    temp.pos=0;
    now.push(temp);


    for(i=1;i<M;i++){
        while(!now.empty() && (now.top().val>=hist[i])) now.pop();

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
        while(!now.empty() && now.top().val>=hist[i]) now.pop();

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
    for(i=0;i<M;i++){
        ans=max(ans,hist[i]*(r[i]-1-l[i]+1));
    }


    return ans;
}


int main(){

    int i,j,k;

    scanf("%d %d",&R,&S);

    for(i=0;i<R;i++){
        for(j=0;j<S;j++){

            scanf("%d",&mat[i][j]);
        }
    }

    for(j=0;j<S-1;j++){
        for(i=1;i<R;i++){
            //printf("%d %d %d %d\n",mat[i][j],mat[i-1][j],mat[i][j+1],mat[i-1][j+1]);
            if((mat[i][j]-mat[i-1][j]) >= (mat[i][j+1]-mat[i-1][j+1])){
                if(ht[i-1][j]!=0) ht[i][j]=ht[i-1][j]+1;
                else ht[i][j]=2;
            }else ht[i][j]=0;
        }
    }

    int ans=0;
    M=S-1;

    /*for(i=1;i<R;i++){
        for(j=0;j<S;j++){
            printf("%d ",ht[i][j]);
        }
        printf("\n");
    }*/

    for(i=1;i<R;i++){
        for(j=0;j<S-1;j++){
            hist[j]=ht[i][j];
        }
        ans=max(ans,buildhist());
    }
    printf("%d\n",ans);

    return 0;
}
