#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
const ll mod = 1e9 + 7;
ll a[N], b[N], dp[N];
vector<int> g[N];

int n, m, vis[N];


void dfs(int u) {
    vis[u] = 1;
    for (int to: g[u]) {
        if (vis[to] == 0) {
            dfs(to);       
        }
        dp[u] += dp[to] + b[to];
        dp[u] %= mod;
    }
    
}

int main() {
    while (~scanf("%d %d", &n, &m)) {
        for (int i = 1; i <= n; i++) {
            scanf("%lld %lld", &a[i], &b[i]);
            vis[i] = 0;
            g[i].clear();
            dp[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                dfs(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            ans = ans + (a[i] * dp[i]) % mod;
            ans %= mod;
        }
        printf("%lld\n", ans);
    }
}

