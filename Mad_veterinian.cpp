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
#define MP make_pair
#define INF 1e8
#define MAXX 160

using namespace std;
struct triple{
    int arr[3];

    bool operator ==(const triple &p)const{
        return (arr[0]==p.arr[0] && arr[1]==p.arr[1] && arr[2]==p.arr[2]);
    }

    triple operator - (const triple &p)const{
        triple diff;
        diff.arr[0]=arr[0]-p.arr[0];
        diff.arr[1]=arr[1]-p.arr[1];
        diff.arr[2]=arr[2]-p.arr[2];

        return diff;
    }
};

bool vis[MAXX][MAXX][MAXX];
int dist[MAXX][MAXX][MAXX];
triple par[MAXX][MAXX][MAXX];
int trans[3][3];
char forw[]={'A','B','C'};
char rev[]={'a','b','c'};

int N, sol;

int bfs(triple src, triple dest){

    int i,j,k;
    queue<triple> Q;

    Q.push(src);dist[src.arr[0]][src.arr[1]][src.arr[2]]=0;

    vis[src.arr[0]][src.arr[1]][src.arr[2]]=1;
    triple null; null.arr[0]=-1;null.arr[1]=-1;null.arr[2]=-1;
    par[src.arr[0]][src.arr[1]][src.arr[2]]=null;

    while(!Q.empty()){
        triple u=Q.front();Q.pop();

        triple v;

        if(u==dest) return dist[u.arr[0]][u.arr[1]][u.arr[2]];

        for(i=0;i<3;i++){
            if(u.arr[i]>0){

                for(j=0;j<3;j++){
                    if(i!=j) v.arr[j]=u.arr[j]+trans[i][j];
                    else v.arr[j]=u.arr[j]-1+trans[i][j];

                }

                if(!vis[v.arr[0]][v.arr[1]][v.arr[2]] && v.arr[0]<150 && v.arr[1]<150 && v.arr[2]<150){
                    dist[v.arr[0]][v.arr[1]][v.arr[2]]=1+dist[u.arr[0]][u.arr[1]][u.arr[2]];
                    vis[v.arr[0]][v.arr[1]][v.arr[2]]=1;
                    par[v.arr[0]][v.arr[1]][v.arr[2]]=u;
                    //if(dist[v.arr[0]][v.arr[1]][v.arr[2]]<10000)
                    Q.push(v);
                }
            }

            if(u.arr[0]>=trans[i][0] && u.arr[1]>=trans[i][1] && u.arr[2]>=trans[i][2]){
                for(j=0;j<3;j++){
                    v.arr[j]=u.arr[j]-trans[i][j];

                }
                v.arr[i]+=1;

                if(!vis[v.arr[0]][v.arr[1]][v.arr[2]]  && v.arr[0]<150 && v.arr[1]<150 && v.arr[2]<150){
                    dist[v.arr[0]][v.arr[1]][v.arr[2]]=1+dist[u.arr[0]][u.arr[1]][u.arr[2]];
                    vis[v.arr[0]][v.arr[1]][v.arr[2]]=1;
                    par[v.arr[0]][v.arr[1]][v.arr[2]]=u;
                    //if(dist[v.arr[0]][v.arr[1]][v.arr[2]]<10000)
                    Q.push(v);
                }
            }
        }


    }
    return -1;
}

string path(triple dest){

    int i,j,k;
    string sol="";
    triple curr=dest;
    triple null; null.arr[0]=-1;null.arr[1]=-1;null.arr[2]=-1;
    triple prev=par[dest.arr[0]][dest.arr[1]][dest.arr[2]];

    triple diff=curr-prev;

    bool match;

    while(!(prev==null)){
        //cout<<"! ";
        for(i=0;i<3;i++){
            match=1;
            for(j=0;j<3;j++){
                if(i==j && diff.arr[j]!=trans[i][j]-1){match=0;break;}
                else if(i!=j && diff.arr[j]!=trans[i][j]){match=0;break;}
            }
            if(match){
                sol+=forw[i];
                break;
            }
        }
        if(match) {
            curr=prev;
            prev=par[curr.arr[0]][curr.arr[1]][curr.arr[2]];
            diff=curr-prev;
            continue;
        }

        for(i=0;i<3;i++){
            match=1;

            for(j=0;j<3;j++){
                if(i==j && diff.arr[j]!=(-trans[i][j]+1)){match=0;break;}
                else if(i!=j && diff.arr[j]!=-trans[i][j]){match=0;break;}
            }
            if(match){
                sol+=rev[i];
                break;
            }
        }
        curr=prev;
        prev=par[curr.arr[0]][curr.arr[1]][curr.arr[2]];
        diff=curr-prev;
    }
    //cout<<sol<<endl;
    reverse(all(sol));

    return sol;
}

int main(){

    int i,j,k,p,q;

    cin>>p;

    while(p--){

        cin>>k>>N;

        for(i=0;i<3;i++){
            for(j=0;j<3;j++) scanf("%d",&trans[i][j]);
        }
        cout<<k<<" "<<N<<endl;

        for(i=0;i<N;i++){

            triple src, dest;
            cin>>q>>src.arr[0]>>src.arr[1]>>src.arr[2]>>dest.arr[0]>>dest.arr[1]>>dest.arr[2];

            CLR(vis);
            int ans=bfs(src,dest);

            if(ans!=-1) cout<<q<<" "<<ans<<" "<<path(dest)<<endl;
            else cout<<q<<" NO SOLUTION"<<endl;
        }
    }

    return 0;
}
