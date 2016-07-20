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
#define all(v) v.begin(),v.end()
#define INF 1e8
#define MAXX 1005

using namespace std;
vector <int> edges[MAXX];
bool vis[MAXX],mult[MAXX];
int order[MAXX],mx[MAXX];
int M,P;
vector<int> vert;

void topsort(int u){
    int i,j;

    for(i=0;i<edges[u].size();i++){
        int v=edges[u][i];

        if(!vis[v]) {vis[v]=1;topsort(v);}
    }
    vert.pb(u);
}

int main(){

    int i,j,k,p;

    scanf("%d",&p);

    while(p--){
        scanf("%d %d %d",&k,&M,&P);

        for(i=0;i<MAXX;i++) edges[i].clear();
        CLR(vis);CLR(order);CLR(mult);CLR(mx);
        vert.clear();

        while(P--){
            int a,b;
            scanf("%d %d",&a,&b);
            edges[a].pb(b);
        }

        for(i=1;i<=M;i++){
            if(!vis[i]){
                vis[i]=1;
                topsort(i);
            }
        }
        reverse(all(vert));

        memset(order,0,sizeof(order));

        //for(i=0;i<M;i++) cout<<vert[i]<<" ";
        //cout<<endl;

        for(i=0;i<M;i++){

            if(order[vert[i]]==0) {order[vert[i]]=1;mx[vert[i]]=1;}

            for(j=0;j<edges[vert[i]].size();j++){
                int v=edges[vert[i]][j];


                if(order[vert[i]]>mx[v]){
                    mx[v]=order[vert[i]];
                    order[v]=order[vert[i]];mult[v]=0;
                }else if(order[vert[i]]==mx[v]){
                    if(!mult[v]) order[v]++;
                    mult[v]=1;

                }
            }
        }


        /*for(i=0;i<M;i++){
            cout<<vert[i]<<" "<<order[i]<<endl;
        }*/

        printf("%d %d\n",k,order[M]);
    }

    return 0;
}
