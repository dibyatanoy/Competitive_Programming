#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#define pb push_back
#define MP make_pair
#define CLR(x) memset(x,0,sizeof(x));
#define all(v) v.begin(),v.end()
#define PII pair <int,int >
#define ll long long
#define MAXX 550
#define INF 100000000000000LL
#define Fr first
#define Sc second

using namespace std;
int N,M;
long long int dist[MAXX][MAXX];
int inEdges[MAXX][MAXX];
int ans[MAXX][MAXX];
bool is_edge[MAXX][MAXX];

void floyd(){
    int i,j,k;

    for(k=1;k<=N;k++){
        for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]) dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    return;
}

void solve(){
    int i,j,k,src;

    for(src=1;src<=N;src++){
        for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                if(is_edge[i][j]){
                    if(dist[src][i]+dist[i][j]==dist[src][j]) inEdges[src][j]++;
                    //if(dist[src][j]+dist[j][i]==dist[src][i]) inEdges[src][i]++;
                }
            }
        }
    }

    for(i=1;i<=N;i++){
        for(j=i+1;j<=N;j++){
            for(k=1;k<=N;k++){
                if(dist[i][k]+dist[k][j]==dist[i][j]) ans[i][j]+=inEdges[i][k];
            }
        }
    }
    return;
}

int main(){

    int i,j,k;

    scanf("%d %d",&N,&M);

    for(i=0;i<MAXX;i++){
        for(j=0;j<MAXX;j++) {
            if(i!=j) dist[i][j]=INF;
            else dist[i][j]=0;
        }
    }

    CLR(is_edge);
    for(i=0;i<M;i++){
        int x,y;
        long long int l;

        scanf("%d %d %I64d",&x,&y,&l);

        dist[x][y]=l;dist[y][x]=l;
        is_edge[x][y]=1;is_edge[y][x]=1;
    }


    CLR(ans);
    CLR(inEdges);

    floyd();
    solve();

    for(i=1;i<=N;i++){
        for(j=i+1;j<=N;j++){
            if(i==1 && j==2) printf("%d",ans[i][j]);
            else printf(" %d",ans[i][j]);
        }
    }
    printf("\n");

    /*for(i=1;i<=N;i++){
        for(j=i+1;j<=N;j++){
            printf("%d ",inEdges[i][j]);
        }
    }
    printf("\n");*/

    return 0;
}
