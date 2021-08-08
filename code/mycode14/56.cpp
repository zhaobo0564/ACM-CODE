#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;

int n, q, w[N], head[N], o = 1, rt[N + N];

struct {
    int nxt, to;
} e[2 * N];



void add_edge(int u, int v) {
    e[o].to = v;
    e[o].nxt = head[u];
    head[u] = o++;
}

int fa[N][30], deep[N];

void dfs(int u, int f) {
    fa[u][0] = f;
    deep[u] = deep[f] + 1;
    for (int i = 1; i <= 22; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == f) continue;
        dfs(to, u);
    }
}

int get_lca(int x, int y) {
    if (deep[x] < deep[y]) swap(x, y);
    int d = deep[x] - deep[y];
    for (int i = 0; i <= 22; i++) {
        if ((d & 1)) {
            x = fa[x][i];
        }
        d = d / 2;
    }
    if (x == y) return x;
    for (int i = 22; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

#define m (l + r >> 1)

int tree[40 * N], ls[40 * N], rs[40 * N], top = 1;

void update(int pos, int v, int l, int r, int &node) {
    if (!node) node = top++;
    if (l == r) {
        tree[node] += v;
        return;
    }
    if (pos <= m) update(pos, v, l, m, ls[node]);
    else update(pos, v, m + 1, r, rs[node]);
}

int merge(int x, int y, int l, int r) {
    if (!x || !y) return x + y;
    if (l == r) {
        tree[x] += tree[y];
        return x;
    }
    ls[x] = merge(ls[x], ls[y], l, m);
    rs[x] = merge(rs[x], rs[y], m + 1, r);
    return x;
}

int query(int pos, int l, int r, int node) {
    if (l == r) return tree[node];
    if (pos <= m) return query(pos, l, m, ls[node]);
    return query(pos, m + 1, r, rs[node]);
}

int ans[N];

void work(int u, int fa) {
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == fa) continue;
        work(to, u);
        rt[u] = merge(rt[u], rt[to], 1, 2 * n);
        rt[u + n] = merge(rt[u + n], rt[to + n], 1, 3 * n);
    }

    int cnt = deep[u] + w[u] + n;
   // cout << "cnt = " << deep[u] + w[u] << " " << w[u] - deep[u] << endl;
   if (cnt <= 2 * n)
    ans[u] = query(cnt, 1, 2 * n, rt[u]);
    cnt = w[u] - deep[u] + 2 * n;
    ans[u] += query(cnt, 1, 3 * n, rt[u + n]);
    
}


int main() {
    scanf("%d %d", &n, &q);  
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
  
    dfs(1, 0);
    for (int i = 1; i <= q; i++) {
        int s, t; scanf("%d %d", &s, &t);
        int lca = get_lca(s, t);
       // cout << "deep " << deep[s] << " t = " << deep[s] - 2 * deep[lca] << " lca " << lca << endl;
        update(deep[s] + n, 1, 1, 2 * n, rt[s]);
        update(deep[s] + n, -1, 1, 2 * n, rt[fa[lca][0]]);
        update(deep[s] - 2 * deep[lca] + 2 * n, 1, 1, 3 * n, rt[t + n]);
        update(deep[s] - 2 * deep[lca] + 2 * n, -1, 1, 3 * n, rt[lca + n]);
    }
    work(1, 0);
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    puts("");



}