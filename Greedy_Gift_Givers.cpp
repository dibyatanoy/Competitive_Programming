/*
ID: dibyapo2
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

string names[11];
int amounts[11],np;

int find(string name){
	bool fnd=false;
	for(int i=0;i<np;i++){
		fnd=false;
		//for(int j=0;j<length(name);j++){
			//if(names[i][j]!=name[j]){
			//	fnd=true;
				//eak;
			//}
		//}
		if(name.compare(names[i])==0) return i;

		//if(fnd==false) return i;

	}
	return 0;
}

int main(){

	memset(amounts,0,sizeof(amounts));
	int i,j,idx;
	string giver="",receiver="";
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);

	cin >> np;
	

	for(i=0;i<np;i++){
		cin >> names[i];
	}

	for(i=0;i<np;i++){
		cin >> giver;
		int amount,res=0;
		cin >> amount >> j;
		
		for(int k=0;k<j;k++){
			res=amount/j;
			cin >> receiver;
			idx=find(receiver);
			amounts[idx]+=res;
		}
		
		idx=find(giver);
		amounts[idx]-=res*j;
	
	}


	for(i=0;i<np;i++){
		cout << names[i] << " " << amounts[i] << endl;
		//printf("%s",names[i]);

	}

	return 0;
}

/** AC!!! **/