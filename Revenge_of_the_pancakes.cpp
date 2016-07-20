#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#define MAXX 110
#define INF 10000000

using namespace std;

bool seq[MAXX];
char str[MAXX];

int dp[MAXX][MAXX], N;
bool seen[MAXX][MAXX];

void flip(bool seen2[], bool fin[], int pos){

    int i;
    for(i = 0; i < N; i++) fin[i]= seen2[i];

    for(int lft = 0, rt = pos; lft <= rt; lft++, rt--){

        fin[lft] = 1 - seen2[rt];
        fin[rt] = 1- seen2[lft];
    }

    return;
}


int rec(bool curr[], int d){

    //printf("Here");
    if(d >= 10) return INF;

    int i;
    bool fnd = false;
    for(i = 0; i < N; i++){

        if(curr[i] == 1) {fnd = true; break;}
    }

    if(!fnd) return 0;
    int ans = INF;

    for(i = 0; i < N; i++){

        bool flipped[MAXX];
        flip(curr, flipped, i);

        ans = min(ans, 1 + rec(flipped, d + 1));
    }

    return ans;
}

int call(int pos, int odds){

    if(pos == N){

        if(odds == 0) return 0;
        else return INF;
    }

    if(seen[pos][odds]) return dp[pos][odds];

    if(seq[pos]){

        dp[pos][odds] = min(call(pos+1,odds+1), 1 + call(pos+1, pos - odds));
    }else{

        dp[pos][odds] = min(call(pos+1, odds), 1 + call(pos+1, pos + 1 - odds));
    }

    seen[pos][odds] = 1;

    return dp[pos][odds];
}

int main(){

    int kases, i, t;

    freopen("Documents/C++_programs/io/B-large.in","r",stdin);
    freopen("Documents/C++_programs/io/pancakes_out_large.txt","w",stdout);

    scanf("%d", &kases);

    for(t =  1; t<= kases; t++){

        scanf("%s", str);

        N= strlen(str);
        memset(seen, 0, sizeof(seen));

        for(i = 0; i < N; i++){

            if(str[i] == '-') seq[i] = 1;
            else seq[i] = 0;
        }

        printf("Case #%d: %d\n", t, call(0, 0));
    }

    return 0;
}
