#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;
ll t, n, a[55], b[55], c[55];

struct node {
    ll a, b, c;
}g[N];


ll dp[55][N];

ll work(ll x, ll y, ll z) {
    return x - y * z;
}

int vis[55];

ll dfs(int p, int v) {
    if (p > n) return 0;
    if (dp[p][v] != -1) return dp[p][v];
    ll ans = 0;
    ans = max(ans, dfs(p + 1, v));
    if (v - g[p].c >= 0) {
        ans =  max(ans, dfs(p + 1, v - g[p].c) + work(g[p].a, g[p].b, t - v + g[p].c));
    }
    return dp[p][v] = ans;
}

int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        g[i] = {a[i], b[i], c[i]};
    }
    sort(g + 1, g + n + 1, [](node x, node y) {
        return x.b * y.c > y.b * x.c;
    });


    memset(dp, -1, sizeof(dp));
    cout << dfs(1, t) << endl;
}