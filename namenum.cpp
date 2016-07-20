/*
ID: dibyapo2
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

string check(string entry){
	string temp="";
	int i,j;
	for(i=0;i<entry.length();i++){
		if(entry[i]=='Q'||entry[i]=='Z'){
			temp="";
			return temp;
		}else if(entry[i]<'Q'){
			temp+=((entry[i]-'A')/3)+'2';
		}else{
			temp+=((entry[i]-'A'-1)/3)+'2';
		}
	}
	return temp;
}

int main(){

	ofstream fout("namenum.out");
	ifstream fin("namenum.in");
	ifstream fdict("dict.txt");

	int i,j;
	bool fnd=false;
	string next_entry,num;
	fin >> num;
	//printf("Reached! ");

	while(fdict >> next_entry){
		if(next_entry.length()==num.length()){
			if(check(next_entry)==num){
				fnd=true;
				fout << next_entry << endl;
			}
		}

	}
	if(!fnd) fout << "NONE" << endl; 

	return 0;
}

/** AC!!! Though it's not working here.**/