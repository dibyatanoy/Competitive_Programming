#include <bits/stdc++.h>
#define MAXX 105
#define pb push_back
#define CLR(v) memset(v,0,sizeof(v))
#define PII pair<int, int >
#define ll long long int

using namespace std;

char grid1[MAXX][MAXX],grid[MAXX][MAXX];
ll dp[MAXX][1<<9][1<<9];
bool vis[MAXX][1<<9][1<<9];
ll M,N;

int Set(int N,int pos){return N= (N |(1<<pos));}
int reset(int N,int pos){return N=(N & ~(1<<pos));}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

ll call(int pos,int bt1,int bt2){

    if(pos==N) return 1;
    if(vis[pos][bt1][bt2]) return dp[pos][bt1][bt2];


    int i,j,k;

    vis[pos][bt1][bt2]=1;

    if(bt1==(1<<M)-1){
        int tmp=0;
        for(i=0;i<M;i++){if((pos+2)<N && grid[pos][i]=='#') Set(tmp,i);}
        printf(" *  %d %d %d\n",pos,bt1,bt2);
        return dp[pos][bt1][bt2]=call(pos+1,bt2,tmp);
    }

    ll ret=0;

    for(i=0;i<M;i++){

            if(check(bt1,i)==0){
                int tmp1;
                tmp1=Set(bt1,i);
                int tmp2;

                if(i<M-1 && check(bt1,i+1)==0){
                    tmp1=Set(bt1,i);
                    tmp1=Set(tmp1,i+1);
                    ret+=call(pos,tmp1,bt2);
                }
                if(pos<N-1 && check(bt2,i)==0){
                    tmp1=Set(bt1,i);
                    tmp2=Set(bt2,i);
                    ret+=call(pos,tmp1,tmp2);
                }
                if(i<M-1 && pos<N-1 && check(bt1,i+1)==0 && check(bt2,i+1)==0){
                    tmp1=Set(bt1,i+1);
                    tmp2=Set(bt2,i+1);
                    ret+=call(pos,tmp1,tmp2);
                }
                if(i<M-1 && pos<N-1 && check(bt1,i+1)==0 && check(bt2,i)==0){
                    tmp1=Set(bt1,i+1);
                    tmp2=Set(bt2,i);
                    ret+=call(pos,tmp1,tmp2);
                }
                if(i>0 && pos<N-1 && check(bt2,i-1)==0 && check(bt2,i)==0){
                    tmp2=Set(bt2,i-1);
                    tmp2=Set(bt2,i);
                    ret+=call(pos,tmp1,tmp2);
                }
                if(i<M-1 && pos<N-1 && check(bt2,i+1)==0 && check(bt2,i)==0){
                    tmp2=Set(bt2,i+1);
                    tmp2=Set(bt2,i);
                    ret+=call(pos,tmp1,tmp2);
                }
                break;
            }

    }

    printf("%d %d %d %lld\n",pos,bt1,bt2,ret);

    return dp[pos][bt1][bt2]=ret;

}

int main(){

    int i,j,k;
    scanf("%lld %lld",&M,&N);

    for(i=0;i<M;i++){

            scanf("%s",grid[i]);
    }

    if(M>8){
        for(i=0;i<M;i++){
            for(j=0;j<N;j++){
                grid[j][i]=grid1[i][j];
            }
        }
    }
    swap(M,N);
    CLR(vis);
    int t[2];
    CLR(t);

    for(i=0;i<2;i++){
        for(j=0;j<M;j++){
            if(grid[j][i]=='#') t[i]=Set(t[i],j);
        }
    }



    ll ans=call(0,t[0],t[1]);

    printf("%lld\n",ans);

    return 0;
}
