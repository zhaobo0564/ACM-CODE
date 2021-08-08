#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
typedef long long ll;
vector<int> g[N];

ll a[N], n, q;

int id[N], cnt = 1, fa[N], sz[N], son[N];

ll tree[4 * N], flag[4 * N], sum[N];

void dfs(int u, int f) {
    id[u] = cnt++;
    fa[u] = f;
    sz[u] = 1;
    for (int to: g[u]) {
        if (to == f) continue;
        dfs(to, u);
        son[u]++;
        sz[u] += sz[to];
    }
}

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1


void push_down(int node, int nl, int nr) {
    if (flag[node]) {
        tree[lson] += flag[node] * 1ll * nl;
        tree[rson] += flag[node] * 1ll * nr;
        flag[lson] += flag[node];
        flag[rson] += flag[node];
        flag[node] = 0;
    }
}

void update(ll v, int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        tree[node] += 1ll * (r - l + 1) * v;
        flag[node] += v;
        return;
    }
    push_down(node, m - l + 1, r - m);
    if (ql <= m) update(v, ql, qr, l, m, lson);
    if (qr > m) update(v, ql, qr, m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];
}

ll query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    ll ans = 0;
    push_down(node, m - l + 1, r - m);
    if (ql <= m) ans += query(ql, qr, l, m, lson);
    if (qr > m) ans += query(ql, qr, m + 1, r, rson);
    return ans;
}


int main() {
    freopen("in.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        update(a[i], id[i], id[i], 1, n, 1);
    }
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int u; cin >> u;
            cout << query(id[u], id[u] + sz[u] - 1, 1, n, 1) + sum[fa[u]] << endl;
        } else if (op == 2) {
            int u, v; cin >> u >> v;
            update(v, id[u], id[u] + sz[u] - 1, 1, n, 1);
        } else {
            int u, v; cin >> u >> v;
            update(v, id[u], id[u], 1, n, 1);
            for (int to: g[u]) {
                if (to == fa[u]) continue;
                update(v, id[to], id[to], 1, n, 1);
            }
        }
    }
}