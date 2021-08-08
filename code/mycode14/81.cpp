#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int deep[N], a[N], rt[N], n, q, top = 1, maxn;;
vector<int> g[N];

#define m (l + r >> 1)

struct hjt {
    int minn, l, r;
} tree[40 * N];

void update(int pos, int v, int l, int r, int last, int &now) {
    now = top++;
    tree[now] = tree[last];
    if (l == r) {
        tree[now].minn = min(tree[now].minn, v);
        return; 
    }
    if (pos <= m) update(pos, v, l, m, tree[last].l, tree[now].l);
    else update(pos, v, m + 1, r, tree[last].r, tree[now].r);
    tree[now].minn = min(tree[tree[now].l].minn, tree[tree[now].r].minn);
}

int query(int ql, int qr, int l, int r, int now) {
    if (ql <= l && qr >= r) {
        return tree[now].minn;
    }
    int ans = INT_MAX;
    if (ql <= m) ans = min(ans, query(ql, qr, l, m, tree[now].l));
    if (qr > m) ans = min(ans, query(ql, qr, m + 1, r, tree[now].r));
    return ans;
}

int id[N], sz[N], cat[N], o = 1;

void dfs(int u, int fa) {
    id[u] = o++;
    sz[u] = 1;
    cat[o - 1] = u;
    deep[u] = deep[fa] + 1;
    maxn = max(deep[u], maxn);
    for (int to: g[u]) {
        if (to == fa) continue;
        dfs(to, u);
        sz[u] += sz[to];
    }
}

queue<int> Q;
int vis[N];

void bfs(int s) {
    Q.push(s);
    int last = 0;
    while (Q.size()) {
        int cd = Q.front();
        Q.pop();
        if (vis[cd]) continue;
        vis[cd] = 1;
        update(id[cd], a[cd], 1, n, rt[deep[last]], rt[deep[cd]]);
        last = cd;
        for (int to: g[cd]) {
            Q.push(to);
        }
    }
}

int main() {
    int r;
    for (int i = 0; i < 40 * N; i++) {
        tree[i].minn = INT_MAX;
    }
    scanf("%d %d", &n, &r);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(r, 0);
    bfs(r);

    scanf("%d", &q);
    int ans = 0;
    while (q--) {
        int u, k;
        scanf("%d %d", &u, &k);
        u = (u + ans) % n + 1;
        k = (k + ans) % n;
        int cnt = deep[u] + k;
        cnt = min(cnt, maxn);
        printf("%d\n", ans = query(id[u], id[u] + sz[u] - 1, 1, n, rt[cnt]));
    }
}