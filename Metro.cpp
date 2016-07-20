#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#define eps 1e-15

using namespace std;
double dp[1002][1002];
bool taken[1002][1002];
int length;

typedef struct pos{
	int x;
	int y;
};

pos diag[102];
int N,M;

double minim(double a,double b,double c){
    if((b-a)>eps&&(c-a)>eps)return a;
    else if((a-b)>eps&&(c-b)>eps) return b;
    return c;
}
double minimum(double a,double b){
	if(a<b) return a;
	return b;
}

bool check(int k,int j){
	for(int i=0;i<length;i++){
		if(diag[i].x==k&&diag[i].y==j) {return 1;}
	}
	return 0;
}

double call(int i,int j){
    if(i==N&&j==M) return 0.0;
    if(i>N||j>M) return 1e9;
    if(taken[i][j]) return dp[i][j];

   
        if(check(i+1,j+1)) {dp[i][j]=minim(call(i+1,j)+100.0,call(i,j+1)+100.0,call(i+1,j+1)+sqrt(100*100+100*100));}
        else dp[i][j]=minimum(call(i+1,j)+100.0,call(i,j+1)+100.0);

        //op1=call(i+1,j)+100.0;
        //op2=call(i,j+1)+100.0;
        //dp[i][j]=min(op1,op2);
    //printf("Returning %.2lf\n",dp[i][j]);
    //taken[i][j]=1;
	taken[i][j]=1;
	//printf("%.lf\n",dp[i][j]);
    return dp[i][j];
}

int main(){

   int dia_no;
    scanf("%d%d",&N,&M);
    scanf("%d",&dia_no);
	length=0;
    for(int i=0;i<dia_no;i++){
        int r,c;
        scanf("%d%d",&r,&c);
        diag[++length].x=r;
		diag[length].y=c;
    }
    memset(taken,0,sizeof(taken));

    printf("%.lf\n",call(0,0));

    return 0;
}