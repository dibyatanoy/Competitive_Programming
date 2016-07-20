#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#define MOD 1000
#define MAXX 502
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a));

using namespace std;

struct data{
	int d,x,y;
	
	bool operator<(const data &p)const{
		return d<p.d;
	}
};

int N,wts[MAXX],bit[MAXX][MAXX];
vector <data> diffs;

void update(int pos1,int pos2,int val){
	int i,j;
	for(i=pos1;i<=MAXX;i+=(i & -i)){
		for(j=pos2;j<=MAXX;j+=(j & -j)) bit[i][j]=(bit[i][j]+val)%MOD;
	}
	return;
}

int query(int pos1,int pos2){
	int i,j,ret=0;
	for(i=pos1;i>0;i-=(i & -i)){
		for(j=pos2;j>0;j-=(j & -j)) ret=(ret+bit[i][j])%MOD;
	}
	return ret;
}


int main(){

	int kases,i,j,k;

	scanf("%d",&kases);

	for(i=1;i<=kases;i++){
		vector<data>curr;
		curr.clear();
		scanf("%d",&N);

		for(j=0;j<N;j++) scanf("%d",&wts[j]);
		diffs.clear();
		CLR(bit);
		for(j=0;j<N;j++){
			for(k=j+1;k<N;k++) {
				data temp;
				temp.d=abs(wts[k]+wts[j]);temp.x=j+1;temp.y=k+1;
				diffs.pb(temp);
			}
		}

		int ans=0;
		sort(diffs.begin(),diffs.end());

		//for(j=0;j<diffs.size();j++) printf("%d %d %d\n",diffs[j].x,diffs[j].y,diffs[j].d);

		for(j=0;j<diffs.size();j++){
			int now=1;
			
			if(diffs[j].y-1>0) now+=query(MAXX-1,diffs[j].y-1)-query(diffs[j].x,diffs[j].y-1);

			ans=(ans+now)%MOD;

			//printf("!\n");

			data temp2;
			temp2.d=now;
			temp2.x=diffs[j].x;
			temp2.y=diffs[j].y;
			curr.pb(temp2);
			
			if(j!=diffs.size()&&diffs[j].d==diffs[j+1].d) {
				//printf("!\n");
				continue;
			}
			else{
				for(k=0;k<curr.size();k++)
					update(curr[k].x,curr[k].y,curr[k].d);
				curr.clear();
			}
		}
		printf("Case %d: %d\n",i,ans%MOD);
	}

	return 0;
}

/** AC!!! Using long long int (not shown here) **/