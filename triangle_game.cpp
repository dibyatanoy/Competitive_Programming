#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#define INF 1e8
#define MAXX 300
#define pb push_back
#define MP make_pair
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a));
#define PII pair<int,int >

using namespace std;

struct data{
    int x,y;
};

data tri[MAXX],N;

int main(){

    int i,j,k,ans;

    cin>>N;

    for(i=0;i<N;i++){
        cin>>tri[i].x,tri[i].y;
    }

    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            for(k=0;k<N;k++){
                if(i!=k && j!=k){
                    if((tri[j].y-tri[i].y)*(tri[k].y-tri[j].y)==-())
                }
            }
        }
    }

    return 0;
}
