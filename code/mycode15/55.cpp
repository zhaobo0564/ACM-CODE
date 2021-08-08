#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int n, k, a[N], l[N];

void gao(int pos) {
    int p = upper_bound(a + 1, a + pos + 1, a[pos] / 2) - a;
    p--;
    l[pos] = p;
}

int dp[N][32];

int dfs(int p, int sum) {
    if (p < 1) {
        if (sum == 0) return 0;
        return 1e7;
    }
    if (dp[p][sum] != -1) return dp[p][sum];
    int ans = INT_MAX;
    ans = min(ans, dfs(p - 1, sum) + 1);
    ans = min(ans, dfs(l[p], sum - 1));
    return dp[p][sum] = ans;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        gao(i);
    }

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= 32; i++) {
        int ans = dfs(n, i);
        if (ans <= k) {
            cout << i << " " << ans << endl;
            return 0;
        }
    }


}