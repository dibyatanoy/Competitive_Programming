#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#define INF 100000000
#define pb push_back
#define MP make_pair
#define all(v) v.begin(),v.end()
#define Fr first
#define Sc second
#define CLR(x) memset(x,0,sizeof(x))

using namespace std;
int kases,O,V,N,t,plyrs;
bool pos[24][3],taken[24];
char lines[5];
int forms[15][3];

bool solve(int a,int b,int c,int t){

    int i,j,k;

    if(a<forms[t][0]){
        for(i=0;i<plyrs;i++){
            if(!taken[i] && pos[i][0]){
                taken[i]=1;

                bool fnd=solve(a+1,b,c,t);
                if(fnd) return true;
                else{
                    taken[i]=0;
                }
            }
        }
        return false;
    }else if(b<forms[t][1]){

        for(i=0;i<plyrs;i++){
            if(!taken[i] && pos[i][1]){
                taken[i]=1;

                bool fnd=solve(a,b+1,c,t);
                if(fnd) return true;
                else{
                    taken[i]=0;
                }
            }
        }
        return false;
    }else if(c<forms[t][2]){

        for(i=0;i<plyrs;i++){
            if(!taken[i] && pos[i][2]){
                taken[i]=1;

                bool fnd=solve(a,b,c+1,t);
                if(fnd) return true;
                else{
                    taken[i]=0;
                }
            }
        }
        return false;
    }else return true;
}

int main(){

    int i,j,k;

    scanf("%d",&kases);

    for(i=0;i<kases;i++){
        CLR(pos);CLR(taken);

        scanf("%d-%d-%d",&forms[i][0],&forms[i][1],&forms[i][2]);

    }
    scanf("%d",&plyrs);

    for(i=0;i<plyrs;i++){
        scanf("%s",lines);
        for(j=0;j<strlen(lines);j++){
            if(lines[j]=='O') pos[i][0]=1;
            if(lines[j]=='V') pos[i][1]=1;
            if(lines[j]=='N') pos[i][2]=1;
        }
    }

    for(i=0;i<kases;i++){
        CLR(taken);
        bool ans=solve(0,0,0,i);

        if(ans) printf("DA\n");
        else printf("NE\n");
    }


    return 0;
}
