#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <map>
#define pb push_back
#define MP make_pair
#define CLR(x) memset(x,0,sizeof(x));
#define INF 1e8
#define MAXX 550
#define READ(a) freopen(a,"r",stdin)
#define WRITE(a) freopen(a,"w",stdout)

using namespace std;
char seq[MAXX];
char punc[]={',', '.', ':', ';', '’', '"', '!', '?', '-'};
int N,mx_pos,words;
double mx;

int main(){

    int kases,i,j,m1,m2,curr;
    bool caps,ast;

    //READ("s1.in");
    //WRITE("s1.out");

    scanf("%d",&kases);

    while(kases--){
        mx=0.0;

        scanf("%d",&i);
        int sent=i;

        while(i--){
            getchar();
            scanf("%[^\n]s",seq);
            //cout<<seq<<endl;
            curr=0;
            m1=1;
            m2=1;
            caps=1;
            ast=0;
            words=0;

            int l=strlen(seq);

            for(j=0;j<l;j++){
                for(int k=0;k<9;k++){
                    if((j-1)>=0 && seq[j]==punc[k] && seq[j-1]!=' ' && seq[j-1]!='*'){
                        //printf("Here!\n");
                        if(caps) m2=2;
                        curr+=m1*m2;
                        m2=1;
                        caps=1;
                        words++;
                        break;
                    }
                }
                if(seq[j]==' ' && seq[j-1]!=' ' && seq[j-1]!='*'){
                    if(caps) m2=2;
                    curr+=m1*m2;
                    m2=1;
                    caps=1;
                    words++;
                }else if(seq[j]=='*'){
                    if(!ast){
                        if((j-1)>=0 && seq[j-1]!=' '){
                            if(caps) m2=2;
                            curr+=m1*m2;
                            m2=1;
                            caps=1;
                            words++;
                        }
                        ast=1;
                        m1=3;
                    }else{
                        if(seq[j-1]!=' ' && seq[j-1]!='*'){
                            if(caps) m2=2;
                            curr+=m1*m2;
                            m2=1;
                            caps=1;
                            words++;
                        }
                        ast=0;
                        m1=1;
                    }
                }else if(seq[j]>='a' && seq[j]<='z'){
                    caps=0;
                }
                if(j==l-1 && seq[j]!=' ' && seq[j]!='*'){
                    if(caps) m2=2;
                    curr+=m1*m2;
                    m2=1;
                    caps=1;
                    words++;
                }
            }
            //printf("! i= %d\n",i);
            //cout<<curr<<" "<<words<<endl;

            if((double)(curr)/(double)words >=mx){
                mx=(double)(curr)/(double)words;
                mx_pos=sent-i;
            }
        }
        cout<<mx_pos<<endl;
    }

    return 0;
}
