#include <bits/stdc++.h>

using namespace std;

int main(){

    int kases,i,j;
    string N,M;

    //freopen("cooking_the_books.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&kases);

    for(i=1;i<=kases;i++){

        int mx=-5,mn=100,mx_pos=0,mn_pos=0;
        cin>>N;
        M=N;

        cout<<"Case #"<< i << ": ";

        mx=N[0]-'0';
        mn=N[0]-'0';

        for(j=1;j<N.length();j++){
            if(N[j]-'0'>=mx && N[j]!='0'){
                mx=N[j]-'0';
                mx_pos=j;
            }
            if(N[j]-'0'<=mn && N[j]!='0'){
                mn=N[j]-'0';
                mn_pos=j;
            }
        }
        int tmp;

        for(j=0;j<mx_pos;j++){
            if(mx>N[j]-'0'){
                tmp=N[j];
                N[j]=mx+'0';
                N[mx_pos]=tmp;
                break;
            }
        }

        for(j=0;j<mn_pos;j++){
            if(mn<M[j]-'0'){
                tmp=M[j];
                M[j]=mn+'0';
                M[mn_pos]=tmp;
                break;
            }
        }

        cout<<M<<" "<<N<<endl;

    }

    return 0;
}
