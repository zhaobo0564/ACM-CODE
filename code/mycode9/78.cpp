#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int dep[N], fa[N][30];

vector<int> g[N];

int s[N * 10];

void dfs(int u, int f) {
    fa[u][0] = f;
    dep[u] = dep[f] + 1;
    for (int i = 1; i <= 20; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int to: g[u]) {
        if (to == f) continue;
        dfs(to, u);
    }
}

int get_lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    int d = dep[x] - dep[y];
    for (int i = 0; i <= 20; i++) {
        if ((d & (1 << i))) {
            x = fa[x][i];
        }
    }
    if (x == y) return x;

    for (int i = 20; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        } 
    }
    return fa[x][0];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    int q; scanf("%d", &q);
    int top = 1;
    while (q--) {
        int k; scanf("%d", &k);
        int mx = 0, node;
        for (int i = 1; i <= k; i++) {
            int x; scanf("%d", &x);
            s[i] = x;
            if (dep[x] > mx) {
                mx = dep[x];
                node = x;
            }
        }
        mx = 0;
        for (int i = 1; i <= k; i++) {
            int lca = get_lca(node, s[i]);
            int ans = dep[node] + dep[s[i]] - 2 * dep[lca];
            mx = max(ans, mx);
        }
        printf("%d\n", (mx + 1) / 2);

    }
}