#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main(){

    int kases,i,j,op,pos=1;

    scanf("%d",&kases);

    for(i=1;i<=kases;i++){
        string sub="";
       while(1){
            if(sub.size()>99){
                cout << "Answer " << sub << endl;
                cout << flush;
                break;
            }
            cout << "Ask " << ((pos==1)? sub+"0":"0"+sub) << endl;
            cout << flush;
            scanf("%d",&op);
            if(op==1){
                sub=(pos==1)? sub+"0":"0"+sub;
                continue;
            }else{
                cout << "Ask " << ((pos==1)? sub+"1":"1"+sub) << endl;
                cout << flush;
                scanf("%d",&op);
                if(op==1){
                    sub=(pos==1)? sub+"1":"1"+sub;
                    continue;
                }else{
                    if(pos==1) pos=0;
                    else {
                        cout << "Answer " << sub << endl;
                        cout<<flush;
                        break;
                    }
                }
            }
       }
    }

    return 0;
}
