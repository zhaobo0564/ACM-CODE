#include<bits/stdc++.h>
using namespace std;
const int N = 5007;
typedef long long ll;
const ll mod = 1e9 + 7;

int b[N], t, n;
ll dp[N][N];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            scanf("%d", &b[i]);
        }
        for (int i = 1; i <= n; i++) {
            dp[n][i] = 1;
        }
        for (int i = n - 1; i; i--) {
            if (b[i]) {
                for (int j = 1; j <= n; j++) {
                    dp[i][j] = (dp[i + 1][j - 1] + dp[i][j - 1]) % mod;
                }
            } else {
                for (int j = n; j; j--) {
                    dp[i][j] = (dp[i + 1][j + 1] + dp[i][j + 1]) % mod;
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = (ans + dp[1][i]) % mod;
        }
        printf("%lld\n", ans);
    }
}