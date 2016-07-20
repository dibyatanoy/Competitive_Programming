#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#define INF 1000000000
#define eps 1e-9
#define CLR(x) memset(x,0,sizeof(x))
#define pb push_back
#define all(x) x.begin(), x.end()
#define Fr first
#define Sc second
#define MAXX 150000
#define pi 2*acos(0.0)

using namespace std;

vector <int> edges[MAXX];
vector <int> wt[MAXX];
bool vis[MAXX];
int stamp[MAXX],cnt;
double probs;
int N;

double traverse(int src){

    vis[src]=1;
    stamp[src]=cnt;

    int i,j;
    double tot;

    i=edges[src][0];

    while(!vis[i]){
        vis[i]=1;
        stamp[i]=cnt;
        i=edges[i][0];
    }

    if(stamp[i]!=cnt) return 0.0;

    tot=((double)wt[i][0])/(100.00);


    int trgt=i;

    i=edges[i][0];

    while(i!=trgt){

        tot*=((double)wt[i][0])/(100.00);
        i=edges[i][0];
    }
    probs+=tot;
    return tot;

}

int main(){

    int i,j,k;

    scanf("%d",&N);

    CLR(vis);

    for(i=1;i<=N;i++){

        int u,v,p;

        scanf("%d %d",&v,&p);

        edges[i].pb(v);
        wt[i].pb(p);
    }

    probs=0.0;
    cnt=0;

    for(i=1;i<=N;i++){
        cnt++;
        if(!vis[i]) traverse(i);
    }

    printf("%.2f\n",roundf(probs*100)/(100));


    return 0;
}
