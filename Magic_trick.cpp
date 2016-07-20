#include <bits/stdc++.h>

using namespace std;
int seen[18];
int grid[5][5];

int main(){

    int i,j,r1,r2,ans=-1,kases,t;
    freopen("A-small-attempt0.in.","r",stdin);
    freopen("out.txt","w",stdout);

    cin>>kases;

    for(t=1;t<=kases;t++){

    memset(seen,0,sizeof(seen));
    cin>>r1;
    ans=-1;

    r1-=2;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++) cin>>grid[i][j];
    }
    for(i=0;i<4;i++) seen[grid[r1+1][i]]=1;

    cin>>r2;
    r2-=2;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++) cin>>grid[i][j];
    }
    bool ok=true;

    for(i=0;i<4;i++){
        ok=true;
        if(seen[grid[r2+1][i]]==1){
            if(ans==-1) ans=grid[r2+1][i];
            else{
                printf("Case #%d: Bad magician!\n",t);
                ok=false;
                break;
            }
        }
        if(!ok) break;
    }
    //for(i=0;i<17;i++) printf("%d\n",seen[i]);
    if(!ok) continue;
    if(ans==-1) printf("Case #%d: Volunteer cheated!\n",t);
    else printf("Case #%d: %d\n",t,ans);
    }

    return 0;
}

/** AC!!! **/
