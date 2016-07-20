#include <bits/stdc++.h>
#define MAXX 100005

using namespace std;

int n,lef[MAXX],bit[MAXX];

void update(int pos,int val){
    int i;
    for(i=pos;i<=MAXX;i+=(i & -i)) bit[i]+=val;
}

int query(int pos){
    int i,ret=0;
    for(i=pos;i>0;i-=(i & -i)) ret+=bit[i];

    return ret;
}

int main(){

    int kases,i,j,k;
    cin>>kases;

    for(i=1;i<=kases;i++){
        cin >>n;
        for(j=0;j<n;j++) cin>>lef[j];
        memset(bit,0,sizeof(bit));

        int pos;

        for(j=n-1;j>=0;j--){
            pos=n-(lef[j]+query(MAXX)-query(j));
            cout << pos <<endl;
            update(pos,1);
        }

        printf("Case %d: %d\n",i,pos);
    }

    return 0;
}
