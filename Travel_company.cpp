#include <bits/stdc++.h>
#define MAXX 1002
#define INF 100000000
#define pb push_back

using namespace std;        // Main idea: From statement:
                            // (I1+I2+...+Ik)/(E1+E2+...+Ek)>p => (I1-pE1)+(I2-pE2)+...> 0  =>(pE1-I1)+(pE2-I2)+...<0 (Negative cycle)
struct data{
    int u,v,w;
};

int dist[MAXX],N,R,P;
vector <data> edges;

void relax(int i,int j,int wt){
    dist[j]=min(dist[j],dist[i]+wt);
}

bool bellman(){
    int i,j;
    for(i=0;i<N-1;i++){
        for(j=0;j<edges.size();j++){
            relax(edges[j].u,edges[j].v,edges[j].w);
        }
    }
    for(j=0;j<edges.size();j++){
        if(dist[edges[j].v]>dist[edges[j].u]+edges[j].w) return 1;
    }

    return 0;
}

int main(){

    int i,j,kases,k;
    scanf("%d",&kases);

    for(i=1;i<=kases;i++){

        cin >> N >> R >> P;
        edges.clear();
        for(j=0;j<N;j++){
           dist[j]=INF;
        }
        dist[0]=0;

        for(j=0;j<R;j++){
            data temp;
            int inc,exp;

            cin>>temp.u>>temp.v>>inc>>exp;
            temp.w=P*exp-inc;
            edges.pb(temp);
        }

        if(bellman()) printf("Case %d: YES\n",i);
        else printf("Case %d: NO\n",i);

    }

    return 0;
}

/** AC!!! **/
