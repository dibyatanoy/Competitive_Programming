#include <bits/stdc++.h>
#include "tile.h"
#define MAXX 22000
#define PII pair<int,int >
#define Fr first
#define Sc second
#define MP make_pair

using namespace std;
int temp[MAXX][6],sz;
int cnt;

void solve(int from,PII x,PII y,PII block){

    //printf("%d Square from (%d, %d) to (%d, %d), block at (%d, %d)\n",from,x.Fr,x.Sc,y.Fr,y.Sc,block.Fr,block.Sc);

    if(x.Fr==y.Fr && x.Sc==y.Sc) return;

    int r=y.Fr-x.Fr+1;
    int c=y.Sc-x.Sc+1;

    int nFr=x.Fr+r/2-1;
    int nSc=x.Sc+c/2-1;



    if(block.Fr<=nFr && block.Sc<=nSc){
        temp[cnt][0]=nFr;temp[cnt][1]=nSc+1;
        temp[cnt][2]=nFr+1;temp[cnt][3]=nSc+1;
        temp[cnt][4]=nFr+1;temp[cnt][5]=nSc;

        cnt++;

        solve(1,x,MP(nFr,nSc),block);solve(2,MP(nFr+1,nSc+1),y,MP(nFr+1,nSc+1));

        solve(3,MP(x.Fr,nSc+1),MP(nFr,y.Sc),MP(nFr,nSc+1));solve(4,MP(nFr+1,x.Sc),MP(y.Fr,nSc),MP(nFr+1,nSc));

    }else if(block.Fr>nFr && block.Sc>nSc){
        temp[cnt][0]=nFr;temp[cnt][1]=nSc+1;
        temp[cnt][2]=nFr;temp[cnt][3]=nSc;
        temp[cnt][4]=nFr+1;temp[cnt][5]=nSc;

        cnt++;

        solve(5,MP(nFr+1,nSc+1),y,block);solve(6,x,MP(nFr,nSc),MP(nFr,nSc));

        solve(7,MP(x.Fr,nSc+1),MP(nFr,y.Sc),MP(nFr,nSc+1)); solve(8,MP(nFr+1,x.Sc),MP(y.Fr,nSc),MP(nFr+1,nSc+1));

    }else if(block.Fr>nFr && block.Sc<=nSc){
        temp[cnt][0]=nFr;temp[cnt][1]=nSc+1;
        temp[cnt][2]=nFr;temp[cnt][3]=nSc;
        temp[cnt][4]=nFr+1;temp[cnt][5]=nSc+1;

        cnt++;

        solve(9,x,MP(nFr,nSc),MP(nFr,nSc));solve(10,MP(nFr+1,nSc+1),y,MP(nFr+1,nSc+1));

        solve(11,MP(x.Fr,nSc+1),MP(nFr,y.Sc),MP(nFr,nSc+1)); solve(12,MP(nFr+1,x.Sc),MP(y.Fr,nSc),block);

    }else{
        temp[cnt][0]=nFr+1;temp[cnt][1]=nSc;
        temp[cnt][2]=nFr;temp[cnt][3]=nSc;
        temp[cnt][4]=nFr+1;temp[cnt][5]=nSc+1;

        cnt++;

        solve(13,x,MP(nFr,nSc),MP(nFr,nSc));solve(14,MP(nFr+1,nSc+1),y,MP(nFr+1,nSc+1));

        solve(15,MP(x.Fr,nSc+1),MP(nFr,y.Sc),block); solve(16,MP(nFr+1,x.Sc),MP(y.Fr,nSc),MP(nFr+1,nSc));
    }

    return;
}

void placeTile(int n,int x,int y,int tile[][6]){
    int i,j;

    sz=(1<<n);

    cnt=0;

    solve(-1,MP(0,0),MP(sz-1,sz-1),MP(x,y));

    for(i=0;i<cnt;i++){
        for(j=0;j<6;j++) tile[i][j]=temp[i][j];
    }

    return;
}


/** AC!!! **/
