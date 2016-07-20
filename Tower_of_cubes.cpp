#include<iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[102][502];
bool taken[102][502];
int colours[102][8],N;
int dir[102][502];

string name[]={"","front","back","left","right","top","bottom"};
int opp[]={0,2,1,4,3,6,5};

int prt_path(int i,int j){
	if(dir[i][j]==-1){
		return 0;//printf("%d %d\n",j,name[dir[i][j]]);
	}else if(j==0){
		prt_path(opp[dir[i][j]],j+1);
	}else if(dir[i][j]==7){
		prt_path(i,j+1);
	}else{
		printf("%d %s\n",j+1,name[dir[i][j]]);
		prt_path(opp[dir[i][j]],j+1);
	}
	return 0;
}

int call(int last,int pos){
	if(pos==N) return 0;
	if(taken[last][pos]) return dp[last][pos];

	int ret=0,i;
	for(i=1;i<=6;i++){
		if(last==0||colours[pos][i]==last){
			int temp=call(colours[pos][opp[i]],pos+1)+1;
			//printf("Called with pos=%d and last=%d, temp=%d, ret=%d\n",pos,last,temp,ret);
			if(temp>ret){
				ret=temp;
				dir[last][pos]=opp[i];
			}
		}
	}
	int temp2=call(last,pos+1);
	if(temp2>ret){
		ret=temp2;
		dir[last][pos]=7;
	}
	taken[last][pos]=1;
	return dp[last][pos]=ret;
}


int main(){
	int i,j,ans,max_pos=0;
	while(scanf("%d",&N)&&N!=0){
		for(i=0;i<N;i++){ 
			for(j=1;j<=6;j++) scanf("%d",&colours[i][j]);
		}
		memset(taken,0,sizeof(taken));
		memset(dir,-1,sizeof(dir));
		ans=call(0,0);
		/*for(i=0;i<n;i++){
			int temp=call(i,1)+1;
			if(temp>ans){
				ans=temp;
				max_pos=i;
				dir[i][0]=i;
			}
		} */
		printf("%d\n",ans);
		prt_path(0,0);
		/*for(i=0;i<N;i++){
			for(j=0;j<N;j++) printf("%d ",dir[i][j]);
			printf("\n");
		}*/
	}
	return 0;
}