#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int son[N], top[N], id[N], cat[N], sz[N], father[N], deep[N], tree[4 * N];
vector<int> g[N];

void dfs(int u, int fa) {
    sz[u] = 1;
    father[u] = fa;
    deep[u] = deep[fa] + 1;
    for (int to: g[u]) {
        if (to == fa) continue;
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
        if (to == father[u]) continue;
        if (to == son[u]) continue;
        dfs1(to, to);
    }
}

int a[N], n;

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void update(int pos, int l, int r, int node) {
    tree[node]++;
    if (l == r) {
        return;
    }
    if (pos <= m) update(pos, l, m, lson);
    else update(pos, m + 1, r, rson);
}

int query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    int ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, lson);
    if (qr > m) ans += query(ql, qr, m + 1, r, rson);
    return ans; 
}

int qu(int x) {
    int ans = 0;
    while (top[x] != 1) {
        ans += query(id[top[x]], id[x], 1, n, 1);
        x = father[top[x]];
    }
    ans += query(id[top[x]], id[x], 1, n, 1);
    return ans;
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
        scanf("%d", &a[i]);
    }
    dfs(1, 0);
    dfs1(1, 1);

    for (int i = 1; i <= n; i++) {
        int r = id[a[i]];
        printf("%d\n", qu(a[i]));
        update(r, 1, n, 1);
    }



}

 

