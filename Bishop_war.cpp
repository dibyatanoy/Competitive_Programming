/* HackerRank World Cup Semi-finals */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define MAXX 50
#define off 15
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))

using namespace std;
int N,M;
bool rt[MAXX], lt[MAXX];
char board[20][20];

long long int solve(int row){
    if(row==(N)) {return 1;}

    long long int ways=0LL,i,j;
    int c;
    vector <int> changes_l,changes_r;

    int rt_now;
    int lt_now;

    for(c=0;c<M;c++){

        rt_now= row-c+off;
        lt_now=row+c+off;

        if(board[row][c]== '*'){

            if(lt[lt_now]) changes_l.pb(lt_now);
            if(rt[rt_now]) changes_r.pb(rt_now);

            lt[lt_now]=0;rt[rt_now]=0;
        }
    }

    for(c=0;c<M;c++){

        rt_now= row-c+off;
        lt_now=row+c+off;

        if(board[row][c]!= '*' && !lt[lt_now] && !rt[rt_now]){
            lt[lt_now]=1;
            rt[rt_now]=1;

            //printf("row %d: bishop at %d\n", row,c);
            ways+=solve(row+1);

            lt[lt_now]=0;rt[rt_now]=0;

        }
    }

    for(i=0;i<changes_l.size();i++) lt[changes_l[i]]=1;
    for(i=0;i<changes_r.size();i++) rt[changes_r[i]]=1;

    return ways;
}

int main(){

    int i,j,k;

    scanf("%d %d",&N,&M);

    for(i=0;i<N;i++){
        scanf("%s",board[i]);
    }

    CLR(rt);CLR(lt);

    printf("%lld\n",solve(0));

    return 0;
}
