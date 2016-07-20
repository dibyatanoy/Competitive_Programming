#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define maxim(a,b) (a>b)? a:b
#define minim(a,b) (a<b)? a:b
#define INF 1e7
#define pb push_back
#define mp make_pair

using namespace std;

int gcd(int a,int b){
	return (b==0)? a:gcd(b,a%b);
}

int main(){

	vector <string> words;
	string letter;
	int n;

	scanf("%d",&n);
	string ss;
	int i,j;

	for(i=0;i<n;i++){
		cin >> ss;
		words.pb(ss);
	}
	cin >> letter;
	j=0;
	int curr_pos=-1;

	int l=letter.size();
	for(i=0;i<l;i++){
		if(curr_pos==-1){
			if(letter[i]=='<') curr_pos=-2;
		}
		else if(curr_pos==-2){
			if(letter[i]=='3') {curr_pos=0;
				if(j==n) break;
			}
		}else{
			if(letter[i]==words[j][curr_pos]){
				curr_pos++;
				if(curr_pos==words[j].size()){
					
					j++;
					curr_pos=-1;
				}
			}
		}
	}
	if(j==n&&curr_pos==0) printf("yes\n");
	else printf("no\n");

	return 0;
}

/** Curse u, char array!!! **/