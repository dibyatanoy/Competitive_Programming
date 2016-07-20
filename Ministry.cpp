#include <iostream>
#include <cstdio>
#include <cstring>
#define TOP 0
#define LEFT 1
#define RIGHT 2

using namespace std;

__int64 dp[102][502][4];
long int fees[102][502];
int direc[102][502][4],M,N;
bool taken[102][502][4];

int prt_path(int flr,int room,int dir){
	if(flr==M-1){
		printf("%d\n",room+1);
		return 0;
	}else{
		printf("%d ",room+1);
		if(direc[flr][room][dir]==TOP) prt_path(flr+1,room,TOP);
		else if(direc[flr][room][dir]==LEFT) prt_path(flr,room-1,LEFT);
		else prt_path(flr,room+1,RIGHT);
		return 0;
	}
}

__int64 call(int flr,int room,int dir){
	if(flr==M-1) return fees[flr][room];
	if(room<0||room==N) return 1e12;
	if(taken[flr][room][dir]) return dp[flr][room][dir];

	__int64 op1,op2,op3;
	if(dir==TOP){
		op1=call(flr+1,room,TOP);
		op2=call(flr,room-1,LEFT);
		op3=call(flr,room+1,RIGHT);
		if(op1<op2&&op1<op3){
			dp[flr][room][dir]=op1+fees[flr][room];
			direc[flr][room][dir]=TOP;
		}else if(op2<op3){
			dp[flr][room][dir]=op2+fees[flr][room];
			direc[flr][room][dir]=LEFT;
		}else{
			dp[flr][room][dir]=op3+fees[flr][room];
			direc[flr][room][dir]=RIGHT;
		}
	}else if(dir==LEFT){
		op1=call(flr+1,room,TOP);
		op2=call(flr,room-1,LEFT);
		if(op2<op1){
			dp[flr][room][dir]=op2+fees[flr][room];
			direc[flr][room][dir]=LEFT;
		}else{
			dp[flr][room][dir]=op1+fees[flr][room];
			direc[flr][room][dir]=TOP;
		}
	}else{
		op1=call(flr+1,room,TOP);
		op2=call(flr,room+1,RIGHT);
		if(op2<op1){
			dp[flr][room][dir]=op2+fees[flr][room];
			direc[flr][room][dir]=RIGHT;
		}else{
			dp[flr][room][dir]=op1+fees[flr][room];
			direc[flr][room][dir]=TOP;
		}
	}

	taken[flr][room][dir]=1;
	return dp[flr][room][dir];
}

int main(){
	__int64 ans=1e12;
	int min_r=0;
	scanf("%d%d",&M,&N);
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&fees[i][j]);
		}
	}
	memset(taken,0,sizeof(taken));
	for(int a=0;a<N;a++){
		__int64 ret=call(0,a,TOP);
		if(ans>ret){ans=ret;min_r=a;}
	}
	prt_path(0,min_r,TOP);
	//printf("%I64d\n",ans);
	
	return 0;
}

/** AC!!!!!!!!!!!!!!!! 3-state dp! **/