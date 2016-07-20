#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define pb push_back

using namespace std;
bool bit[14];

void print_ans(int x){
    int num=0,i,curr=1;

    for(i=0;i<x;i++){
        num+=bit[i]*curr;
        curr*=2;
    }
    printf("Answer %d\n",num);
    fflush(stdout);
}

int main(){

    int kases,i,j,n,bt_no;
    bool is_one;
    vector <int> zeros,ones,curr;
    int e_z,e_o;
    scanf("%d",&kases);

    while(kases--){
        scanf("%d",&n);
        zeros.clear();
        ones.clear();
        is_one=0;
        j=0;
        bt_no=0;

        for(i=1;i<n;i++) curr.pb(i);

        while(1){
            zeros.clear();
            ones.clear();
            if(curr.size()==0) {print_ans(bt_no);break;}
            for(i=0;i<curr.size();i++){
                int bt;
                printf("Ask %d %d\n",curr[i],j);
                fflush(stdout);
                scanf("%d",&bt);
                (bt==1)? ones.pb(curr[i]):zeros.pb(curr[i]);
            }
            if((curr.size()+1)%2==0){
                e_z=(curr.size()+1)/2;
                e_o=(curr.size()+1)/2;
                if(zeros.size()<e_z){
                    curr.clear();
                    bit[bt_no++]=0;
                    for(i=0;i<zeros.size();i++) curr.pb(zeros[i]);
                }else{
                    curr.clear();
                    is_one=1;
                    bit[bt_no++]=1;
                    for(i=0;i<ones.size();i++) curr.pb(ones[i]);
                }
            }else{
                if(is_one){e_o=(curr.size()+1)/2;e_z=curr.size()+1-e_o;}
                else {e_z=(curr.size()+1)/2;e_o=curr.size()+1-e_z;}
                if(zeros.size()<e_z){
                    curr.clear();
                    bit[bt_no++]=0;
                    for(i=0;i<zeros.size();i++) curr.pb(zeros[i]);
                }else{
                    curr.clear();
                    is_one=1;
                    bit[bt_no++]=1;
                    for(i=0;i<ones.size();i++) curr.pb(ones[i]);
                }
            }
            j++;
        }
    }

    return 0;
}

/** AC!!! **/
