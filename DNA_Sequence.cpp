#include <bits/stdc++.h>
#define MAXX 16
#define INF 2000

using namespace std;

int dp[MAXX+1][1<<MAXX],n,dir[MAXX+1][1<<MAXX],pt[MAXX+1][1<<MAXX];
bool vis[MAXX+1][1<<MAXX];
string seq[MAXX+1];

int Set(int N,int pos){return N=N|(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

int call(int last,int mask){
    if(mask==(1<<n)-1) return 0;
    if(vis[last][mask]) return dp[last][mask];

    int ret=INF,i,j,k,c_cost;
    char c;
    bool fnd=0;

    for(i=1;i<=n;i++){
        if(check(mask,i-1)==0){
            for(j=0;j<seq[last].length();j++){
                fnd=0;

                for(k=0;k+j<seq[last].length() && k<seq[i].length();k++){
                    if(seq[last][j+k]!=seq[i][k]) {fnd=0;break;}
                    if(k==seq[i].length()-1) {fnd=1;break;}
                    if(j+k==seq[last].length()-1) {fnd=1;break;}
                }
                if(fnd) break;
            }
            //if(last==2) cout<<"k= "<<k<<endl
            if(last==0) k=-1;
            //cout << last << " " << i << " "<< k <<endl;
            int left=seq[i].length()-(k+1);
            int temp=Set(mask,i-1);
            c_cost=call(((left)? i:last),temp)+left;

            if(c_cost<ret) {ret=c_cost;dir[last][mask]=i;pt[last][mask]=k;c="}
            else if(c_cost=ret)
        }
    }
    vis[last][mask]=1;
    return dp[last][mask]=ret;
}

int main(){

    int kases,i,j;
    scanf("%d",&kases);

    for(i=1;i<=kases;i++){
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));

        for(j=0;j<n;j++) cin >> seq[j+1];
        seq[0]="B";

        printf("Case %d: %d\n",i,call(0,0));

    }

    return 0;
}
