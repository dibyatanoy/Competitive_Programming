/*
ID: dibyapo2
TASK: ariprog
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define MAXX 125000

using namespace std;

struct data{
	int a,diff;

	bool operator <(const data&p)const{
		if(diff!=p.diff){
			return (diff<p.diff);
		}else{
			return a<p.a;
		}
	}
};

vector <data> results;
bool is_bisq[MAXX+5];
int m,n;

void preprocess(){
	int i=0,j=0;
	memset(is_bisq,0,sizeof(is_bisq));
	for(i=0;i<=m;i++){
		for(j=0;j<=m;j++) {if(!is_bisq[i*i+j*j]) is_bisq[i*i+j*j]=1;}
	//printf("reached! ");
	}
	return;
}


int main(){

	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);

	scanf("%d %d",&n,&m);

	preprocess();
	//sort(bisq.begin(),bisq.end());

	int limit=2*m*m;
	int i;
	bool fnd=0;
	
	for(int a=0;a<=limit;a++){
		int next=a;
		int len=1;
		if(!is_bisq[a]) continue;
		for(int diff=1;a+(n-1)*diff<=limit;diff++){
			len=1;
			next=a+diff;
			while(is_bisq[next]){
				len++;
				next=next+diff;
				if(len==n){
					 fnd=1;
					 //printf("%d %d\n",a,diff);
					data temp;
					temp.a=a;
					temp.diff=diff;
					results.push_back(temp);
				}

			}
		}
	}
	sort(results.begin(),results.end());
	if(!fnd) printf("NONE\n");
	else{
		
		for(i=0;i<results.size();i++) printf("%d %d\n",results[i].a,results[i].diff);
	}
	
	return 0;
	
}