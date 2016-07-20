#include <bits/stdc++.h>
#define eps 1e-9

using namespace std;
char grid[52][52];

int main(){

    freopen("C-small-attempt4.in.","r",stdin);
    freopen("out2.txt","w",stdout);

    int M,R,C,i,j,k,t;
    cin>>t;

    for(i=1;i<=t;i++){
        bool ok=true;

        cin>>R>>C>>M;

        for(j=0;j<R;j++){
            for(k=0;k<C;k++) grid[j][k]='?';
        }

        printf("Case #%d:\n",i);
        if(R>1 && C>1 && R*C-M<4) {printf("Impossible\n");ok=false;}
        else if(R==1){
            if(R*C-M<2) {printf("Impossible\n");ok=0;}
            else{
                grid[R-1][C-1]='c';
                grid[R-2][C-1]='.';
            }
        }else if(C==1){
            if(R*C-M<2) {printf("Impossible\n");ok=0;}
            else{
                grid[R-1][C-1]='c';
                grid[R-1][C-2]='.';
            }
        }
        else{

            grid[R-1][C-1]='c';
            grid[R-2][C-1]='.';
            grid[R-1][C-2]='.';
            grid[R-2][C-2]='.';
        }

        if(ok){
            k=0;
            int done=0;
            for(j=0;done<M;j++){
                for(k=0;k<C && done<M;k++){
                    if(grid[j][k]=='?') {grid[j][k]='*';done++;}
                }
            }
            for(j=0;j<R;j++){
                for(k=0;k<C;k++){
                    if(grid[j][k]=='?') grid[j][k]='.';
                }
            }
            for(j=0;j<R;j++){
                printf("%c",grid[j][0]);
                for(k=1;k<C;k++){
                    printf("%c",grid[j][k]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
