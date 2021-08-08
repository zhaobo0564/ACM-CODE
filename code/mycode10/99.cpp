#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;

int head[N], cnt = 1;

struct edge {
    int to, w, nxt;
}e[2 * N];

void add_edge(int u, int v, int w) {
    e[cnt].w = w;
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

int o = 1, id[N], cat[N], sz[N], son[N], fa[N];

ll dist[N];

void dfs(int u, int f) {
    fa[u] = f;
    id[u] = o++;
    cat[o - 1] = u;
    sz[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        int w = e[i].w;
        if (to == f) continue;
        dist[to] = w;
        dfs(to, u);
        sz[u] += sz[to];
        if (sz[son[u]] < sz[to]) {
            son[u] = to;
        }

    }
}

int top[N];

void dfs1(int u, int up) {
    top[u] = up;
    if (son[u]) dfs1(son[u], up);
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        int w = e[i].w;
        if (to == fa[u] || to == son[u]) continue;
        dfs1(to, to);
    }
}
int n, q;
ll tree[4 * N];

void update(int v, int pos, int l, int r, int node) {
    if (l == r) {
        tree[node] += v;
        return;
    }
    if (pos <= m) update(v, pos, l, m, lson);
    else update(v, pos, m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];
}

ll query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    ll ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, lson);
    if (qr > m) ans += query(ql, qr, m + 1, r, rson);
    return ans;
}

ll ans[N];

void work(int x, int y) {
    update(y, id[x], 1, n, 1);
    while (fa[x]) {
        if (son[fa[x]] != x) {
            ans[fa[x]] += 1ll * y * dist[x];
        }
        
        x = top[fa[x]];
    }
}

ll cal(int u) {
    ll res = (tree[1] - query(id[u], id[u] + sz[u] - 1, 1, n, 1)) * dist[u];
    if (son[u]) {
        res += query(id[son[u]], id[son[u]] + sz[son[u]] - 1, 1, n, 1) * dist[son[u]];
        //cout << " dist " << son[u] << endl;
    }
 //   cout << ans[u] << endl;
  //  printf("ans[%d] = %lld\n", u, ans[u]);
    return ans[u] + res;

}

int main() {
    
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dfs(1, 0);
    dfs1(1, 1);
    
    scanf("%d", &q);
    int pos = 1;
    while (q--) {
        int op, v;
        scanf("%d %d", &op, &v);
        if (op == 1) {
            int x; scanf("%d", &x);
            work(v, x);
        } else {
            pos = v;
        }
        printf("%lld\n", cal(pos));
    }

}

