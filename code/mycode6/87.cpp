#include<bits/stdc++.h>
using namespace std;

const int N = 3e4 + 7;

typedef long long ll;

ll a[N];

vector<int> g[N];

int fa[N], deep[N], top[N], son[N], sz[N], id[N], cat[N], n;

void dfs(int u, int f) {
    //cout << "u " << u << endl;
    fa[u] = f;
    sz[u] = 1;
    deep[u] = deep[f] + 1;
    for (int to: g[u]) {
        if (to == f) continue;
        dfs(to, u);
        sz[u] += sz[to];
        if (sz[son[u]] < sz[to]) {
            son[u] = to;
        }
    }
}

int cnt = 1;

void dfs1(int u, int up) {
    id[u] = cnt++;
    cat[id[u]] = u;
    top[u] = up;
    if (son[u]) dfs1(son[u], up);
    for (int to: g[u]) {
        if (to == fa[u] || to == son[u]) continue;
        dfs1(to, to);
    }
} 

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

struct segment {
    ll maxn, sum;
} tree[4 * N];

void build(int l, int r, int node) {
    if (l == r) {
        tree[node].maxn = tree[node].sum = a[cat[l]];
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node].sum = tree[lson].sum + tree[rson].sum;
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
}

void update(int pos, int v, int l, int r, int node) {
    if (l == r) {
        tree[node].maxn = tree[node].sum = v;
        return;
    }
    if (pos <= m) update(pos, v, l, m, lson);
    else update(pos, v, m + 1, r, rson);
    tree[node].sum = tree[lson].sum + tree[rson].sum;
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
}

ll ans = 0, maxn = -1e12;

void query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        ans += tree[node].sum;
        maxn = max(maxn, tree[node].maxn);
        return;
    }
    if (ql <= m) query(ql, qr, l, m, lson);
    if (qr > m) query(ql, qr, m + 1, r, rson);
    

}

ll mx = -1e15, sum = 0;

void qu(int x, int y) {
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        ans = 0, maxn = -1e17;
        query(id[top[x]], id[x], 1, n, 1);
        sum += ans;
        mx = max(mx, maxn);
        x = fa[top[x]];
    }

    if (deep[x] < deep[y]) swap(x, y);
    ans = 0, maxn = -1e17;

    query(id[y], id[x], 1, n, 1);
    sum += ans, mx = max(maxn, mx);
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
    dfs1(1, 1);
    build(1, n, 1);
    int q; scanf("%d", &q);
    while (q--) {
        char s[10];
        scanf(" %s", s);
        if (s[0] == 'Q') {
            int l, r;scanf("%d %d", &l, &r);
            sum = 0, mx = -1e17;
            qu(l, r);
            if (s[1] == 'S') {
                printf("%lld\n", sum);
            } else {
                printf("%lld\n", mx);
            }
        } else {
            int l, r; scanf("%d %d", &l, &r);
            update(id[l], r, 1, n, 1);
        }
    }
}

