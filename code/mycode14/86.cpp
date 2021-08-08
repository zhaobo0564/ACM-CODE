#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int a[N], n;
vector<int> g[N];
int fa[N], sz[N], son[N], deep[N];

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

int top[N];

void dfs1(int u, int up) {
    top[u] = up;
    if (son[u]) dfs1(son[u], up);
    for (int to: g[u]) {
        if (to == fa[u] || to == son[u]) continue;
        dfs1(to, to);
    }
}

int get_lca(int x, int y) {
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) {
            swap(x, y);
        }
        x = fa[top[x]];
    }
    if (deep[y] < deep[x]) {
        return y;
    }
    return x;
}

int x[N];

void work(int u) {
    for (int to: g[u]) {
        if (to == fa[u]) continue;
        work(to);
        x[u] += x[to];
    }
} 

void solve() {
    for (int i = 2; i <= n; i++) {
        int lca = get_lca(a[i], a[i - 1]);
        x[a[i]]++;
        x[a[i - 1]]++;
        x[lca]--;
        x[fa[lca]]--;
    }
    work(1);
    for (int i = 2; i <= n; i++) {
        x[a[i]]--;
    }
    for (int i = 1; i <= n; i++) {
        cout << x[i] << "\n";
    }
}



int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    dfs1(1, 0);
    solve();
}