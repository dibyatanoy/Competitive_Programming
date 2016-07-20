#include <bits/stdc++.h>

using namespace std;

int main(){
    int kases,i,j,steps;
    long long n,sq,left,row,col;

    cin>>kases;

    for(i=1;i<=kases;i++){
        cin>>n;
        sq=sqrt(n);
        if((sq+1)*(sq+1)<=n) sq++;

        steps=sq+1;
        left=n-sq*sq;
        if(left==0){
            col=sq;
            row=1;
        }else if(left>steps){
            row=steps;
            col=2*steps-left;
        }else{
            col=steps;
            row=left;
        }
        if(sq%2==1) swap(row,col);

        cout << "Case " << i <<": " << col << " " << row << endl;
    }

    return 0;
}
