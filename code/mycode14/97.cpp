#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n, q, v[N];

vector<int> g[N];

vector<pair<int, int> > qu[N];

int sz[N], son[N];


void dfs(int u) {
    sz[u] = 1;
    for (int to: g[u]) {
        dfs(to);
        sz[u] += sz[to];
        if (sz[son[u]] < sz[to]) {
            son[u] = to;
        }
    }
}

int tree[40 * N][2], top = 1;

void insert(int x) {
    int now = 0;
    for (int i = 30; i >= 0; i--) {
        int pos = (x & (1 << i));
        if (pos) pos = 1;
        if (!tree[now][pos]) {
            tree[now][pos] = top++;
        }
        now = tree[now][pos];
    }
}

int query(int k, int base, int now) {
    if (k < 0) return 0;
    int pos = (base & (1 << k));
    if (pos) pos = 1;
    if (tree[now][pos ^ 1]) {
        return query(k - 1, base, tree[now][pos ^ 1]) + (1 << k);
    } else {
        return query(k - 1, base, tree[now][pos]);
    }
}

void work(int u, int zson) {
    
    insert(v[u]);
    for (int to: g[u]) {
        if (to == zson) continue;
        work(to, zson);
    }
}

int ans[N];

void cal(int u) {
    for (auto it: qu[u]) {
        int x = it.first;
        int id = it.second;
        ans[id] = query(30, x, 0);
    }
}

void gao(int u, int ok) {
    for (int to: g[u]) {
        if (to == son[u]) continue;
        gao(to, 1);
    }
    if (son[u]) {
        gao(son[u], 0);
    }
    work(u, son[u]);
    cal(u);
    if (ok) {
        for (int i = 0; i <= top; i++) {
            tree[i][0] = tree[i][1] = 0;
        }
        top = 1;
    }

}

int main() {
    while (~scanf("%d %d", &n, &q)) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
            son[i] = 0;
            g[i].clear();
            qu[i].clear();

        }
        for (int i = 2; i <= n; i++) {
            int x; scanf("%d", &x);
            g[x].push_back(i);
        }
        for (int i = 1; i <= q; i++) {
            int u, x; scanf("%d %d", &u, &x);
            qu[u].push_back({x, i});
        }
        dfs(1);
        gao(1, 1);
        for (int i = 1; i <= q; i++) {
            printf("%d\n", ans[i]);
        }
    }
}