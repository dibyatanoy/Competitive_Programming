#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n,k,dp[34],prev[34];

struct data{
    int num,dim[11];
    bool operator <(const data &p)const{
        int a;
        for(a=0;a<k;a++){
            if(dim[a]!=p.dim[a]) return dim[a]<p.dim[a];
        }
        return dim[k-1]<p.dim[k-1];
    }
};

data boxes[34];

int main(){

    int i,j,p;

    while(scanf("%d %d",&n,&k)==2){
        bool val;
        int mx=1,mx_pos=0;

        memset(boxes,0,sizeof(boxes));

        for(i=0;i<n;i++){
            boxes[i].num=i;
            for(j=0;j<k;j++){
                cin >> boxes[i].dim[j];
            }
            sort(boxes[i].dim,boxes[i].dim+k);
        }
        sort(boxes,boxes+n);
        for(i=0;i<n;i++) dp[i]=1;
        memset(prev,-1,sizeof(prev));

        for(i=1;i<n;i++){
            for(j=0;j<i;j++){
                val=true;
                for(p=0;p<k;p++){
                    if(boxes[i].dim[p]<=boxes[j].dim[p]){
                        val=false;
                        break;
                    }
                }
                if(val && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>mx){
                mx=dp[i];
                mx_pos=i;
            }
        }

        cout << mx << endl;
        vector <int> ans;
        ans.clear();
        for(i=mx_pos;i!=-1;i=prev[i]){

                ans.push_back(boxes[i].num);

        }
        cout << ans[ans.size()-1]+1;
        for(i=ans.size()-2;i>=0;i--){
            cout << " " << ans[i]+1;

        }
        cout << endl;
    }

    return 0;
}

/** AC!!! **/
