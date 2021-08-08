#include<bits/stdc++.h>
using namespace std;

const int N = 5007;

int dp[N][N], n, m;

char s[N], t[N];

int main() {
    scanf("%d %d", &n, &m);
    scanf("%s %s", s + 1, t + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = max(dp[i - 1][j - 1] + 2, 2);
                dp[i][j] = max(dp[i - 1][j] - 1, dp[i][j]);
                dp[i][j] = max(dp[i][j - 1] - 1, dp[i][j]);
            } else {
                dp[i][j] = max(dp[i - 1][j] - 1, dp[i][j]);
                dp[i][j] = max(dp[i][j - 1] - 1, dp[i][j]);
            }
        }
    }
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}