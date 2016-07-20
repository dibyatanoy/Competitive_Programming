/*
ID: dibyapo2
LANG: C++
TASK: milk3
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define maxim(a,b) (a>b)? a:b
#define minim(a,b) (a<b)? a:b
 
using namespace std;
 
bool taken[23][23][23];
int A,B,C;
vector <int> results;
 
void dfs(int a, int b,int c){
    if(taken[a][b][c]) return;
        if(a==0){
                results.push_back(c);
                taken[a][b][c]=1;
				if(b>0){
                        //taken[minim(A,a+b)][maxim(0,b-A)][c];
                        //taken[a][maxim(0,b-C)][minim(C,c+b)];
                        dfs(minim(A,a+b),maxim(0,b-(A-a)),c);
                        dfs(a,maxim(0,b-(C-c)),minim(C,c+b));
                }
                if(c>0){
                        //taken[minim(A,a+c)][b][maxim(0,c-A)];
                        //taken[a][minim(B,b+c)][maxim(0,c-B)];
                        dfs(minim(A,a+c),b,maxim(0,c-(A-a)));
                        dfs(a,minim(B,b+c),maxim(0,c-(B-b)));
                }
        }else{
                taken[a][b][c]=1;
                dfs(maxim(0,a-(B-b)),minim(B,b+a),c);
                dfs(maxim(0,a-(C-c)),b,minim(C,c+a));
 
                if(b>0){
                        //taken[minim(A,a+b)][maxim(0,b-A)][c];
                        //taken[a][maxim(0,b-C)][minim(C,c+b)];
                        dfs(minim(A,a+b),maxim(0,b-(A-a)),c);
                        dfs(a,maxim(0,b-(C-c)),minim(C,c+b));
                }
                if(c>0){
                        //taken[minim(A,a+c)][b][maxim(0,c-A)];
                        //taken[a][minim(B,b+c)][maxim(0,c-B)];
                        dfs(minim(A,a+c),b,maxim(0,c-(A-a)));
                        dfs(a,minim(B,b+c),maxim(0,c-(B-b)));
                }
        }
        return;
}
 
int main(){
    
        freopen("milk3.in","r",stdin);
        freopen("milk3.out","w",stdout);
 
        memset(taken,0,sizeof(taken));
        scanf("%d %d %d",&A,&B,&C);
 
        int i,j;
        //taken[0][0][C]=1;
        //results.push_back(C);
        if(C<A) {dfs(C,0,0);}//taken[C][0][0]=1;}
        else {dfs(A,0,C-A);}//taken[A][0][C-A]=1;}
        if(C<B) {dfs(0,C,0);}//taken[0][C][0]=1;}
        else {dfs(0,B,C-B);}//taken[0][B][C-B]=1;}
 
        sort(results.begin(),results.end());
 
        printf("%d",results[0]);
        for(i=1;i<results.size();i++) printf(" %d",results[i]);
        printf("\n");
 
        return 0;
}

/** AC!!! **/