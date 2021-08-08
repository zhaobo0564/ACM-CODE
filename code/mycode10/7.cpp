#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;

typedef long long ll;

ll a[N], q, n, k, dp[N][N];

int main() {
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[0][i] = a[i];
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1) {
                dp[i][j] = dp[i - 1][j + 1] + a[j];
            } else if (j == n) {
                dp[i][j] = dp[i - 1][j - 1] + a[j];
            } else {
                dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1] + a[j] + a[j];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[k][i];
    }
    cout << ans << endl;

}
