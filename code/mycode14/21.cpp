#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, q, head[N], top = 1, a[N], R;

struct edge {
    int nxt, to;
} e[2 * N];

void add_edge(int u, int v) {
    e[top].to = v;
    e[top].nxt = head[u];
    head[u] = top++;
}
int rt, sz[N], maxn[N], mx, vis[N];

#define m (l + r >> 1)
struct segment {
    int minn, dist;
} tree[200 * N];

int ls[200 * N], rs[200 * N], o = 1;

void update(int v, int pos, int l, int r, int &node) {
    if (!node) node = o++;
    if (l == r) {
        tree[node].dist = v;
        tree[node].minn = INT_MAX;
        return;
    }
    if (pos <= m) update(v, pos, l, m, ls[node]);
    else update(v, pos, m + 1, r, rs[node]);
    tree[node].minn = min(tree[ls[node]].minn, tree[rs[node]].minn);
}

void up(int f, int pos, int l, int r, int node) {
    if (l == r) {
        if (f == 1) {
            tree[node].minn = tree[node].dist;
        } else {
            tree[node].minn = INT_MAX;
        }
        return;
    }
    if (pos <= m) up(f, pos, l, m, ls[node]);
    else up(f, pos, m + 1, r, rs[node]);
    tree[node].minn = min(tree[ls[node]].minn, tree[rs[node]].minn);
}

void get_rt(int u, int fa) {
   
    sz[u] = 1;
    maxn[u] = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == fa || vis[to]) continue;
        get_rt(to, u);
        sz[u] += sz[to];
        maxn[u] = max(maxn[u], sz[to]);
    }
    maxn[u] = max(maxn[u], n - sz[u]);
    if (mx > maxn[u]) {

        mx = maxn[u];
        rt = u;
    }
}

struct node {
    int fa, dist;
};

int root[N];

vector<node> fn[N];

void dfs(int u, int fa, int dep, int base) {
    fn[u].push_back({base, dep});
    update(dep, u, 1, R, root[base]);
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == fa || vis[to]) continue;
        dfs(to, u, dep + 1, base);
    }
}

void work(int u) {
    update(0, u, 1, R, root[u]);
    fn[u].push_back({u, 0});
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (vis[to]) continue;
        
        dfs(to, u, 1, u);
    }
}

void gao(int u) {
    vis[u] = 1;
    work(u);
    for (int i = head[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (vis[to])continue;
        mx = 1e8;
        n = sz[to];
        get_rt(to, u);
        get_rt(rt, 0);
        gao(rt);
    }
}

int main() {
    tree[0].minn = INT_MAX;
    scanf("%d", &n);
    R = n;
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    mx = 1e8;
    get_rt(1, 0);
    get_rt(rt, 0);
    gao(rt);
    scanf("%d", &q);
    while (q--) {
        int op, u; scanf("%d %d", &op, &u);
        if (op == 0) {
            a[u] ^= 1;
            for (int i = 0; i < fn[u].size(); i++) {
                up(a[u], u, 1, R, root[fn[u][i].fa]);
            }
        } else {
            int ans = INT_MAX;
            for (int i = 0; i < fn[u].size(); i++) {
                if (tree[root[fn[u][i].fa]].minn != INT_MAX) {   
                    ans = min(ans, tree[root[fn[u][i].fa]].minn + fn[u][i].dist);
                }
            }
            if (ans == INT_MAX) {
                ans = -1;
            }
            printf("%d\n", ans);
        }
    }
}