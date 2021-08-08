#include<bits/stdc++.h>
using namespace std;

const int N = 500;

int a[N], n, t, dp[N][N];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 400; j++) {
                dp[i][j] = 1e8;
            }
        }
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 400; j++) {
                for (int z = 0; z < j; z++) {
                    dp[i][j] = min(dp[i - 1][z] + abs(a[i] - j), dp[i][j]);
                }
            }
        }

        int ans = 1e8;
        for (int j = 1; j <= 400; j++) {
            ans = min(ans, dp[n][j]);
        }
        cout << ans << endl;

    }
}