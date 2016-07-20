#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define MAXX 1002
#define ll long long
#define pb push_back

using namespace std;

struct data{
    int val,pos;
};

int N,M,k;
int a[MAXX][MAXX];
bool z[MAXX][MAXX];
vector <int> nums1,nums;
int hist[MAXX];

int buildhist(){
    stack<data>now;
    data temp;
    int l[MAXX],r[MAXX],i,ans=0;

    while(!now.empty()) now.pop();

    l[0]=-1;
    temp.val=hist[0];
    temp.pos=0;
    now.push(temp);


    for(i=1;i<M;i++){
        while(!now.empty() && (now.top().val>=hist[i])) now.pop();

        if(!now.empty()) l[i]=now.top().pos;
        else l[i]=-1;

        temp.val=hist[i];
        temp.pos=i;

        now.push(temp);

    }

    while(!now.empty()) now.pop();

    r[M-1]=M;
    temp.val=hist[M-1];
    temp.pos=M-1;
    now.push(temp);

    for(i=M-2;i>=0;i--){
        while(!now.empty() && now.top().val>=hist[i]) now.pop();

        if(!now.empty()) r[i]=now.top().pos;
        else r[i]=M;

        temp.val=hist[i];
        temp.pos=i;
        now.push(temp);
    }

    /*for(i=0;i<M;i++){
        printf("%d %d ",l[i],r[i]);
    }
    cout<<endl;*/

    //printf("*%d %d %d %d\n",l[0],r[0],l[1],r[1]);
    for(i=0;i<M;i++){
        ans=max(ans,hist[i]*(r[i]-1-l[i]));
    }


    return ans;
}

int check(int curr){
    int i,j,ans=0;

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(a[i][j]>=curr) z[i][j]=1;
            else z[i][j]=0;
        }
    }

    memset(hist,0,sizeof(hist));
    for(i=0;i<N;i++){

        for(j=0;j<M;j++){
            if(z[i][j]==1) hist[j]++;
            else hist[j]=0;

        }
        //if(curr==2 && i==1) printf("%d %d\n",hist[0],hist[1]);

        /*for(j=0;j<M;j++){
            printf("%d ",hist[j]);
        }
        cout<<endl;*/

        ans=max(ans,buildhist());
        //cout<<"! "<<curr<<" "<<ans<<" "<<endl;
    }

    //cout<<ans<<endl;
    return ans;
}

int main(){

    int i,j;

    freopen("burrow.in","r",stdin);
    freopen("burrow.out","w",stdout);

    scanf("%d%d%d",&N,&M,&k);

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%d",&a[i][j]);
            nums1.pb(a[i][j]);
        }
    }
    sort(nums1.begin(),nums1.end());
    nums.clear();

    for(i=0;i<nums1.size();i++){
        if(i==0) nums.pb(nums1[i]);
        else{
                if(nums1[i]==nums1[i-1]) continue;
                nums.pb(nums1[i]);

        }
    }
    //cout<<nums.size()<<endl;

    int lo=0;
    int hi=nums.size()-1;

    while(lo<=hi){

        int mid=(lo+hi)/2;
        //cout<<lo<<" "<<mid<<" "<<hi<<endl;
        int max_a=check(nums[mid]);

        //cout<<max_a<<endl;

        if(max_a>=k){
            //cout<<"!"<<endl;
            lo=mid+1;
        }else hi=mid-1;
    }

    printf("%d %d\n",nums[lo-1],check(nums[lo-1]));
    return 0;
}

/** AC!!! **/
