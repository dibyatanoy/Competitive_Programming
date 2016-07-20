#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#define MAXX 210000
#define INF 1000000000000000LL
#define pb push_back
#define MP make_pair
#define all(v) v.begin(),v.end()
#define Fr First
#define Sc Second
#define CLR(x) memset(x,0,sizeof(x))

using namespace std;

struct data{
    long long int x,y;

    bool operator <(const data &p)const{
        return x<p.x;
    }
};

int N,K;
long long int cu_sum[MAXX],cnt[MAXX];
vector <long long int> pos;
vector <data> pos2;
long long int tot;
long long int ans;

int main(){

    int i,j, a;
    CLR(cu_sum);
    CLR(cnt);
    tot=0;

    scanf("%d %d",&K,&N);

    char x,y,disc;
    long long int x_p,y_p;


    if(K==1){

        scanf("%c",&disc);

        for(i=0;i<N;i++){
            scanf("%c %lld %c %lld",&x,&x_p,&y,&y_p);
            scanf("%c",&disc);
            //printf("%lld %lld\n", x_p, y_p);

            if(x==y){
                ans+=max(x_p,y_p)-min(x_p,y_p);
                //printf("! %lld\n",ans);
            }else{

                pos.pb(x_p);
                pos.pb(y_p);
                ans+=1;
            }

        }
        if(pos.size()==0){printf("%lld\n",ans);return 0;}

        sort(all(pos));
        N=pos.size();

        //for(i=0;i<N;i++) printf("%lld ",pos[i]);
        //printf("\n");


        int mid=(N+1)/2;

        if(2*mid == (N+1)){
            for(i=0;i<N;i++){
                ans+=max(pos[i],pos[mid-1])-min(pos[i],pos[mid-1]);
            }
            printf("%lld\n",ans);
        }else{
            long long opt=(pos[mid-1]+pos[mid])/2;
            for(i=0;i<N;i++){
                ans+=max(pos[i],opt)-min(pos[i],opt);
            }
            printf("%lld\n",ans);
        }
    }else{

        long long int mn=INF;
        long long int br=-2;
        long long int curr=0LL;
        data tmp;

        scanf("%c",&disc);

        for(i=0;i<N;i++){
            scanf("%c %lld %c %lld",&x,&x_p,&y,&y_p);
            scanf("%c",&disc);
            //printf("%lld %lld\n", x_p, y_p);

            if(x==y){
                ans+=max(x_p,y_p)-min(x_p,y_p);
                //printf("! %lld\n",ans);
            }else{

                tmp.x=x_p;tmp.y=y_p;pos2.pb(tmp);
                tmp.x=y_p;tmp.y=x_p;pos2.pb(tmp);

                ans+=1;
            }

        }

        sort(all(pos2));

        for(i=0;i<pos2.size();i++){
            long long int bridge1=pos2[i].x;
            curr=0;
            pos.clear();

            for(j=0;j<=i;j++){
                if(pos2[j].y>=bridge1){
                    curr+=pos2[j].y-pos2[j].x;
                }else{
                    curr+=bridge1-(pos2[j].x);
                }
            }
            for(;j<pos2.size();j++){

                if(pos2[j].x>bridge1 && pos2[j].y>bridge1){
                    pos.pb(pos2[j].x);
                }
            }
            sort(all(pos));
            int sz=pos.size();


            //if(i==0) printf("! %lld\n",curr);

            /*if(i==0){
                for(j=0;j<pos.size();j++){
                    printf("%lld ",pos[j]);
                }
                printf("\n");
            }*/
            if(sz!=0){
                int mid=(sz+1)/2;

                if(2*mid == (sz+1)){
                    for(a=0;a<sz;a++){
                        curr+=max(pos[a],pos[mid-1])-min(pos[a],pos[mid-1]);
                    }

                }else{
                    long long opt=(pos[mid-1]+pos[mid])/2;
                    for(a=0;a<sz;a++){
                        curr+=max(pos[a],opt)-min(pos[a],opt);
                    }

                }
            }
            //if(pos2[i].x==2) printf("! %lld\n", curr+ans);
            if(mn>curr){
                mn=curr;
                br=bridge1;
            }
        }

        printf("%lld\n", mn+ans);
    }
    return 0;
}
