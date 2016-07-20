#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main(){


    int i,j, kases;

    int N;

    freopen("Documents/C++_programs/io/A-large.in","r",stdin);
    freopen("Documents/C++_programs/io/Sheep_out_large.txt","w",stdout);

    scanf("%d", &kases);
    //fprintf(stdout, "Here! cases = %d\n", kases);

    for(int t = 1; t<=kases; t++){

    scanf("%d", &N);

    bool seen[10], fnd = false;
    int cnt = 0, curr = N;
    memset(seen, 0, sizeof(seen));

    if(N == 0) {

        printf("Case #%d: INSOMNIA\n", t);
        continue;
    }

    while(!fnd){

        i = N;

        for(i = N; i != 0; i /= 10){

            if(!seen[i % 10]){
                seen[i%10] = 1;
                cnt++;

                if(cnt == 10){

                    printf("Case #%d: %d\n", t, N);

                    fnd = 1;
                    break;
                }
            }
        }

        N += curr;
    }
    }

    return 0;
}
