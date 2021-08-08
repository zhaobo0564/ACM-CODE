#include<bits/stdc++.h>
using namespace std;
const int N = 2007;
typedef long long ll;

ll dp[N][N], n, m, fn[N][N], f[N][N];
const ll mod = 1e9 + 7;

ll x[N][N], y[N][N], z[N][N];

char mp[N][N];

int main() {
    scanf("%lld %lld", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &mp[i][j]);
        }
    }
    dp[1][1] = 1;
    x[1][1] = 1, y[1][1] = 1, z[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (mp[i][j] == '.') {
                dp[i][j] = (x[i - 1][j] + y[i][j - 1] + z[i - 1][j - 1]) % mod;

                x[i][j] = (x[i - 1][j] + dp[i][j]) % mod;
                y[i][j] = (y[i][j - 1] + dp[i][j]) % mod;
                z[i][j] = (z[i - 1][j - 1] + dp[i][j]);
            } else {
                x[i][j] = y[i][j] = z[i][j] = dp[i][j] = 0;
            }
            // ÈýÎ¬ dp
            // for (int k = i - 1; k; k--) {
            //     dp[i][j] += dp[k][j];
            // }
            // for (int k = j - 1; k; k--) {
            //     dp[i][j] += dp[i][k];
            // }
            // for (int k = 1; k < min(i, j); k++) {
            //     dp[i][j] += dp[i - k][j - k];
            // }
        }
    }
    cout << dp[n][m] << endl;
}