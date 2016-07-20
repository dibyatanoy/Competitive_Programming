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
#include <utility>
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))
#define MAXX 220

using namespace std;

map <string, int> ppl;
vector <int> edges[MAXX];
int dp[MAXX][2],N,par[MAXX];
bool not_uniq[MAXX][2],vis[MAXX][2];
int emp;

void dfs(int u){

    int i,j;

    for(i=0;i<edges[u].size();i++){
        int v=edges[u][i];
        if(v!=par[u]){
            par[v]=u;
            dfs(v);
        }
    }
    return;
}

int call(int v,bool taken){

    if(vis[v][taken]) return dp[v][taken];

    int ret=0,u,i;
    not_uniq[v][taken]=0;

    if(taken){
        for(i=0;i<edges[v].size();i++){
            u=edges[v][i];
            if(u==par[v]) continue;
            //printf("%d %d ",v,u);

            ret+=call(u,0);

            not_uniq[v][taken] |= not_uniq[u][0];
        }
        ret++;
    }else{
        for(i=0;i<edges[v].size();i++){
            u=edges[v][i];
            if(u==par[v]) continue;

            //printf("%d %d ",v,u);


            int r1=call(u,0);
            int r2=call(u,1);

            if(r1>r2){
                ret+=r1;
                not_uniq[v][taken] |= not_uniq[u][0];
            }else if(r1<r2){
                ret+=r2;
                not_uniq[v][taken] |= not_uniq[u][1];
            }else{
                ret+=r1;
                not_uniq[v][taken]=1;
            }

        }
    }

    vis[v][taken]=1;
    return dp[v][taken]=ret;
}

int main(){

    int i,j,k;

    while(scanf("%d",&N) && N!=0){

        emp=0;
        CLR(vis);
        ppl.clear();

        for(i=0;i<MAXX;i++) edges[i].clear();

        string u,v;
        cin>>u;

        ppl[u]=emp++;

        for(i=0;i<N-1;i++){
            cin>>u>>v;

            int v1,v2;

            if(ppl.find(u)!=ppl.end()){
                v1=ppl[u];
            }else{
                v1=emp++;
                ppl[u]=v1;
            }
            if(ppl.find(v)!=ppl.end()){
                v2=ppl[v];
            }else{
                v2=emp++;
                ppl[v]=v2;
            }

            edges[v1].pb(v2);
            edges[v2].pb(v1);
        }


        par[0]=-1;
        dfs(0);

        call(0,0);

        call(0,1);

        //printf("%d %d\n",dp[0][0],dp[0][1]);


        if(dp[0][0]>dp[0][1]){
            cout<<dp[0][0]<<" " << ((not_uniq[0][0])? "No": "Yes" )<<endl;
        }else if(dp[0][0]<dp[0][1]){
            cout<<dp[0][1]<<" "<< ((not_uniq[0][1])? "No": "Yes") <<endl;
        }else{
            cout<<dp[0][0]<<" "<<"No"<<endl;
        }

    }



    return 0;
}


/** AC!!! **/
