#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
string seq;
string out;

int conv(char c){

    if(c>'0' && c<'9') return c-'0';
    else return 10+(c-'A');
}


int main(){

    int i,j,k,P,kase;
    int bytes;
    int run,n_run;
    int curr_out;

    scanf("%d",&P);

    while(P--){
        cin>>kase>>bytes;
        cin>>seq;

        int curr=0;
        curr_out=0;

        while(curr<2*bytes){
            int tmp=16*(conv(seq[curr]))+conv(seq[curr+1]);


            if(tmp&(1<<16)){
                run=tmp-1<<16;
                run=conv(seq[curr+1])+3;

                while(run--){
                    out+=(string)
                }
            }else{

            }
        }
    }

    return 0;
}
