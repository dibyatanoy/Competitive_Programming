/*
ID: dibyapo2
PROG: calfflac
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int main(){

	string temp,original="",modified="";
	int map[20001],max=1,max_idx=0;
	int i,j;

	freopen("calfflac.in","r",stdin);
	freopen("calfflac.out","w",stdout);

	while(getline(cin,temp)){
		original+=temp;
		original+="\n";
	}

	for(i=0,j=0;i<original.length();i++){
		if(original[i]>='a'&&original[i]<='z') {modified+=original[i];map[j++]=i;}
		else if(original[i]>='A'&&original[i]<='Z'){
			modified+=original[i]-'A'+'a';
			map[j++]=i;
		}
	}

	for(i=0;i<=j;i++){
		int st,ed,temp_cnt=1;
		for(st=i-1,ed=i+1;st>=0&&ed<=j;st--,ed++){
			if(modified[st]!=modified[ed]) break;
			else{
				temp_cnt+=2;
			}
		}
		if(temp_cnt>max){
			max=temp_cnt;
			max_idx=st+1;
		}
		temp_cnt=0;
		for(st=i,ed=i+1;st>=0&&ed<=j;st--,ed++){
			if(modified[st]!=modified[ed]) break;
			else{
				temp_cnt+=2;
			}
		}
		if(temp_cnt>max){
			max=temp_cnt;
			max_idx=st+1;
		}

	}
	printf("%d\n",max);
	for(i=map[max_idx];i<=map[max_idx+max-1];i++) printf("%c",original[i]);
	printf("\n");
	



	return 0;
}

/** AC!!! **/