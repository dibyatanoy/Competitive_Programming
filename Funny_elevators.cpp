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
#define INF 100000000
#define eps 1e-9
#define CLR(x) memset(x,0,sizeof(x))
#define pb push_back
#define all(x) x.begin(), x.end()
#define Fr first
#define Sc second
#define MAXX 1200
#define pi 2*acos(0.0)

using namespace std;

vector<int> edges[MAXX];
bool vis[MAXX];
int F,E,A,B;

bool bfs(){

    int i;
    queue<int> Q;

    vis[A]=1;Q.push(A);

    while(!Q.empty()){

        int u=Q.front();Q.pop();

        if(u==B) return 1;

        for(i=0;i<edges[u].size();i++){

            int v=edges[u][i];

            if(!vis[v]){
                Q.push(v);

                //cout<<"pushing "<<v<<endl;
                vis[v]=1;
            }
        }
    }

    return 0;
}

int main(){

    int i,j,k;

    cin>>F>>E>>A>>B;

    CLR(vis);

    for(i=0;i<E;i++){

        int x,y;
        cin>>x>>y;





        for(j=y,k=y+x;k<F;j+=x,k+=x){

            edges[j].pb(k);
            edges[k].pb(j);
        }

    }

    cout<<bfs()<<endl;

    return 0;
}
