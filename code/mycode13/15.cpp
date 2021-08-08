#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 7;
char s[N];
int n, dp[N][N][6];

int dfs(int l, int r, int f) {
    if (r <= l) {
        return 1;
    }
    int ans = 0;
    if (dp[l][r][f] != -1) return dp[l][r][f];
    if (f < 2) {
        if (s[l] == s[r]) {
            ans = max(ans, dfs(l + 1, r - 1, f));
        } else {
            ans = max(ans, dfs(l + 1, r, f + 1));
            ans = max(ans, dfs(l, r - 1, f + 1));
        }
    } else {
        if (s[l] == s[r]) {
            ans = max(ans, dfs(l + 1, r - 1, f));
        }
    }
    return dp[l][r][f] = ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d %s", &n, s + 1);
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= n + 1; j++) {
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
            }
        }
        int ans = dfs(1, n, 0);
        if (ans == 1) {
            puts("Yes");
        } else {
            puts("No");
        }

    }
}