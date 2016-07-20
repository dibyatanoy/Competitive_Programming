/*
ID: dibyapo2
LANG: C++
TASK: hamming
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#define sz sizeof
#define all(a) a.begin(),a.end()
#define mem(a,k) memset(a,k,sz a)
#define minim(a,b) (a<b)? a:b

using namespace std;

bool checked[257];
vector <int> results;
vector <string> bin;

int check(int a){
	int i,j;
	string temp="";
	for(i=a;i!=0;i/=2){
		temp+=(i%2)-'0';
	}
	if(temp.length()<B){
		for(i=temp.length+1;i<=B;i++) temp+="0";
	}
	for(i=0;i<results.size();i++){
		int hamdist;
		for(j=0;j<B;j++){
			if(temp[j]!=bin[i][j]) ham_dist++;
			if(hamdist>D) return 0;
		}
	}
	if(hamdist<D) return 0;
	results.push_back(a);
	bin.push_back(temp);

	return 1;

}

void output(){
	int i,prev=0;
	while(N>0){
		printf("%d",results[prev++]);
		for(i=prev;i<10;i++,prev++,N--){
			printf(" %d",results[i]);
		}
		printf("\n");
	}
}

int main(){

	int N,B,D,cnt;
	scanf("%d %d %d",&N,&B,&D);

	int i,j;
	mem(checked,0);
	int limit=pow(2,B);

	for(i=0;i<=limit;i++){
		cnt=0;
		if(!checked[i]){
			cnt=1;
			results.clear();
			bin.clear();
			results.push_back(i);
			string temp="";
			for(j=a;j!=0;j/=2){
				temp+=(j%2)-'0';
			}
			bin.push_back(temp);
			for(j=i+1;j<=limit&&cnt<N;j++){
				if(check(j)){
					results.push_back(j);
					cnt++;
				}
			}
			if(cnt==N){
				output();
				break;
			}
		}
	}

	return 0;
}