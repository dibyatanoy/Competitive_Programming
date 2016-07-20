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
#define ll long long
#define MAXX 50010
#define INF 10000000000000000LL
#define Fr first
#define L 0
#define R 1
#define Sc second

using namespace std;
vector <int> edges[2*MAXX];
int in_edge[2*MAXX],in_edge2[2*MAXX],N1,N2,D;
vector <int> zero1,zero2;

int solve(){
    int i,j,k,u,ans=1,a2=1;

    i=0;j=0;k=0;

    while(i<N1+N2){
        while(j<zero1.size()){
            for(u=0;u<edges[zero1[j]].size();u++){
                int v=edges[zero1[j]][u];
                in_edge[v]--;
                if(in_edge[v]==0){
                    if(v<=N1) zero1.pb(v);
                    else zero2.pb(v);
                }
            }
            j++;
            i++;
        }
        //printf("i= %d, j=%d, k=%d\n",i,j,k);
        if(k<zero2.size()) ans++;

        while(k<zero2.size()){
            for(u=0;u<edges[zero2[k]].size();u++){
                int v=edges[zero2[k]][u];
                in_edge[v]--;
                if(in_edge[v]==0){
                    if(v<=N1) zero1.pb(v);
                    else zero2.pb(v);
                }
            }
            k++;
            i++;
        }
        //printf("i= %d, j=%d, k=%d\n",i,j,k);
        if(j<zero1.size()) ans++;
    }

    zero1.clear();
    zero2.clear();
    for(i=1;i<=N1+N2;i++){
            if(in_edge2[i]==0){
                if(i<=N1) zero1.pb(i);
                else zero2.pb(i);
            }
    }

    i=0;j=0;k=0;

    while(i<N1+N2){
        while(j<zero2.size()){
            for(u=0;u<edges[zero2[j]].size();u++){
                int v=edges[zero2[j]][u];
                in_edge2[v]--;
                if(in_edge2[v]==0){
                    if(v<=N1) zero1.pb(v);
                    else zero2.pb(v);
                }
            }
            j++;
            i++;
        }
        //printf("i= %d, j=%d, k=%d\n",i,j,k);
        if(k<zero1.size()) a2++;

        while(k<zero1.size()){
            for(u=0;u<edges[zero1[k]].size();u++){
                int v=edges[zero1[k]][u];
                in_edge2[v]--;
                if(in_edge2[v]==0){
                    if(v<=N1) zero1.pb(v);
                    else zero2.pb(v);
                }
            }
            k++;
            i++;
        }
        //printf("i= %d, j=%d, k=%d\n",i,j,k);
        if(j<zero2.size()) a2++;
    }
    return min(ans+1,a2+1);
}

int main(){

    int kases,i,j,k;



    while(scanf("%d %d %d",&N1,&N2,&D) && !(N1==0 && N2==0 && D==0)){

        CLR(in_edge);
        CLR(in_edge2);
        zero1.clear();
        zero2.clear();
        for(i=0;i<=N1+N2;i++) edges[i].clear();

        for(i=0;i<D;i++){
            int u,v;
            scanf("%d%d",&u,&v);

            edges[v].pb(u);
            in_edge[u]++;
            in_edge2[u]++;
        }

        for(i=1;i<=N1+N2;i++){
            if(in_edge[i]==0){
                if(i<=N1) zero1.pb(i);
                else zero2.pb(i);
            }
        }
        printf("%d\n",solve());

    }

    return 0;
}

/** AC!!! **/
