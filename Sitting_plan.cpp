#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int dir_x[]={-1,-1,-1,0,0,1,1,1};
int dir_y[]={-1,0,1,-1,1,-1,0,1};


int main(){

    int r,s,shakes=0,i,j,k,mx=0,m,x,y;
    char grid[54][54];

    cin>>r>>s;

    for(i=0;i<r;i++) scanf("%s",grid[i]);

    for(i=0;i<r;i++){
        for(j=0;j<s;j++){
            if(grid[i][j]=='o'){
                for( m=0;m<8;m++){
                     x=j+dir_x[m];
                     y=i+dir_y[m];
                    if(x>=0 && x<s && y>=0 && y<r && grid[y][x]=='o') shakes++;
                }
            }
        }
    }
    shakes/=2;

    for(i=0;i<r;i++){
        for(j=0;j<s;j++){
            if(grid[i][j]=='.'){
                int temp=0;
                for( m=0;m<8;m++){
                     x=j+dir_x[m];
                     y=i+dir_y[m];
                    if(x>=0 && x<=s && y>=0 && y<=r && grid[y][x]=='o') temp++;
                }
                mx=max(temp,mx);
            }
        }

    }

    cout << shakes+mx<<endl;

    return 0;
}

/** AC!!! **/
