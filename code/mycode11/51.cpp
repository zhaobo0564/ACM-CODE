#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int n, a[N], m;

vector<int> g[N];

int vis[N];

typedef long long ll;

ll maxn = 0, ct = 0;

void dfs(int u) {
    vis[u] = 1;
    ct++;
    maxn = max(maxn, 1ll*a[u]);
    for (int to: g[u]) {
        if (vis[to]) continue;
        dfs(to);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            maxn = 0;
            ct = 0;
            dfs(i);
            ans += ct * maxn;
        }
    }
    cout << ans << endl;

}