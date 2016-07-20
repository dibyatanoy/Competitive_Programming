#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXX 10

#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b

int Set(int N,int pos){return N=N | (1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

using namespace std;

int dp[1<<MAXX][1<<MAXX],n;
int taken[1<<MAXX][1<<MAXX];
int grid[8][8];

int call(int alice,int bob){
    if(bob&(1<<(n-1))) return 0;
	if(taken[alice][bob]) return dp[alice][bob];

    int prof1=-90000,prof2=90000;

    for(int i=1;i<=n;i++){
        if(check(alice,i)==0){

            int temp=Set(alice,i);
            for(int j=1;j<=n;j++){

                if(check(bob,j)==0){
					int ret=call(temp,Set(bob,j))+grid[i-1][j-1];
					//if(prof2<-10000) prof2=ret;
                    /*else*/ prof2=min(prof2,ret);
					//printf("Returning prof2=%d ",prof2);
                }
            }
            prof1=max(prof1,prof2);
			
        }
    }
    taken[alice][bob]=1;
	//printf("Returning prof1=%d ",prof1);
    return dp[alice][bob]=prof1;
}



int main(){
    int testcases,i,j;
    scanf("%d",&testcases);

    for(i=1;i<=testcases;i++){

        scanf("%d",&n);
        memset(taken,0,sizeof(taken));
        for(j=0;j<n;j++){
            for(int k=0;k<n;k++) scanf("%d",&grid[j][k]);
        }
        int ans=call(0,0);

        printf("%d\n",ans);
    }
    return 0;
}