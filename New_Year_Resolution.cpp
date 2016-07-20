#include <bits/stdc++.h>
#define MAXX 22

using namespace std;
int gc,gp,gf,N;
int c[MAXX],p[MAXX],f[MAXX];

bool solve(int pos,int x,int y,int z){

    if(x==gc && y==gp && z==gf) return 1;
    if(pos>=N) return 0;
    if(x>gc || y>gp || z>gf) return 0;

    return solve(pos+1,x,y,z) || solve(pos+1,x+c[pos],y+p[pos],z+f[pos]);
}

int main(){

    int i,j,k,kases,t;

    freopen("new_years_resolution.txt","r",stdin);
    freopen("New_Year_Res_out.txt","w",stdout);

    scanf("%d",&kases);

    for(t=1;t<=kases;t++){
        scanf("%d %d %d",&gc,&gp,&gf);
        scanf("%d",&N);

        for(i=0;i<N;i++) scanf("%d %d %d",&c[i],&p[i],&f[i]);

        bool ans=solve(0,0,0,0);

        if(ans) printf("Case #%d: yes\n",t);
        else printf("Case #%d: no\n",t);
    }

    return 0;
}
