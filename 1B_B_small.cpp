#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#define MAXX 110
#define INF 9100000000000000000
#define pb push_back
#define all(v) v.begin(), v.end()
#define CLR(x) memset((x), 0, sizeof((x)))

using namespace std;
string C, J;

long long int dp[20][2];
int path_i[20][2], path_j[20][2];
int L;
bool seen[20][2];

long long int exp(long long int b, long long int p){

    int i;
    long long int j;
    j = 1;
    for( i = 0; i < p; i++) j *= b;

    return j;
}

void print_path(bool order){

    cout<< order << "";
    int i = 0;

    for(i = 0; i < L; i++) cout << path_i[i][order];
    for(i = 0; i < L; i++) cout << path_j[i][order];
}

long long int min_diff(int pos, int order){

    if(seen[pos][order]) return dp[pos][order];
    if(pos >= L) return 0;

    long long int ret = INF;

    if(order){

        long long int c_val, j_val;
        for(int i = 0; i < 10; i++){


            if(C[pos] == '?') c_val = (long long) i;
            else c_val = (long long) (C[pos] - '0');

            for(int j = 0; j < 10; j++){

                if(J[pos] == '?') j_val = (long long) i;
                else j_val = (long long) (J[pos] - '0');

                long long int tmp = (c_val - j_val) * exp(10, L - pos - 1) + min_diff(pos+1, order);

                if(tmp < ret) {path_i[pos][order] = c_val; path_j[pos][order] = j_val; ret = tmp;}
            }
        }
    }else{

        long long int c_val, j_val;
        for(int i = 0; i < 10; i++){


            if(C[pos] == '?') c_val = (long long) i;
            else c_val = (long long) (C[pos] - '0');

            for(int j = 0; j < 10; j++){

                if(J[pos] == '?') j_val = (long long) i;
                else j_val = (long long) (J[pos] - '0');

                long long int tmp = (j_val - c_val) * exp(10, L - pos - 1) + min_diff(pos+1, order);

                if(tmp < ret) {path_i[pos][order] = c_val; path_j[pos][order] = j_val; ret = tmp;}
            }
        }
    }

    dp[pos][order] = ret;
    seen[pos][order] = 1;

    return dp[pos][order];
}

int main(){

    //freopen("Documents/C++_programs/io/","r",stdin);
    //freopen("Documents/C++_programs/io/","w",stdout);

    int kases, i, j, t;

    scanf("%d", &kases);

    for(t = 1; t <= kases; t++){

        cin >> C >> J;
        CLR(seen);

        L = C.size();

        cout << "Case #" << t << ": ";

        if(abs(min_diff(0, 0)) <= abs(min_diff(0, 1))) print_path(0);
        else print_path(1);

        cout << endl;

    }

    return 0;
}
