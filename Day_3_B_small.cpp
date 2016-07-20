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
#include <cmath>
#define INF 1e7
#define MOD 1000000007
#define MAXX 14
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define all(v) v.begin(),v.end()
#define MP make_pair
#define PII pair<int,int >
#define ll long long

using namespace std;
int N,seq[MAXX],d;
bool taken[MAXX],taken_in_odd[MAXX],taken_in_even[MAXX];
int so_far[4100][MAXX],s_cnt=0;
int mask[MAXX];

bool check(){
    int i,j;
    bool fnd=false;

    for(i=0;i<s_cnt;i++){
        fnd=false;
        for(j=0;j<N;j++){
            if(mask[j]!=so_far[i][j]){fnd=true;break;}
        }
        if(!fnd) return 0;
    }

    for(i=0;i<N;i++) so_far[s_cnt][i]=mask[i];
    s_cnt++;

    //if(s_cnt>0) for(i=0;i<N;i++) printf("%d ",so_far[s_cnt-1][i]);
    //cout<<endl;
    return 1;
}

int solve(int odd,int even,int odd_cnt,int even_cnt){
    int ans=0;
    if(abs(odd-even)<=d && (odd_cnt==even_cnt || odd_cnt-even_cnt==1)){
        if(check()) ans++;
        //if(odd==0 && even==0) printf("%d\n",ans);
    }

    for(int i=0;i<N;i++){
        if(!taken[i]){
            taken[i]=1;
            mask[i]=1;

            ans+=solve(odd^seq[i],even,odd_cnt+1,even_cnt);

            if(odd_cnt+even_cnt>0){
                    taken[i]=1;
            mask[i]=0;
            ans+=solve(odd,even^seq[i],odd_cnt,even_cnt+1);
            }
            mask[i]=-1;
            taken[i]=0;
        }
    }
    return ans;
}

int main(){

    int i,j,k;

    scanf("%d %d",&N,&d);

    int temp[MAXX];

    memset(mask,-1,sizeof(temp));



    for(i=0;i<N;i++) cin>>seq[i];

    cout<<solve(0,0,0,0)-1<<endl;


    return 0;
}
