#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;
const ll mod = 1e9 + 7;
int n;

vector<pair<int, ll> > g[N];

ll deep[N];

void dfs(int u, int fa, ll d) {
    deep[u] = d;
    for (auto it: g[u]) {
        int to = it.first;
        ll w = it.second;
        if (to == fa) continue;
        dfs(to, u, d ^ w);
    }
}

ll ans = 0;

void work(ll id) {
    ll one = 0, zero = 0;
    for (int i = 1; i <= n; i++) {
        ll pos = deep[i] & (1ll * 1 << id);

        if (pos) {
            ll cnt = (1ll * 1 << id) % mod;
            cnt = cnt * zero % mod;
            ans += cnt;
            ans %= mod;
            one++;
        } else {
            ll cnt = (1ll * 1 << id) % mod;
            cnt = cnt * one % mod;
            ans += cnt;
            ans %= mod;
            zero++;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0, 0);
    // for (int i = 1; i <= n; i++) {
    //     cout << deep[i] << endl;
    // }
    for (int i = 0; i <= 60; i++) {
        work(i);
    }
    printf("%lld\n", ans);
    return 0;
}