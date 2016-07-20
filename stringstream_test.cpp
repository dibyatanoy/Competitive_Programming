#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int>a;
    int tmp;
    string str,t;           //successful !

    getline(cin,str);

    stringstream kin(str);
    while(kin >> t){
        sscanf(t.c_str(),"%d",&tmp);
        a.push_back(tmp);
    }

    for(int i=0;i<a.size();i++) cout << a[i] <<endl;

    return 0;
}
