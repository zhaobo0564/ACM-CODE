#include<bits/stdc++.h>

using namespace std;

const int N = 2e3 + 7;

typedef long long ll;

ll dp[N][N], a[N], n, vis[N], sum[N], m;
const ll mod =  20000311;


int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &a[i]);
        vis[a[i]] = 1;
    }
    
    for (int i = 0; i <= n; i++) {
        sum[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        
        if (vis[i]) {
            for (int j = i + 1; j <= n; j++) {
                dp[i][j] += sum[j - 1];
                dp[i][j] %= mod;
                dp[i][j] += dp[i - 1][j] * (j - (i - 1));
                dp[i][j] %= mod;
            }
        } else {
            for (int j = i; j <= n; j++) {
                dp[i][j] += sum[j - 1];
                dp[i][j] %= mod;
                dp[i][j] += dp[i - 1][j] * (j - (i - 1));
                dp[i][j] %= mod;
            }
        }

        sum[0] = 0;
        for (int j = 1; j <= n; j++) {
            sum[j] = sum[j - 1] + dp[i][j];
            sum[i] %= mod;
        }

        
    }
  //  cout << dp[3][3] << endl;
    cout << dp[n][n] << endl;


}