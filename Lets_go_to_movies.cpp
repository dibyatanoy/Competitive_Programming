#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define MAXX 100010
#define minim(a,b) (a<b)? a:b
#define maxim(a,b) ((a)>(b))? (a):(b)

using namespace std;

vector <int> edges[MAXX];
map <string,int> people;
int s,f,n;

int main(){

	char seq1[12];
	int i,j;
	string seq;

	while(scanf("%d %d",&s,&f) && s!=0 && f!=0){
		n=0;
		while(scanf("%s",seq1)){
			int curr;
			seq=seq1;
			if(people.find(seq)==people.end()){
				n++;
				curr=n;
			else{
				curr=people.find(seq).second;
			}
			
			seq="";
			scanf("%[^\n]s",seq1);
			for(i=0;i<strlen(seq1);i++){
				if(seq1[i]!=' '){
					seq+=seq1[i];
				}else{
					int t;
					if(people.find(seq)==people.end()){
						n++;
						t=n;
					else{
						t=people.find(seq).second;
					}
					edges[curr].pb(t);
				}
			}
		}
		
	}

	return 0;
}