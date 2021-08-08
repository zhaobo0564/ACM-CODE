#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
const ll mod = 19260817;
ll add[N], n, q, sz[N], sum[N], cat[N], son[N];
vector<int> g[N];
int fa[N];

void dfs(int u, int f) {
    fa[u] = f;
    sz[u] = 1;
    for (int to: g[u]) {
        if (to == f) continue;
        sz[u]++;
        dfs(to, u);
    }
}


int main() {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    dfs(1, 0);
    ll ans = 0;
    for (ll i = 1; i <= q; i++) {
        int x; scanf("%d", &x);
        
        sum[x]++;
        cat[fa[x]]++;
        son[fa[fa[x]]]++;
        sum[0] = cat[0] = son[0] = 0;
        ll cnt = sum[x] * sz[x] + cat[fa[x]] + cat[x] * 2 + sum[fa[x]] * 2 + son[x] + sum[fa[fa[x]]];
        ans = (ans + cnt * i % mod) % mod;
     //   cout << "cnt = " << cnt << endl;
    }
    cout << ans << endl;
    return 0;
}