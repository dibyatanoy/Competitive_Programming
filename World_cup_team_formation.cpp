#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int pts[15];

int main(){

    int i,j;

    for(i=0;i<10;i++) scanf("%d",&pts[i]);

    sort(pts,pts+10);
    reverse(pts,pts+10);

    printf("%d\n",max(pts[0]+pts[2]+pts[4],pts[1]+pts[3]+pts[5]));

    return 0;
}
