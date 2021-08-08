#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;

ll dp[N], a[N], sum[N];
int n, father[N];
vector<int> g[N];
ll maxn = 0;
ll mod = 10007, ans = 0;

void dfs(int u, int fa) {
    father[u] = fa;
    for (int to: g[u]) {
        if (to == fa) continue;
        dfs(to, u);
        ans = (ans + (sum[u] % mod * a[to] % mod) % mod) % mod;
        maxn = max(maxn, dp[u] * a[to]);
        dp[u] = max(dp[u], a[to]);
        sum[u] = (sum[u] + a[to]) % mod;
    }
}


 
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        int x = father[father[i]];
        maxn = max(maxn, a[i] * a[x]);
        ans = (ans + a[i] * a[x]) % mod;
    }
    ans = (ans + ans) % mod;
    printf("%lld %lld\n", maxn, ans);
}