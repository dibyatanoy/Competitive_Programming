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
#define INF 1e7
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define all(v) v.begin(),v.end()
#define MAXX 205
#define MAXXN 205
#define PII pair <int,int >
#define ll long long
#define MP make_pair

using namespace std;

vector <string> pals;
string seq;

void check(int st,int ed){
    int i,j;
    i=st;j=ed;

    while(i<j){
        if(seq[i]!=seq[j]) return;
        i++;
        j--;
    }
    string temp="";
    for(i=st;i<=ed;i++) temp+=(seq[i]);

    pals.pb(temp);

    return;
}

int main(){

    int i,j;

    freopen("palindrome.in","r",stdin);
    freopen("palindrome.out","w",stdout);

    cin>>seq;
    int l=seq.length();

    for(i=0;i<l;i++){
        for(j=i;j<l;j++) check(i,j);
    }

    sort(all(pals));

    //for(i=0;i<pals.size();i++) cout<<pals[i]<<endl;

    //sort(all(pals));

    long long int curr_l,curr_cnt;

    curr_l=pals[0].length();curr_cnt=1;
    long long int mx=1;

    for(i=1;i<pals.size();i++){
        if(pals[i]==pals[i-1]){
            curr_cnt++;
        }else{
            mx=max(curr_cnt*curr_l,mx);
            curr_cnt=1;
            curr_l=pals[i].length();
        }
    }
    cout<<mx<<endl;

    return 0;
}
