#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 7;

int n, a[N], dp[N];

int dfs(int p) {
    if (p == n) return 0;
    int ans = 0;
    if (dp[p] != -1) return dp[p];
    if (a[p + 1] >= a[p]) {
        ans += dfs(p + 1) + 1;
    }
    return dp[p] = ans;

}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1ll * dfs(i) + 1;
    }
    cout << ans << endl;
}