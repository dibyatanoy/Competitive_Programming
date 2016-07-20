#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#define CLR(x) memset((x),0,sizeof((x)))
#define all(v) v.begin(),v.end()
#define pb push_back
#define MP make_pair
#define PII pair <int,int >
#define MAXX 301000
#define INF 1e16
#define ll long long
#define MOD 1000000007
#define Fr first
#define Sc second

using namespace std;

map <string, int> words;
vector <int> edges[MAXX];
long long int min_r[MAXX],min_l[MAXX],l[MAXX];
int N,M;
int par[MAXX];
bool vis[MAXX];
int nodes=0;

string essay[MAXX];

void dfs(int u){

    vis[u]=1;
    min_l[u]=l[u];

    int i;

    for(i=0;i<edges[u].size();i++){
        int v=edges[u][i];

        if(!vis[v]){
            par[v]=u;
            dfs(v);
        }
            if(min_r[v]<min_r[u]){
                min_r[u]=min_r[v];
                min_l[u]=min_l[v];
            }else if(min_r[v]==min_r[u] && min_l[u]>min_l[v]){
                min_l[u]=min_l[v];
            }

    }
    return;
}

int main(){

    int i,j,k;

    scanf("%d",&M);

    for(i=0;i<M;i++) cin>>essay[i];

    scanf("%d",&N);
    nodes=1;

    for(i=0;i<N;i++){

        string u1,u2;
        long long int r1=0,r2=0;
        int v1,v2;

        cin>> u1 >>u2;

        for(j=0;j<u1.size();j++) u1[j]=tolower(u1[j]);
        for(j=0;j<u2.size();j++) u2[j]=tolower(u2[j]);

        if(words.find(u1)!=words.end()){
            v1=words[u1];
        }else{

            v1=nodes;
            words[u1]=nodes++;

            for(j=0;j<u1.size();j++){
                if(u1[j]=='r') r1++;
            }
            min_r[v1]=r1;
            l[v1]=(ll)u1.size();
        }

        if(words.find(u2)!=words.end()){
            v2=words[u2];
        }else{

            v2=nodes;
            words[u2]=nodes++;

            for(j=0;j<u2.size();j++){
                if(u2[j]=='r') r2++;
            }
            min_r[v2]=r2;
            l[v2]=(ll)u2.size();
        }

        edges[v1].pb(v2);
        //cout<<v1<<" "<<v2<<endl;
    }

    CLR(vis);

    for(i=1;i<nodes;i++){
        if(!vis[i]) dfs(i);
    }

    long long int r_ans=0,l_ans=0;

    for(i=0;i<M;i++){
        for(j=0;j<essay[i].size();j++) essay[i][j]=tolower(essay[i][j]);

        if(words.find(essay[i])!=words.end()){
            r_ans+=min_r[words[essay[i]]];
            l_ans+=min_l[words[essay[i]]];
        }else{
            l_ans+=essay[i].size();
            for(j=0;j<essay[i].size();j++){
                if(essay[i][j]=='r') r_ans++;
            }
        }
    }

    //for(i=1;i<=6;i++) printf("%d %d\n",min_r[i],min_l[i]);
    printf("%I64d %I64d\n",r_ans,l_ans);

    return 0;
}



