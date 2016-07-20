#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

int main(){

    set<int> myset;
    vector<int> myv(10);

    for(int i=0;i<5;i++){
        scanf("%d",&myv[i]);
    }

    myv.resize(5);
    sort(myv.begin(),myv.end());

    myv=unique(myv.begin(),myv.end())-myv.begin();

    for(int i=0;i<myv.size();i++) cout<<myv[i]<<endl;

    for(int i=0;i<5;i++){
        int x;
        cin>>x;
        myset.insert(x);
    }

    set<int>::const_iterator it;

    for(it=myset.begin();it!=myset.end();++it){
        cout<<*it<<endl;
    }

    map <string, int> mymap;

    for(int i=0;i<5;i++){
        int val;
        string key;
        cin>>key>>val;

        mymap[key]=val;
    }

    for(int i=0;i<5;i++){
        string fnd;
        cin>>fnd;

        if(mymap.find(fnd)!=mymap.end()) cout<<mymap[fnd]<<endl;
        else cout<<"Does not exist"<<endl;

    }

    return 0;
}
