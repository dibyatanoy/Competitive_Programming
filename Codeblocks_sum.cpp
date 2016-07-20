#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

int main(){

    vector <int> a;
    int tmp;
    string str,t;

    a.clear();
    getline(cin,str);
    stringstream kin(str);

    while(kin>>t){
        cout << "reached" <<endl ;
        scanf(t.c_str(),"%d",&tmp);
        cout << tmp <<endl;
        a.push_back(tmp);
    }
    //cout << "reached" <<endl ;
    int i;
    for(i=0;i<a.size();i++) printf("%d ",a[i]);
    printf("\n");

    return 0;
}
