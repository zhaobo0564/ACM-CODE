#include<bits/stdc++.h>
using namespace std;
const int N = 2007;

typedef long long ll;

const ll mod = 1e9 + 7;

char mp[N][N];
ll dp[N][N], n, m, sum[4];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '.') {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;  
            } else {
                dp[i][j] = 0;

            }
          
            
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            
        }
    }
}