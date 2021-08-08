#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int rt[N], tree[40 * N], maxn[40 * N], ls[40 * N], rs[40 * N], n, q;

vector<int> g[N];

#define m (l + r) / 2

int fa[N][32], deep[N], ans[N];

void dfs(int u, int f) {
    fa[u][0] = f;
    deep[u] = deep[f] + 1;
    for (int i = 1; i <= 20; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int to: g[u]) {
        if (to == f) continue;
        dfs(to, u);
    }
}

int get_lca(int x, int y) {
    if (deep[y] > deep[x]) swap(x, y);
    int d = deep[x] - deep[y];

    for (int i = 0; i <= 20; i++) {
        if ((d & 1)) {
            x = fa[x][i];
        }
        d = d / 2;
    }
    if (x == y) return x;

    for (int i = 20; i >= 0; i--) {
        if (fa[x][i] == fa[y][i]) {

        } else {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}
int top = 1;
void update(int pos, int v, int l, int r, int &node) {
    if (!node) node = top++;
    tree[node] += v;
    if (l == r) {
        maxn[node] = tree[node];
        return;
    }
    if (pos <= m) update(pos, v, l, m, ls[node]);
    else update(pos, v, m + 1, r, rs[node]);
    maxn[node] = max(maxn[ls[node]], maxn[rs[node]]);
}

int query(int l, int r, int node) {
    if (l == r) return l;
    if (maxn[ls[node]] == maxn[node]) {
        return query(l, m, ls[node]);
    }
    return query(m + 1, r, rs[node]);
}

int merge(int x, int y, int l, int r) {
    if (!x) return y;
    if (!y) return x;
    if (l == r) {
        tree[x] += tree[y];
        maxn[x] = tree[x];
        return x;
    } 
    ls[x] = merge(ls[x], ls[y], l, m);
    rs[x] = merge(rs[x], rs[y], m + 1, r);
    maxn[x] = max(maxn[ls[x]], maxn[rs[x]]);
    tree[x] = tree[ls[x]] + tree[rs[x]];
    return x;
}

void dfs1(int u, int fa) {
    for (int to: g[u]) {
        if (to == fa) continue;
        dfs1(to, u);
        rt[u] = merge(rt[u], rt[to], 1, N);
    }

    ans[u] = query(0, N, rt[u]);
}



int main() {
    ios::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        update(z, 1, 0, N, rt[x]);
        update(z, 1, 0, N, rt[y]);
        update(z, -1, 0, N, rt[get_lca(x, y)]);
        update(z, -1, 0, N, rt[fa[get_lca(x, y)][0]]);
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }


}