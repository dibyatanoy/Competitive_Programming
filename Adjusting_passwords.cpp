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
#include <utility>
#define pb push_back
#define ll long long int
#define MP make_pair
#define CLR(a) memset(a,0,sizeof(a))
#define READ(x) freopen(x,"r",stdin)
#define WRITE(x) freopen(x,"w",stdout)
#define INF 1e8
#define MAXX 60

using namespace std;

int gcd(int a,int b){
    return (b==0)? a:gcd(b,a%b);
}

char pass[MAXX],seq[MAXX];

int main(){

    READ("a2.in");
    WRITE("a2.out");

    int t,i,j,k;
    cin>>t;
    getchar();

    while(t--){
        getchar();
        gets(pass);
        gets(seq);

        for(i=0;i<strlen(seq) && i<strlen(pass);i++){
            if(seq[i]!=pass[i]) break;
        }

        //cout<<i<<endl;
        if(i==strlen(seq)){
            for(j=i;j<strlen(pass);j++) printf("%c",pass[j]);
            cout<<"*"<<endl;
            //cout<<endl;
        }else if(i==strlen(pass)){

            for(j=i;j<strlen(seq);j++) printf("<",seq[j]);
            cout<<"*"<<endl;
            //cout<<endl;
        }else{
            j=i;
            if(strlen(seq)-j+strlen(pass)-j+1>1+strlen(pass)+1){
                cout<<"*"<<pass<<"*"<<endl;
            }else{
                for(k=strlen(seq)-1;k>=j;k--) cout<<"<";
                for(k=j;k<strlen(pass);k++) cout<<pass[k];
                cout<<"*"<<endl;

            }
        }
    }


    return 0;
}
