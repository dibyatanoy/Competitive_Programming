#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define MAXX 50

using namespace std;
char keyboard[]={'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};

char str[200];
char mov;
int off;

int main(){

    int i,j,k,tmp;

    scanf("%c",&mov);
    scanf("%c",&tmp);

    scanf("%s",&str);

    if(mov=='L') off=+1;
    else off=-1;

    for(i=0;i<strlen(str);i++){
        for(j=0;j<30;j++){
            if(keyboard[j]==str[i])
            {str[i]=keyboard[j+off];break;}
        }
    }

    printf("%s\n",str);

    return 0;
}
