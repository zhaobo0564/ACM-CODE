#include <bits/stdc++.h>

using namespace std;

int a[200], n, dp[300][2];

int dfs(int p, int ok) {
    if (dp[p][ok] != -1) return dp[p][ok];
    int ans = 0;
    if (ok) {
        for (int i = p + 1; i <= n; i++) {
            if (a[i] > a[p]) {
                ans = max(ans, dfs(i, 1) + 1);
                ans = max(ans, dfs(i, 0) + 1);
            }
        }
    } else {
        for (int i = p + 1; i <= n; i++) {
            if (a[i] < a[p]) {
                ans = max(ans, dfs(i, 0) + 1);
            }
        }
    }
    return dp[p][ok] = ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    memset(dp, -1, sizeof(dp));
    int ans = dfs(0, 1);
    cout << n - ans << endl;

}