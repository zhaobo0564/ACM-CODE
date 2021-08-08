#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
vector<pair<int, int > > g[N];

ll n, dp[N], ans;

ll cal(ll x) {
    return ((11 + x + 10) * x) / 2;
} 

void dfs(int u, int fa) {
    for (auto it: g[u]) {
        int to = it.first;
        ll w = it.second;
        if (to == fa) continue;
        dfs(to, u);
        ans = max(ans, dp[u] + dp[to] + w);
        dp[u] = max(dp[u], dp[to] + w);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    cout << cal(ans) << endl;
}