/*
ID: dibyapo2
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#define set(a,b) a[b[0]][b[1]][b[2]][b[3]][b[4]][b[5]][b[6]][b[7]][b[8]]

using namespace std;

struct data{
	int idx[9];
	//int move_list[30];
	//int cnt;
	vector <int> move_list;
};

vector <int> moves[9];
bool taken[4][4][4][4][4][4][4][4][4];

bool is_valid(data v){
	int i;
	for(i=0;i<9;i++){
		if(v.idx[i]!=3) return 0;
	}
	//for(i=0;i<9;i++) printf("Reached! ");
	return 1;

}


data bfs(int init[9]){
	queue <data> Q;
	data temp;
	int i;
	for(i=0;i<9;i++) temp.idx[i]=(init[i]/3)-1;
	temp.move_list.clear();
	memset(taken,0,sizeof(taken));
	//temp.cnt=0;
	Q.push(temp);

	

	while(!Q.empty()){
		data u=Q.front();
		//for(i=0;i<9;i++) printf("%d ",u.idx[i]);
		//printf("%d ",taken[u.idx[0]][u.idx[1]][u.idx[2]][u.idx[3]][u.idx[4]][u.idx[5]][u.idx[6]][u.idx[7]][u.idx[8]]);
		
			int j,k;
			for(j=0;j<9;j++){
				data v;
				//v.cnt=0;
				memset(v.idx,-1,sizeof(v.idx));
				for(k=0;k<moves[j].size();k++) {v.idx[moves[j][k]]=(u.idx[moves[j][k]]+1)%4;}
				//printf("move=[%d][%d], switch from %d to %d ",j,k,u.idx[moves[j][k]],(u.idx[moves[j][k]]+1)%4);}
				
				for(k=0;k<9;k++){
					if(v.idx[k]==-1) v.idx[k]=u.idx[k];	
				}
				if(set(taken,v.idx)==0){
				for(k=0;k<u.move_list.size();k++) {v.move_list.push_back(u.move_list[k]);}
				v.move_list.push_back(j+1);
				//v.cnt+=1;

				if(is_valid(v)) return v;
				
				//printf("Reached! ");
				//for(i=0;i<9;i++) printf("%d ",v.idx[i]);
				set(taken,v.idx)=1;
				Q.push(v);
				}
			}
		
		Q.pop();
	}

}

int main(){

	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);


	moves[0].push_back(0);moves[0].push_back(1);moves[0].push_back(3);moves[0].push_back(4);
	moves[1].push_back(0);moves[1].push_back(1);moves[1].push_back(2);
	moves[2].push_back(1);moves[2].push_back(2);moves[2].push_back(4);moves[2].push_back(5);
	moves[3].push_back(0);moves[3].push_back(3);moves[3].push_back(6);
	moves[4].push_back(1);moves[4].push_back(3);moves[4].push_back(4);moves[4].push_back(5);moves[4].push_back(7);
	moves[5].push_back(2);moves[5].push_back(5);moves[5].push_back(8);
	moves[6].push_back(3);moves[6].push_back(4);moves[6].push_back(6);moves[6].push_back(7);
	moves[7].push_back(6);moves[7].push_back(7);moves[7].push_back(8);
	moves[8].push_back(4);moves[8].push_back(5);moves[8].push_back(7);moves[8].push_back(8);

	int init[9];

	for(int i=0;i<9;i++) scanf("%d",&init[i]);

	data ans=bfs(init);

	if(ans.move_list.size()>0){
	printf("%d",ans.move_list[0]);
	for(int j=1;j<ans.move_list.size();j++) printf(" %d",ans.move_list[j]);
	printf("\n");
	}



	return 0;
}

/** AC!!! (But a pretty messy solution :(  ) **/