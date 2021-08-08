#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

typedef long long ll;

ll n, t[N], dist[N], dp[N][5], sz[N];
int f[N];

vector<pair<int, int> > g[N];

void dfs(int u, int fa) {
    sz[u] = 1;
    f[u] = fa;
    dp[u][2] = t[u];
    for (auto it: g[u]) {
        int to = it.first;
        ll w = it.second;
        if (to == fa) continue;
        dfs(to, u);
        sz[u] += sz[to];
        dp[u][1] += dp[to][1] + sz[to] * w;
        dp[u][2] += dp[to][2];
        dp[u][3] += dp[to][3] + dp[to][2] * w;
    }
    dp[u][0] = dp[u][1] * t[u] + dp[u][3];
}

ll ans[N];

void dfs1(int u,  ll dp0, ll dp1, ll dp2, ll dp3) {
    ans[u] = dp0;
    for (auto it: g[u]) {
        int to = it.first;
        ll w = it.second;
        if (to == f[u]) continue;
        ll siz = n - sz[to];
        ll last1 = dp1 - dp[to][1] - w * sz[to];
        ll last2 = dp2 - dp[to][2];
        ll last3 = dp3 - dp[to][3] - dp[to][2] * w;
        ll p1 = last1 + w * siz;
        ll p2 = last2 + t[to];
        ll p3 = last3 + last2 * w;
        ll p0 = p1 * t[to] + p3 + dp[to][0];
        p1 = p1 + dp[to][1];
        p2 = p2 + dp[to][2] - t[to];
        p3 = p3 + dp[to][3];
        dfs1(to, p0, p1, p2, p3);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    dfs1(1, dp[1][0], dp[1][1], dp[1][2], dp[1][3]);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}