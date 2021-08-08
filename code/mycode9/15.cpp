#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500][500];
ll n, m;
ll dp[400][400];
ll dfs(int p, int sum) {
    if (sum >= n) return 0;
    if (p > n) {
        if (sum >= n) return 0;
        return 1e15;
    }
    if (dp[p][sum] != -1) return dp[p][sum];
    ll ans = INT_MAX;
    ll cnt = 0;
    if (sum >= p)
        ans = dfs(p + 1, sum);
    for (int i = 1; i <= m; i++) {
        cnt += a[p][i];
        ans = min(ans, dfs(p + 1, sum + i) + cnt + i * i);
    }
    return dp[p][sum] = ans;
}

int main() {
    ios::sync_with_stdio(0);
     cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
        sort(a[i] + 1, a[i] + m + 1);
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 0) << endl;

}