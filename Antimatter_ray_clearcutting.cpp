#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXX 34
#define eps 1e-9
 
using namespace std;
 
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
 
typedef struct pos{
    int x;
    int y;
};
 
pos points[17];
int n,m;
int dp[1<<17];
bool taken[1<<17];

int minim(int a,int b){
	if(a<b) return a;
	return b;
}
 
int call(int bt){
    int cnt=0;
    for(int a=0;a<n;a++){
        if(check(bt,a)==0) cnt++;
    }
    if(cnt==1) return 1;
	if(cnt<=n-m) return 0;
    if(bt==((1<<n)-1)) return 0;
    if(taken[bt]) return dp[bt];
 
    int max2,fmax=100000;
 
    for(int i=0;i<n;i++){
        if(check(bt,i)==0){
            int temp=Set(bt,i);
            max2=100000;
            for(int j=i+1;j<n;j++){
 
                int temp2;
                if(check(temp,j)==0){
                    temp2=Set(temp,j);
                    int temp3=temp2;
                    for(int k=j+1;k<n;k++){
                        if(check(temp3,k)==false&&((points[k].y-points[j].y)*(points[j].x-points[i].x))==((points[j].y-points[i].y)*(points[k].x-points[j].x))) {temp3=Set(temp3,k);}
                    }
                   max2=minim(max2,call(temp3)+1);
 
                }
            }
			fmax=minim(fmax,max2);
            //break;
        }
    }
    dp[bt]=fmax;
    taken[bt]=true;
    return dp[bt];
}
 
int main(){
 
    int testcases;
    scanf("%d",&testcases);
    for(int i=1;i<=testcases;i++){
        scanf("%d %d",&n,&m);
        for(int j=0;j<n;j++) scanf("%d%d",&points[j].x,&points[j].y);
 
        memset(taken,0,sizeof(taken));
		if(i>1) printf("\n");
 
        int ans=call(0);
        printf("Case #%d:\n%d\n",i,ans);
    }
 
    return 0;
}

/** AC!!! **/