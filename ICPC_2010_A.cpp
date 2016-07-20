#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
char toss[50];

int times[10000];

int main(){

    int i,j,kases;

    scanf("%d",&kases);

    for(i=1;i<=kases;i++){

        int x;
            scanf("%d",&x);
            // y;
            //scanf("%c",&y);
        scanf("%s",toss);
        //printf("%s",toss);

        memset(times,0,sizeof(times));

        for (j=2;j<40;j++){

            int tmp=0;
            tmp+= (toss[j-2]=='T')? 0:1;
            tmp+= (toss[j-1]=='T')? 0:2;
            tmp+= (toss[j]=='T')? 0:4;

            times[tmp]++;
        }

        printf("%d",i);
        for(j=0;j<8;j++){
            printf(" %d",times[j]);
        }

        printf("\n");
    }

    return 0;
}
