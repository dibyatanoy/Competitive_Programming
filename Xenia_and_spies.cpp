#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main(){

	string seq="";
	int maxx=0;

	int l[10004],r[10004];
	int N,M,i,j,s,f;
	scanf("%d %d %d %d",&N,&M,&s,&f);
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));

	for(i=0;i<M;i++){
		int step;
		if(step>maxx) maxx=step;
		scanf("%d",&step);
		scanf("%d %d",&l[step],&r[step]);
	}
	int curr=s;

	if(s<f){
		for(i=1;i<=maxx&&curr!=f;i++){
			if((curr>=l[i]&&curr<=r[i])||(curr+1>=l[i]&&curr+1<=r[i])) seq+="X";
			else {seq+="R";curr=curr+1;}
		}
		if(curr!=f){
			for(i=curr;i<f;i++) seq+="R";
		}
	}else{
		curr=f;
		for(i=1;i<=maxx&&curr!=s;i++){
			if((curr>=l[i]&&curr<=r[i])||(curr-1>=l[i]&&curr-1<=r[i])) seq+="X";
			else {seq+="L";curr=curr-1;}
		}
		if(curr!=s){
			for(i=curr;i>f;i--) seq+="L";
		}
	}

	for(i=0;i<seq.length();i++){
		printf("%c",seq[i]);
	}
	printf("\n");

	return 0;
}