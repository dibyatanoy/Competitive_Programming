#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("out.txt","w",stdout);

    printf("100 4950\n");

    for(int i=1;i<=100;i++){
        for(int j=i+1;j<=100;j++) printf("%d %d 1 3\n",i,j);
    }

    return 0;
}
