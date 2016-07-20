/*
ID: dibyapo2
LANG: C++
TASK: beads
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char beads[500];
int N;

int mod(int a){
	if(a<0) return (a+N)%(N);
	else return a%(N);
}

int main(){

	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);

	scanf("%d",&N);
	char in;
	int a=0;
	scanf("%s",beads);
	//printf("%s\n",beads);
	
	int max=0,curr=0,j=0,reached=0;
	for(int i=0;i<N;i++){

		reached=0;
		char curr_c;
		int k;
		curr=1;
		j=mod(i);


		if(beads[i]!='w') {reached=1;curr_c=beads[i];}
		else{
			for(j=mod(i+1);mod(j)!=i;j++){
				if(beads[j]!='w') {curr_c=beads[j];curr++;break;}
				else curr++;
			}
		}
		if(reached==1||mod(j)!=i){

			for(k=mod(j+1);mod(k)!=mod(i);k++){
				if(beads[mod(k)]==curr_c||beads[mod(k)]=='w') curr++;
				else break;
			}
		}else{
			k=mod(j);
		}
		//printf("Now i=%d, curr=%d ",i,curr);

		if(mod(k)!=mod(i)){
		curr+=1;
		j=mod(i-1);

		//printf("Now i=%d, curr=%d ",i,curr);
		reached=0;

		if(beads[mod(i-1)]!='w') {reached=1;curr_c=beads[mod(i-1)];}
		else{
			for(j=mod(i-2);mod(j)!=mod(k-1);j--){
				if(beads[j]!='w'){
					curr_c=beads[j];
					curr++;
					break;
				}else curr++;
			}
		}
		if(reached==1||mod(j)!=mod(k-1)){
			for(int l=mod(j-1);mod(l)!=mod(k-1);l--){
				if(beads[mod(l)]==curr_c||beads[mod(l)]=='w') curr++;
				else break;
			}
		}
		//printf("Now i=%d, curr=%d ",i,curr);
		}



		if(curr>max) max=curr;
	}

	printf("%d\n",max);


	return 0;
}

/** AC!!! **/