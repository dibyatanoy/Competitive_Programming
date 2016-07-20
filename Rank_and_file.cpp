#include <set>
#include <map>
#include <utility>
#define INF 100000000
#define MAXX 100
#define eps 1e-9
#define PI 2*arccos(0.0)
#define all(v) v.begin(), v.end()
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
string s;

struct lst{

    int cols[MAXX];

    bool operator < (const data &p)const{

        int i,j;
        for(i = 0; ; i++){
            if(cols[i] == -1) return 1;

            if(cols[i] == p.cols[i]) continue;
            else return cols[i] < p.cols[i];
        }
    }
};


int main(){

    int i,j,k;
    int t;

    cin >> t;

    for(i = 1; i <= t; i++){

        cin >> N;

        lst nums[2*N - 1];
        int grid[N][N];

        for(j = 0; j < 2*N - 1; j++){

            memset(nums[j].cols, -1, sizeof(nums[j].cols));

            for(k = 0; k < N; k++){

                cin >> nums[j].cols[k];
            }
        }

        sort(all(nums));
        bool to_row = 1;

        row_num = 0;
        col_num = 0;

        for(j = 0; j < 2*N - 1; j++){

            if(to_row){

                for(k = 0; grid[row_num][k] != -1; k++){

                    if(grid[row_num][k] != nums[j].cols[k]){

                        missing_row =
                    }
                }
            }
        }
    }


    return 0;
}
