#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#define INF 100000000
#define MAXX 1000
#define eps 1e-9
#define PI 2*arccos(0.0)
#define all(v) v.begin(), v.end()
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
string s;

int main(){

    int i,j,k;
    int t;

    freopen("Documents/C++_programs/io/A-large (1).in","r",stdin);
    freopen("Documents/C++_programs/io/The_last_word.txt","w",stdout);

    scanf("%d",&t);

    for(i = 0; i<t; i++){

        cin >> s;
        string tmp = "";

        tmp += s[0];

        int l = s.size();
        for(j = 1; j < l; j++){

            if(s[j] >= tmp[0])

                tmp.insert(tmp.begin(), s[j]);
            else

                tmp += s[j];
        }

        cout << "Case #" << i+1 << ": " << tmp <<endl;
    }

    return 0;
}
