#include <bits/stdc++.h>
#define MAXX 50005

using namespace std;
char pattern[MAXX],target[MAXX];
int f[MAXX];
vector <int> matches;

void pre_kmp(){
    int i,k;
    int m=strlen(pattern);
    k=0;
    f[0]=-1;

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

void kmp(){
    int sp=0,kp=0;
    int m=strlen(target),n=strlen(pattern);

    while(sp<m){
        while(kp!=-1 && (kp==n || pattern[kp]!=target[sp])) kp=f[kp];
        kp++;
        sp++;

        if(kp==n) matches.push_back(sp-n);
    }
    return;
}

int main(){

    int kases,i,j,k;

    cin>>kases;

    for(i=1;i<=kases;i++){
        cin>>target>>pattern;

        pre_kmp();
        kmp();

        //for(j=0;j<matches.size();j++) cout<<matches[j]<<" "<<endl;
        //cout<<endl;

        int contain=0;
        int n=strlen(pattern);
        int last=-1;

        for(j=0;j<matches.size();j++){
            int bef=(matches[i]-last-1);
            int aft=strlen(target)-1-(matches[i]+n-1);
            contain+=1+bef+aft+bef*aft;
        }
        cout<<contain<<endl;

        matches.clear();
    }

    return 0;
}
