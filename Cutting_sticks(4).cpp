#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int length;
bool cuts[1002];
long int dp[1002][1002];
bool taken[1002][1002];

long int call(int i,int j){
	if(i==j) return 0;
	if(taken[i][j]) return dp[i][j];

	long int ret=2147483647,a;
	for(a=i;a<j;a++){
		if(cuts[a]){
			long int temp=call(i,a)+call(a+1,j)+(j+1-i);
			if(temp<ret) ret=temp;
		}
	}
	if(ret>=2147483647) ret=0;

	taken[i][j]=true;
	return dp[i][j]=ret;
}

int main(){
	int cut;
	while(scanf("%d",&length)==1&&length!=0){
		scanf("%d",&cut);
		memset(cuts,0,sizeof(cuts));
		memset(taken,0,sizeof(taken));
		int pos;
		for(int i=0;i<cut;i++){
			scanf("%d",&pos);
			cuts[pos-1]=true;
		}
		long int ans=call(0,length-1);
		printf("The minimum cutting is %ld.\n",ans);
	}

	return 0;
}
/** AC!!! **/