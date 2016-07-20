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
#define INF 10000000
#define pb push_back
#define all(v) v.begin(), v.end()
#define CLR(x) memset((x), 0, sizeof((x)))

using namespace std;

int cnt[30];
string num;

bool allzero(){

    int i;

    for(i = 0; i < 28; i++){

        if(cnt[i] != 0) {/*printf("%d\n", i);*/return false;}

    }
    return true;
}

int main(){

    //freopen("Documents/C++_programs/io/A-small-attempt0 (2).in","r",stdin);
    //freopen("Documents/C++_programs/io/B1_A_small.txt","w",stdout);

    int kases, i, j, t;

    cin >> kases;
    //cout << kases;

    for(t = 1; t <= kases; t++){

        CLR(cnt);
        cin >> num;

        int l = num.size();


        for(i = 0; i < l; i++){

            cnt[num[i] - 'A']++;
        }

        cout << "Case #" << t << ": ";

        printf("%d\n", l);

        while(!allzero()){
        if(cnt['Z' - 'A'] && cnt['E' - 'A'] && cnt['R' - 'A'] && cnt['O' - 'A']){

            cout << 0;
            cnt['Z' - 'A']--;
            cnt['E' - 'A']--;
            cnt['R' - 'A']--;
            cnt['O' - 'A']--;
            continue;

        }
        if(cnt['O' - 'A'] && cnt['N' - 'A'] && cnt['E' - 'A']){

            cout << 1;
            cnt['O' - 'A']--;
            cnt['N' - 'A']--;
            cnt['E' - 'A']--;
            continue;

        }
        if(cnt['T' - 'A'] && cnt['W' - 'A'] && cnt['O' - 'A']){

            cout << 2;
            cnt['T' - 'A']--;
            cnt['W' - 'A']--;
            cnt['O' - 'A']--;
            continue;

        }
        if(cnt['T' - 'A'] && cnt['H' - 'A'] && cnt['R' - 'A'] && cnt['E' - 'A'] >= 2){

            cout << 3;
            cnt['T' - 'A']--;
            cnt['H' - 'A']--;
            cnt['R' - 'A']--;
            cnt['E' - 'A']--;
            cnt['E' - 'A']--;
            continue;

        }
        if(cnt['F' - 'A'] && cnt['O' - 'A'] && cnt['U' - 'A'] && cnt['R' - 'A']){

            cout << 4;
            cnt['F' - 'A']--;
            cnt['O' - 'A']--;
            cnt['U' - 'A']--;
            cnt['R' - 'A']--;
            continue;

        }
        if(cnt['F' - 'A'] && cnt['I' - 'A'] && cnt['V' - 'A'] && cnt['E' - 'A']){

            cout << 5;
            cnt['F' - 'A']--;
            cnt['I' - 'A']--;
            cnt['V' - 'A']--;
            cnt['E' - 'A']--;
            continue;

        }
        if(cnt['S' - 'A'] && cnt['I' - 'A'] && cnt['X' - 'A']){

            cout << 6;
            cnt['S' - 'A']--;
            cnt['I' - 'A']--;
            cnt['X' - 'A']--;
            continue;

        }
        if(cnt['S' - 'A'] && cnt['E' - 'A'] >= 2 && cnt['V' - 'A'] && cnt['N' - 'A']){

            cout << 7;
            cnt['S' - 'A']--;
            cnt['E' - 'A']--;
            cnt['V' - 'A']--;
            cnt['E' - 'A']--;
            cnt['N' - 'A']--;
            continue;

        }
        if(cnt['E' - 'A'] && cnt['I' - 'A'] && cnt['G' - 'A'] && cnt['H' - 'A'] && cnt['T' - 'A']){

            cout << 8;
            cnt['E' - 'A']--;
            cnt['I' - 'A']--;
            cnt['G' - 'A']--;
            cnt['H' - 'A']--;
            cnt['T' - 'A']--;
            continue;

        }
        if(cnt['N' - 'A'] >= 2 && cnt['I' - 'A'] && cnt['E' - 'A']){

            cout << 9;
            cnt['N' - 'A']--;
            cnt['I' - 'A']--;
            cnt['N' - 'A']--;
            cnt['E' - 'A']--;
            continue;
            //cnt['T' - 'A']--;

        }
        }
        cout << endl;

    }
    //printf("Here\n");

    return 0;
}
