#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define MAXX 18

using namespace std;
char x[MAXX],y[MAXX],curr[MAXX];
long long int xn,yn;

int main(){

    //freopen("odometer.in","r",stdin);
    //freopen("odometer.out","w",stdout);

    cin>>x>>y;
    cin>>xn>>yn;
    int i,j,pos,a1=0,a2=0,l1=0,l2=0,k;

    //for(pos=xn;pos!=0;l1++,pos/=10);
    //for(pos=yn;pos!=0;l2++,pos/=10);
    //a1=10*9*((l1+1)*l1/2-1)-((l1-1)*l1/2-1);
    bool ok;
    bool fnd;
    l1=strlen(x)-1;
    l2=strlen(y)-1;

    a1=9*9*(l1-1)+9*9*(l1-1)*l1/2;
    a2=9*9*(l2-1)+9*9*(l2-1)*l2/2;
    cout<<a1<<" "<<a2<<endl;

    for(i=0;i<=9;i++){
        for(j=0;j<=9;j++){

            for(pos=0;pos<strlen(x) && i!=j;pos++){
                ok=true;
                fnd=false;
                //if(i==1 && j==0 && pos==1) printf("!\n");
                if(pos==0 && j==0) continue;
                if(pos>0 && i==0) continue;
                for(k=0;k<pos;k++){
                        if(i<x[k]-'0'){a1++;fnd=true;break;}
                        else if(i>x[k]-'0') {ok=false;break;}
                }
                if(fnd) continue;
                if(!ok) continue;
                //if(i==1 && j==0 && pos==1) printf("! %d\n",x[k]-'0');
                if(j<x[k]-'0'){a1++;continue;}
                else if(j>x[k]-'0') continue;
                k+=1;
                ok=true;
                for(;k<strlen(x);k++){
                    if(i<x[k]-'0'){break;}
                    else if(i>x[k]-'0') {ok=false;break;}
                }
                if(ok) a1++;
                //if(i==1 && j==0 && pos==1) printf("!\n");
            }

        }
    }
    for(i=0;i<=9;i++){
        for(j=0;j<=9;j++){

            for(pos=0;pos<strlen(y) && i!=j;pos++){
                ok=true;
                fnd=false;
                //if(i==1 && j==0 && pos==1) printf("!\n");
                if(pos==0 && j==0) continue;
                if(pos>0 && i==0) continue;
                for(k=0;k<pos;k++){
                        if(i<y[k]-'0'){a2++;fnd=true;break;}
                        else if(i>y[k]-'0') {ok=false;break;}
                }
                if(fnd) continue;
                if(!ok) continue;
                //if(i==1 && j==0 && pos==1) printf("! %d\n",x[k]-'0');
                if(j<y[k]-'0'){a2++;continue;}
                else if(j>y[k]-'0') continue;
                k+=1;
                ok=true;
                for(;k<strlen(y);k++){
                    if(i<y[k]-'0'){break;}
                    else if(i>y[k]-'0') {ok=false;break;}
                }
                if(ok) a2++;
                //if(i==1 && j==0 && pos==1) printf("!\n");
            }

        }
    }
    cout<<a1<<" "<<a2<<endl;
    bool seen[10];

    memset(seen,0,sizeof(seen));
    for(i=0;i<strlen(x);i++) seen[x[i]-'0']=1;
    j=0;
    for(i=0;i<9;i++) j+=(seen[i])? 1:0;
    if(j==2) a2++;

    int ans=0;
    for(i=xn;i<=yn;i++){
        j=i;
        memset(seen,0,sizeof(seen));
        while(j!=0){
            seen[j%10]=1;
            j/=10;
        }
        j=0;
        for(int k=0;k<9;k++) j+=(seen[k])? 1:0;
        if(j==2) ans++;
    }
    cout << a2-a1<<" "<<ans<<endl;

    return 0;
}
