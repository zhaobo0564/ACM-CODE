#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e3 + 7;

ll mp[N][N], dp[N][N], fn[N][N];
int n, q;
const ll mod = 998244353;

ll sum[N][N];

int main() {
    // freopen("C.in", "r", stdin);
    // freopen("C.out", "w", stdout);
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &mp[i][j]);
        }
    }
    dp[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fn[i][j] = (fn[i - 1][j] + fn[i][j - 1]) % mod;
            fn[i][j] = (fn[i][j] + dp[i][j] * mp[i][j] % mod) % mod;
        }
    }
    ll ans = fn[n][n];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
        }
    }

    while (q--) {
        int x, y, len, c;
        scanf("%d %d %d %d", &x, &y, &len, &c);
        for (int i = len; i; i--) {
            ans += (1ll * c * ((sum[x][y + i - 1] - sum[x][y - 1] + mod) % mod)) % mod;
            cout << "cnt " << sum[x][y + i - 1] - sum[x][y - 1] << endl;
            x++;
        }
        
        
        printf("%lld\n", ans);

    }
}