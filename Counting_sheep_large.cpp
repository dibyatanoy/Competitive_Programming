#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main(){


    int i,j, kases;

    int curr, N, tot;

    scanf("%d", &tot);

    //freopen("Sheep_large.txt","w", stdout);

    for(curr = 0; curr<=tot; curr++){


        bool seen[10], fnd = false;
        int cnt = 0;
        memset(seen, 0, sizeof(seen));

        N = curr;

        if(N == 0) {
            printf("INSOMNIA");
            continue;
        }

        while(!fnd){

            i = N;

            for(i = N; i != 0; i /= 10){

                if(!seen[i % 10]){
                    seen[i%10] = 1;
                    cnt++;

                    if(cnt == 10){

                        printf(", %d", N);

                        fnd = 1;
                        break;
                    }
                }
            }

            N += curr;
        }
    }

    printf("\n");

    return 0;
}
