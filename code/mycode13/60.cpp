#include<bits/stdc++.h>
using namespace std;
const int N = 2007;
typedef long long ll;
ll n, k;
const ll mod = 1e9 + 7;
ll dp[N][N][3];


ll dfs(int p, int now, int f) {
    if (p < 1 || p > n) return 0;
    if (now == 1) {
        return 0;
    }
    if (dp[p][now][f] != -1) return dp[p][now][f];
    ll ans = 0;
    if (f == 1) {
        ans += dfs(p + 1, now, 1);
        ans %= mod;
        ans += dfs(p, now - 1, 0) + 1;
        ans %= mod;
    } else {
        ans += dfs(p - 1, now, 0);
        ans %= mod;
        if (p > 1)
            ans += dfs(p, now - 1, 1) + 1;
        ans %= mod;
    }
    return dp[p][now][f] = ans;

}

void solve() {
    cin >> n >> k;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= k + 1; j++) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    cout << dfs(1, k, 1) + 1 << endl;

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}