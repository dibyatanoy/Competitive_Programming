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
#define all(v) (v.begin(),v.end())
#define INF 1e8
#define MAXX 105

using namespace std;
map <string, string > dist;

string swap_st(string x, int i,int j){

    string tmp=x;
    tmp[i]=x[j];tmp[j]=x[i];
    return tmp;
}

void bfs(string root){

    dist[root]="";
    queue<string> Q;

    Q.push(root);

    while(!Q.empty()){
        string u=Q.front();
        Q.pop();


            string v;
            int hole_pos=u.find('*');

            //cout<<hole_pos<<" " <<u<<endl;

            if(hole_pos==6){

                v=swap_st(u,1,6);
                //cout<<u<<" "<<v<<" ";

                if(dist.find(v)==dist.end()){
                    dist[v]=dist[u]+u[1];
                    //cout<<dist[v]<<" "<<dist[u]<<endl;
                    Q.push(v);
                    //cout<<"pushing "<<v<<endl;
                }

                v=swap_st(u,4,6);

                if(dist.find(v)==dist.end()){
                    dist[v]=dist[u]+u[4];
                    Q.push(v);
                    //cout<<"pushing "<<v<<endl;
                }
            }else{
                if(hole_pos==1 || hole_pos==4){
                    v=swap_st(u,hole_pos,6);



                    if(dist.find(v)==dist.end()){
                        dist[v]=dist[u]+u[6];
                        Q.push(v);
                        //cout<<"pushing "<<v<<endl;
                    }
                }

                v=swap_st(u,hole_pos,(hole_pos+1)%6);


                if(dist.find(v)==dist.end()){
                    dist[v]=dist[u]+u[(hole_pos+1)%6];
                    Q.push(v);
                    //cout<<"pushing "<<v<<endl;
                }

                int prev=(hole_pos==0)? 5:(hole_pos-1);

                v=swap_st(u,hole_pos,prev);


                if(dist.find(v)==dist.end()){
                    dist[v]=dist[u]+u[prev];
                    //if(v=="FACDE*B") cout<<"!"<<dist[v]<<endl;
                    Q.push(v);
                    //cout<<"pushing "<<v<<endl;
                }
            }

    }
}

int main(){

    int i,j,k,p;

    dist.clear();

    bfs("ABCDEF*");
    //cout<<dist["FACDE*B"]<<endl;

    scanf("%d",&p);

    while(p--){
        string q;
        cin>>i>>q;

        cin.clear();fflush(stdin);

        q+='*';


        if(dist.find(q)==dist.end()){
            printf("%d NO SOLUTION\n",i);
        }else {
            string sol=dist[q];
            reverse(sol.begin(),sol.end());
            cout<< i << " " << dist[q].length() << " " << sol <<endl;
            }
    }

    return 0;
}
