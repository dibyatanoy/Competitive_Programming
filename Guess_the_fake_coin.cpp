#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    int kases,i,j,n,grp,l,u;

    scanf("%d",&kases);

    while(kases--){
        int op;
        scanf("%d",&n);
        l=1;u=n;
        while(1){

            if(n%3==0){
                grp=n/3;
            }else if(n%3==1) grp=n/3;
            else grp=n/3+1;

            printf("Test");
            for(i=l;i<=l-1+2*grp;i++){
                printf(" %d",i);
            }
            printf("\n");
            fflush(stdout);
            scanf("%d",&op);
            if(op==0){
                if(n-2*grp==1) {printf("Answer %d\n",u);fflush(stdout);break;}
                else {
                    l=l+2*grp;
                    n=u-l+1;
                }
            }else if(op==1){
                if(grp<=1) {printf("Answer %d\n",l);fflush(stdout);break;}
                //if(n-2*grp==1) {printf("Answer %d\n",u);fflush(stdout);break;}
                else{
                    u=l+grp-1;
                    n=u-l+1;
                }
            }else{
                if(grp<=1) {printf("Answer %d\n",l+grp);fflush(stdout);break;}
                //if(n-2*grp==1) {printf("Answer %d\n",u-1);fflush(stdout);break;}
                else{
                    l=l+grp;
                    u=l+grp-1;
                    n=u-l+1;
                }
            }
        }
    }

    return 0;
}

/*AC!!! */
