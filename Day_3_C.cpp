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
#define MAXX 100010
#define pb push_back
#define CLR(a) memset(a,0,sizeof(a))
#define all(v) v.begin(),v.end()
#define MP make_pair
#define PII pair<int,int >
#define ll long long

using namespace std;

long long int N;

vector< int> full,curr;

int main(){

        int kases,i,j;

        scanf("%d",&kases);

        while(kases--){
            scanf("%lld",&N);

            long long int s_now=0;
            long long int left=N;
            long long int c=0;
            curr.clear();
            i=1;

            full.clear();

            while(left>0){
                //printf("%d\n",left);
                //getchar();
                if((long long)(s_now*2+(long long)(1)+c)>N){
                    //printf("%d\n",i);
                    c+=s_now;
                    s_now=0;


                    for(j=curr.size()-1;j>=0;j--){
                        full.push_back(curr[j]);
                    }
                    curr.clear();
                    left=N-s_now-c;
                }else{

                    s_now=s_now*2+1;
                    curr.push_back(i);
                    left=N-s_now-c;
                    i++;
                }

            }


            for(j=curr.size()-1;j>=0;j--){
                full.push_back(curr[j]);
            }
            cout<<full.size()<<endl;

            cout<<full[full.size()-1];

            for(i=full.size()-2;i>=0;i--){
                cout<<" "<<full[i];
            }
            cout<<endl;

        }

    return 0;
}
