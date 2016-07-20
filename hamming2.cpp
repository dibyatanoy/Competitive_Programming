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
int N,B,D;

int check(int a){
	int i,j;
	string temp="";
	for(i=a;i!=0;i/=2){
		temp+=(i%2)-'0';
	}
	char zero='0';
	
	for(i=temp.length()+1;i<=B;i++) temp+=0-'0';
	
		int hamdist=0;
	for(i=0;i<results.size();i++){
		hamdist=0;
		for(j=0;j<B;j++){
			if(temp[j]!=bin[i][j]) hamdist++;
			if(hamdist>D) {/*printf("%d does not match %d\n",a,results[i]);*/break;}
		}
		if(hamdist<D) return 0;
	}
	results.push_back(a);
	bin.push_back(temp);

	return 1;

}

void output(){
	int i,prev=0;
	while(N>0){
		--N;
		printf("%d",results[prev]);
		prev++;
		for(i=prev;i<prev+9&&N>0;i++,N--){
			printf(" %d",results[i]);
		}
		prev=prev+9;
		printf("\n");
	}
}

int main(){

	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);

	int cnt;
	scanf("%d %d %d",&N,&B,&D);

	int i,j;
	mem(checked,0);
	int limit=pow(2,B);
	//printf("%d ",limit);

	for(i=0;i<=limit;i++){
		//cnt=0;
		
			checked[i]=1;
			cnt=1;
			results.clear();
			bin.clear();
			results.push_back(i);
			string temp="";
			for(j=i;j!=0;j/=2){
				temp+=(j%2)-'0';
			}
			for(j=temp.length()+1;j<=B;j++) temp+=0-'0';
			bin.push_back(temp);
			for(j=i+1;j<=limit&&cnt<N;j++){
				if(check(j)){
					//results.push_back(j);
					cnt++;
				}
				checked[j]=1;
			}
			if(cnt==N){
				output();
				break;
			}
		
	}
	//printf("cnt= %d ",cnt);

	return 0;
}

/** AC!!! **/