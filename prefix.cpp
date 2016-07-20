/*
ID: dibyapo2
LANG: C++
TASK: prefix
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

bool dp[200001];
vector<string> prim;
string seq;

int main(){

	string temp1;
	while(scanf("%s",temp1)&&temp1[0]!='.'){
		prim.push_back(temp1);
	}
	seq="";
	
	bool cont=0;
	while(scanf("%s",temp1)){
		seq+=temp1;
		seq.pop_back();
	}
	
	return 0;
}