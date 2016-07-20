#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct data{
	int cost;
	int score;

	bool operator<(const data &p)const{
		return score<p.score;
	}
};

typedef struct data2{
	int score;
	int pos;
};

vector <data> need,give;
vector <data2> temp;


int main(){

	int N,M,i,j;
	scanf("%d %d",&N,&M);

	for(i=0;i<N;i++){
		data u;
		scanf("%d %d",&u.cost,&u.score);
		need.push_back(u);
	}

	for(i=0;i<M;i++) {data u;scanf("%d %d",&u.cost,&u.score);give.push_back(u);}

	/**for(i=0;i<N;i++){
		for(j=1;j<N;j++){
			if(need[j].score<need[j-1].score){
				temp=need[j].score;
				need[j].score=need[j-1].score;
				need[j-1].score=temp;
				temp=need[j].cost;
				need[j].cost=need[j-1].cost;
				need[j-1].cost=temp;
			}else if(need[j].score==need[j-1].score&&need[j].cost<need[j-1].cost){
				temp=need[j].score;
				need[j].score=need[j-1].score;
				need[j-1].score=temp;
				temp=need[j].cost;
				need[j].cost=need[j-1].cost;
				need[j-1].cost=temp;
			}
		}
	}

	for(i=0;i<M;i++){
		for(j=1;j<M;j++){
			if(give[j].score<give[j-1].score){
				temp=give[j].score;
				give[j].score=give[j-1].score;
				give[j-1].score=temp;
				temp=give[j].cost;
				give[j].cost=give[j-1].cost;
				give[j-1].cost=temp;
			}else if(give[j].score==give[j-1].score&&give[j].cost<give[j-1].cost){
				temp=give[j].score;
				give[j].score=give[j-1].score;
				give[j-1].score=temp;
				temp=give[j].cost;
				give[j].cost=give[j-1].cost;
				give[j-1].cost=temp;
			}
		}
	}*/

	sort(need.begin(),need.end());
	sort(give.begin(),give.end());
	int cost=0;
	bool done=0;

	int r=M-1;
	for(i=N-1;i>=0;i--){
		while(1){
			if(r<0) break;
			if(give[r].score>=need[i].score){
				data2 v;
				v.score=give[r].score;
				v.pos=r;
				temp.push_back(v);
				r--;
			}else break;
		}
		int min_cost=1000000,min_pos;
		for(j=0;j<temp.size();j++){
			if(give[temp[j].pos].cost>=need[i].cost&&give[temp[j].pos].cost<min_cost){
				min_cost=give[temp[j].pos].cost;
				min_pos=j;
			}
		}
		if(min_pos==1000000){
			printf("-1\n");
			done=1;
			break;
		}else{
			cost+=min_cost;
			temp.erase(temp.begin()+min_pos);
		}
	}
	if(!done) printf("%d\n",cost);

	/*int cost=0;
	j=0;
	for(i=0;i<N;i++){
		while(give[j].score<need[i].score){
			j++;
			if(j==M) {printf("-1\n");
			return 0;}
		}
		while(give[j].cost<need[i].cost){
			j++;
			if(j==M) {printf("-1\n");
			return 0;}

		}
		cost+=give[j].cost;
		j++;
	}
	printf("%d\n",cost);*/

	return 0;
}