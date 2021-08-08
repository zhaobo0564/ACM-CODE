#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;

ll a[N], n, dp[N];

ll dfs(int p) {
    if (p > n) {
        return 0;
    }
    if (dp[p] != -1) return dp[p];
    ll ans = 0;
    ans += dfs(p + a[p]) + a[p];
    return dp[p] = ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = -1;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;






}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}