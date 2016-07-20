#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#define INF 100000000
#define pb push_back
#define MP make_pair
#define all(v) v.begin(),v.end()
#define Fr first
#define Sc second
#define CLR(x) memset(x,0,sizeof(x))
#define MAXX 3100
using namespace std;
int R,S;
char grid[MAXX][MAXX],ans[MAXX][MAXX];

int main(){

    int i,j,k,fall;

    fall=10000;
    scanf("%d %d",&R,&S);

    for(i=0;i<R;i++) scanf("%s",grid[i]);

    for(j=0;j<S;j++){
        int g=0;
        for(i=R-1;i>=0;i--){
            if(grid[i][j]=='#') g=i;
            else if(grid[i][j]=='X'){
                fall=min(fall,g-i-1);
                break;
            }
        }
    }

    for(i=R-1;i>=0;i--){
        for(j=0;j<S;j++){
            if(grid[i][j]=='X') {ans[i+fall][j]='X';ans[i][j]='.';}
            else ans[i][j]=grid[i][j];
        }
    }

    for(i=0;i<R;i++){
        printf("%s\n",ans[i]);
    }


    return 0;
}
