#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], n, q;
vector<pair<int, int> > g[N];
int maxn[N], sz[N], mx, rt, vis[N];

void get_rt(int u, int fa) {
    sz[u] = 1;
    maxn[u] = 0;
    for (auto it: g[u]) {
        int to = it.first;
        if (to == fa || vis[to]) continue;
        get_rt(to, u);
        sz[u] += sz[to];
        maxn[u] = max(sz[to], maxn[u]);
    }
    maxn[u] = max(maxn[u], n - sz[u]);
    if (mx > maxn[u]) {
        mx = maxn[u];
        rt = u;
    }
}

#define m (l + r >> 1)
int tree[200 * N], ls[200 * N], rs[200 * N], top = 1, Rt[N];

void update(int v, int pos, int l, int r, int &node) {
    if (!node) node = top++;
    if (l == r) {
        if (tree[node] == -1) tree[node] = v;
        else tree[node] = min(tree[node], v);
        return;
    }
    if (pos <= m) update(v, pos, l, m, ls[node]);
    else update(v, pos, m + 1, r, rs[node]);
    tree[node] = min(tree[ls[node]], tree[rs[node]]);
}

int query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        
        return tree[node];
    }
    int ans = INT_MAX;
    if (ql <= m) ans = min(ans, query(ql, qr, l, m, ls[node]));
    if (qr > m) ans = min(ans, query(ql, qr, m + 1, r, rs[node]));
    return ans;
}

vector<int> G[N];

void dfs(int u, int dep, int base, int f) {
    update(dep, a[u], 1, 10000, Rt[base]);
    for (auto it: g[u]) {
        int to = it.first;
        int w = it.second;
        if (vis[to] || to == f) continue;
        dfs(to, dep + w, base, u);
    }
}

void work(int u) {
    update(0, a[u], 1, 10000, Rt[u]);
    for (auto it: g[u]) {
        int to = it.first;
        int w = it.second;
        if (vis[to]) continue;
        dfs(to, w, u, u);
    }
}

void gao(int u) {
    vis[u] = 1;
    work(u);
    for (auto it: g[u]) {
        int to = it.first;
        if (vis[to]) continue;
        n = sz[to];
        mx = 1e8;
        get_rt(to, u);
        get_rt(rt, 0);
        G[u].push_back(rt);
        gao(rt);
    }
}

int father[N];

void dfs1(int u, int fa) {
    father[u] = fa;
    for (int to: G[u]) {
        dfs1(to, u);
    }
}

int Fa[N][30], dist[N], deep[N];

void dfs2(int u, int fa) {
    Fa[u][0] = fa;
    for (int i = 1; i <= 20; i++) {
        Fa[u][i] = Fa[Fa[u][i - 1]][i - 1];
    }
    for (auto it: g[u]) {
        int to = it.first;
        if (to == fa) continue;
        deep[to] = deep[u] + 1;
        dist[to] = dist[u] + it.second;
        dfs2(to, u);
    }
}

int get_lca(int x, int y) {
    if (deep[y] > deep[x]) swap(x, y);
    int d = deep[x] - deep[y]; 
    for (int i = 0; i <= 20; i++) {
        if (d & 1) {
            x = Fa[x][i];
        }
        d >>= 1;
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
        if (Fa[x][i] != Fa[y][i]) {
            x = Fa[x][i];
            y = Fa[y][i];
        }
    }
    return Fa[x][0];
}

int main() {
    memset(tree, -1, sizeof(tree));
    tree[0] = 1e9 + 7;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int root;
    mx = 1e8;
    dfs2(1, 0);
    get_rt(1, 0);
    get_rt(rt, 0);
    root = rt;
    gao(rt);
    dfs1(root, 0);
    while (q--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int u, x; scanf("%d %d", &u, &x);
            int now = u;
            while (now) {
                int lca = get_lca(u, now);
                int d = dist[now] + dist[u] - 2 * dist[lca];
                update(d, x, 1, 10000, Rt[now]);
                now = father[now];
            }
        } else {
            int u, x, y; scanf("%d %d %d", &u, &x, &y);
            int ans = INT_MAX;
            int now = u;
            while (now) {
                int lca = get_lca(u, now);
                int d = dist[now] + dist[u] - 2 * dist[lca];
                ans = min(ans, query(x, y, 1, 10000, Rt[now]) + d);
                now = father[now];
            }
            if (ans > 1e9) {
                puts("-1");
            } else
            printf("%d\n", ans + ans);
        }
    }
}
