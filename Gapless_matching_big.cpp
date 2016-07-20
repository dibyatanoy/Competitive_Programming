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
#define INF 1e8
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define all(v) v.begin(),v.end()
#define MAXX 52000
#define offset 52003
#define PII pair <int,int >
#define ll long long
#define MP make_pair

using namespace std;

vector <int> pos[2][MAXX];
int p[150];
char a[MAXX],b[MAXX];
int sat,dis;
int points[2*MAXX];

int main(){


    int i,j,k;

    scanf("%d %d",&sat,&dis);

    scanf("%s",a);
    scanf("%s",b);
    int l1=strlen(a);
    int l2=strlen(b);
    int pt1,pt2;

    int st=0;

    for(i='a';i<='z';i++){
        p[i]=st++;
    }
    for(i='A';i<='Z';i++){
        p[i]=st++;
    }

    for(i=0;i<l1;i++){
        edges[0][p[a[i]]].pb(i);
    }
    for(i=0;i<l2;i++){
        edges[1][p[b[i]]].pb(i);
    }

    pt1=0;
    pt2=0;


        for(j=0;j<52;j++){
            for(i=0;i<edges[0][j].size();j++){
                for(k=0;k<edges[1][j].size();k++){
                    points[edges[1][j][k]-edges[1][j][i]+offset]+=1;
                }
            }
        }

        for(i=0;i<2*MAXX;i++){
            if(i>=offset){
                mx=max(mx,min(l1,l2+i-offset));
            }
        }


    return 0;
}
