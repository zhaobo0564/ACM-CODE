#include<bits/stdc++.h>
using namespace std;

const int N = 107;

int t[N], w[N], n;

int dp[N][207][207];

int dfs(int p, int len, int sum) {
    if (sum > 201) return 1e7;
    if (p > n) {
        if (sum <= len) return 0;
        return 1e7;
    }
    if (dp[p][len][sum] != -1) return dp[p][len][sum];
    int ans = 1e7;
    ans = min(ans, dfs(p + 1, len + t[p], sum) + t[p]);
    ans = min(ans, dfs(p + 1, len, sum + w[p]));
    return dp[p][len][sum] = ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> w[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 0, 0) << endl;
}