#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

typedef long long ll;

ll son[N], sz[N], fa[N], id[N], cnt = 1, tree[4 * N], deep[N], top[N], a[N], cat[N];
ll n, q, r, p;

vector<int> g[N];

void dfs(int u, int f) {
    fa[u] = f;
    deep[u] = deep[f] + 1;
    sz[u] = 1;
    for (int to: g[u]) {
        if (to == f) continue;
        dfs(to, u);
        sz[u] += sz[to];
        if (sz[son[u]] < sz[to]) {
            son[u] = to;
        }
    }
}

void dfs1(int u, int up) {
    id[u] = cnt++;
    cat[id[u]] = u;
    top[u] = up;
    if (son[u]) dfs1(son[u], up);
    for (int to: g[u]) {
        if (to == fa[u]) continue;
        if (to == son[u]) continue;
        dfs1(to, to);
    }
}

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

ll flag[4 * N];

void build(int l, int r, int node) {
    if (l == r) {
        tree[node] = a[cat[l]];
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node] = (tree[lson] + tree[rson]) % p;
}

void push_down(int node, int nl, int nr) {
    if (flag[node]) {
        tree[lson] = (tree[lson] + (flag[node] * 1ll * nl) % p) % p;
        tree[rson] = (tree[rson] + (flag[node] * 1ll * nr) % p) % p;
        flag[lson] += flag[node];
        flag[rson] += flag[node];
        flag[lson] %= p;
        flag[rson] %= p;
        flag[node] = 0;
    }
}

void update(ll v, int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        tree[node] += v * 1ll * (r - l + 1) % p;
        flag[node] += v;
        flag[node] %= p;
        return;
    }
    push_down(node, m - l + 1, r - m);
    if (ql <= m) update (v, ql, qr, l, m, lson);
    if (qr > m) update(v, ql, qr, m + 1, r, rson);
    tree[node] = (tree[lson] + tree[rson]) % p;
}

ll query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    ll ans = 0;
    push_down(node, m - l + 1, r - m);
    if (ql <= m) ans = (ans + query(ql, qr, l, m, lson)) % p;
    if (qr > m) ans = (ans + query(ql, qr, m + 1, r, rson)) % p;
    return ans;
}

void up(int x, int y, ll v) {
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        update(v, id[top[x]], id[x], 1, n, 1);
        x = fa[top[x]];
    }
    if (deep[x] < deep[y]) swap(x, y);
    update(v, id[y], id[x], 1, n, 1);
}

ll qu(int x, int y) {
    ll ans = 0;
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        ans = (ans + query(id[top[x]], id[x], 1, n, 1));
        x = fa[top[x]];
    }
    if (deep[x] < deep[y]) swap(x, y);
    ans = (ans + query(id[y], id[x], 1, n, 1)) % p;
    return ans; 
}


int main() {
    scanf("%lld %lld %lld %lld", &n, &q, &r, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }   
    dfs(r, 0);
    dfs1(r, r);
    build(1, n, 1);
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x, y;
            ll z;
            scanf("%d %d %lld", &x, &y, &z);
            up(x, y, z);
        } else if (op == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%lld\n", qu(x, y));
        } else if (op == 3) {
            int x; ll z; scanf("%d %lld", &x, &z);
            int l = id[x], r = id[x] + sz[x] - 1;
            update(z, l, r, 1, n, 1);
        } else if (op == 4) {
            int x; scanf("%d", &x);
            int l = id[x], r = id[x] + sz[x] - 1;
            printf("%lld\n", query(l, r, 1, n, 1));
        }
    }



}