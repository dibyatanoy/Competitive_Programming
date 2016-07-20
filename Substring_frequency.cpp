#include <bits/stdc++.h>
#define MAXX 1000005

using namespace std;

char pattern[MAXX],target[MAXX];
int f[MAXX];

void pre_kmp(){
    int i,k;
    int m=strlen(pattern);

    f[0]=-1;
    k=0;

    for(i=1;i<=m;i++){
        k=f[i-1];

        while(k>=0){
            if(pattern[k]==pattern[i-1]) break;
            else k=f[k];
        }

        f[i]=k+1;
    }

    return;
}

int kmp(){
    int sp=0,kp=0,matches=0;
    int m=strlen(target), n=strlen(pattern);

    while(sp<m){
        while(kp!=-1 && (kp==n || pattern[kp]!=target[sp])) kp=f[kp];
        kp++;
        sp++;

        if(kp==n) {matches++;}
    }

    return matches;
}

int main(){

    int kases,i,j;

    scanf("%d",&kases);

    for(i=1;i<=kases;i++){

        scanf("%s",target);
        scanf("%s",pattern);

        //memset(f,-1,sizeof(f));

        pre_kmp();

        printf("Case %d: %d\n",i,kmp());

    }

    return 0;
}

/** AC!!! **/
