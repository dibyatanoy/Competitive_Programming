
//      In the Name of God

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <stack>
#include <list>
#include <queue>


using namespace std;

#define ll long long
#define pb push_back
int n , k;
long long dp[1001][1001][8];
long long a[4][1001];
long long BT(int i , int j ,int mask)
{
    if(j == 0)
        return 0ll;

    if(dp[i][j][mask] != -1)
        return dp[i][j][mask];

    long long ans = -1e10;

    if( (mask & (1 << 2)) == 0 && (mask & (1 << 1)) == 0)
        ans = max(ans, BT(i , j - 1 , (mask | 4) | 2) + a[1][i] + a[2][i]);
    if( (mask & (1 << 1)) == 0 && (mask & (1 << 0)) == 0)
        ans = max(ans, BT(i , j - 1 , (mask | 1) | 2) + a[2][i] + a[3][i]);

    if(i != n)
        for(int t = 0;t < (1 << 3);t ++)
        {
            if(mask & t)
                continue;
            int cost = 0 , cnt = 0;
            for(int p = 1;p <= 3;p ++)
            {
                if(t & (1 << (p - 1)))
                {
                    cost += a[3 - p + 1][i] + a[3 - p + 1][i + 1];
                    cnt ++;
                }
            }
            ans = max(ans , BT(i + 1 , j - cnt , t) + cost);
        }
    return (dp[i][j][mask] = ans);
}
int main(){
    memset(dp , - 1, sizeof dp);
    freopen("domine.in.1","r",stdin);
    cin >> n >> k;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= 3;j ++)
            cin >> a[j][i];
    cout << BT(1 , k , 0) << endl;

	return 0;
}
