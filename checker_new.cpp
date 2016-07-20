/*
ID: dibyapo2
TASK: checker
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXX 14

using namespace std;

int N,a[MAXX];
int ans_cnt=0;
bool rowstat[MAXX],lrdlist[2*MAXX],rldlist[2*MAXX]; /*lrd: left upper to right lower, and vice versa*/
int outputs=0;

void construct_cand(int k,int c[MAXX],int *ncandidates){
	int i,j,lim;
	bool legal;

	*ncandidates=0;

	for(i=0;i<N;i++){
		legal=true;
		if(rowstat[i]||lrdlist[k+i]||rldlist[k-i+N-1]){
				continue;
				
		}
		/*for(j=0;j<k;j++){
			if(abs(k-j)==abs(i-a[j])){
				legal=false;
				break;
			}
			
		}*/
		if(legal){
				//printf("Reached! i=%d ",i);
				c[*ncandidates]=i;
				*ncandidates=*ncandidates+1;

		}
	}
	//printf("Reached! ");
	return;
}

void process(){
	ans_cnt+=1;
	outputs+=1;
	if(N>6 && a[0]<N/2) ans_cnt++; /*When N/2, a[0] lies on line of symmetry*/
	if(outputs<=3){
		//printf("now output= %d ",outputs);
		printf("%d",a[0]+1);
		for(int i=1;i<N;i++) printf(" %d",a[i]+1);
		printf("\n");

	}
	return;
}

int backtrack(int k){
	int c[MAXX];
	int ncandidates;
	int i;

	if(k==N){
		process();
	}else{
		construct_cand(k,c,&ncandidates);
		for(i=0;i<ncandidates;i++){
			a[k]=c[i];
			int row=c[i];
			int col=k;
			rowstat[c[i]]=1;
			lrdlist[col+row]=1;
			rldlist[col-row+N-1]=1;
			backtrack(k+1);
			rowstat[c[i]]=0;
			lrdlist[col+row]=0;
			rldlist[col-row+N-1]=0;
		}
	}
	return 0;
}

int main(){

	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);

	scanf("%d",&N);
	memset(rowstat,0,sizeof rowstat);
	memset(lrdlist,0,sizeof(lrdlist));
	memset(rldlist,0,sizeof rldlist);

	int lim=(N>6)? (N-1)/2:(N-1);
	for(int i=0;i<=lim;i++){
		rowstat[i]=1;
		lrdlist[0+i]=1;
		rldlist[0-i+N-1]=1;
		a[0]=i;
		backtrack(1);
		rowstat[i]=0;
		lrdlist[0+i]=0;
		rldlist[0-i+N-1]=0;
	}
	printf("%d\n",ans_cnt);

	return 0;
}