/*
ID: dibyapo2
LANG: C++
TASK: holstein
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define sz sizeof
#define all(a) a.begin(),a.end()
#define mem(a,k) memset(a,k,sz a)
#define minim(a,b) (a<b)? a:b

using namespace std;
int V,needed[26],curr[26],G,vit[16][26],results[30],feeds=0,minn=30,call_cnt=0;
int final[30];
bool fnd=0;

bool check(){
	int i;
	//for(i=0;i<V;i++) printf("%d ",curr[i]);
	//printf("\n");
	for(i=0;i<V;i++) {if(curr[i]<needed[i]) return 0;}
	return 1;
}

void set(int pos){
	for(int i=0;i<V;i++) curr[i]+=vit[pos][i];
}

void reset(int pos){
	for(int i=0;i<V;i++) curr[i]-=vit[pos][i];
}

void process(){
	int i;
	for(i=0;i<minn;i++) final[i]=results[i]; 
}

void call(int pos){
	if(pos==-1&&check()){
		//call_cnt++;
		minn=feeds;
		process();
		//printf("Updating: minn= %d ",feeds);
		//minn=feeds;
		//printf("%d",feeds);
		int i;
		//for(i=feeds-1;i>=0;i--) printf(" %d",results[i]);
		return;
	}else if(pos==-1){
		call_cnt++;
		return;
	}else{
		call(pos-1);
		if(fnd) return;
	
		if(feeds+1<minn){
			set(pos);
		results[feeds]=pos+1;
		feeds++;
		call(pos-1);
		feeds--;
		reset(pos);
		}
	}
	return;
}

int main(){

	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);

	scanf("%d",&V);
	int i,j;
	minn=30;
	feeds=0;

	for(i=0;i<V;i++) scanf("%d",&needed[i]);
	scanf("%d",&G);
	for(i=0;i<G;i++){
		for(j=0;j<V;j++) scanf("%d",&vit[i][j]);
	}
	memset(curr,0,sizeof(curr));
	memset(final,0,sizeof(final));
	//printf("Reached! ");
	call(G-1);
	printf("%d",minn);
	for(i=minn-1;i>=0;i--) printf(" %d",final[i]);
	printf("\n");

	return 0;
}

/** AC!!! **/