#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define CLR(x) memset(x,0,sizeof(x))
#define ll long long int
#define B 0
#define R 1
#define MAXX 220000

using namespace std;

struct data{
    int top,btm,color;

    bool operator <(const data &p)const{
        if(top==p.top){
            return color>p.color;
        }else return top<p.top;
    }
};

int bit[MAXX],N,M;
int dia[MAXX],eq[MAXX];
data hooks[MAXX];

void update(int pos,int val){
    int i;
    for(i=pos;i<MAXX;i+=(i & -i)){
        bit[i]+=val;
    }
    return;
}

int query(int pos){
    int i,ret=0;
    if(pos==0) return 0;
    for(i=pos;i>0;i-= (i & -i)){
        ret+=bit[i];
    }
    return ret;
}

int main(){

    int i,j,k,t,kases;

    scanf("%d",&t);

    for(kases=1;kases<=t;kases++){
        scanf("%d %d",&N,&M);

        for(i=0;i<N;i++){
            scanf("%d %d",&hooks[i].btm,&hooks[i].top);
            hooks[i].color=B;
        }

        CLR(bit);
        CLR(dia);
        CLR(eq);

        for(i=0;i<M;i++){
            scanf("%d %d",&hooks[i+N].btm,&hooks[i+N].top);
            hooks[i+N].color=R;
        }
        sort(hooks,hooks+N+M);

        for(i=0;i<N+M;i++){
            if(hooks[i].color==B){
                //printf("!\n");
                update(hooks[i].btm,1);
                if(hooks[i].top<=hooks[i].btm) dia[hooks[i].top]++;
                if(hooks[i].top==hooks[i].btm) eq[hooks[i].top]++;
                //printf("U %d\n",hooks[i].btm);
            }
        }
        long long int crosses=0;

        //printf("! %d %d\n",hooks[N+M-2].color,hooks[N+M-1].color);

        for(i=0;i<N+M;i++){
            if(hooks[i].color==R){
                //printf("Q %d %d\n",hooks[i].btm,query(hooks[i].btm-1));
                crosses+=(ll)query(hooks[i].btm)+dia[hooks[i].top];
                //if(hooks[i].top==hooks[i].btm) crosses-=eq[hooks[i].top];

            }else{
                update(hooks[i].btm,-1);
            }
        }

        printf("Case %d: %lld\n",kases,crosses);
    }

    return 0;
}
