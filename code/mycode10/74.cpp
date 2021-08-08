#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

struct segment {
    int maxn, len;

}tree[4 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1


int work(int k, int l, int r, int node) {
    if (l == r) return 0;
    if (tree[lson].maxn > k) {
        return work(k, l, m, lson);
    } else {
        return work(k, m + 1, r, rson) + tree[node].len - tree[rson].len;
    }
}

segment merge (segment x, segment y, int l, int r, int node) {
    segment z;
    if (x.len == 0) return y;
    if (y.len == 0) return x;
    z.maxn = max(x.maxn, y.maxn);
    if (x.maxn >= y.maxn) {
        z.len = x.len;
    } else {
        z.len = x.len + y.len - work(x.maxn, l, r, node);
    }
    return z;
}

void update(int pos, int v, int l, int r, int node) {
    if (l == r) {
        tree[node].maxn = v;
        tree[node].len = 1;
        return;
    }
    if (pos <= m) update(pos, v, l, m, lson);
    else update(pos, v, m + 1, r, rson);
    tree[node] = merge(tree[lson], tree[rson], m + 1, r, rson);
}

segment query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    segment res;
    res.len = 0;
    if (ql <= m) res = merge(res, query(ql, qr, l, m, lson), m + 1, r, rson);
    if (qr > m) res = merge(res, query(ql, qr, m + 1, r, rson), m + 1, r, rson);
    return res;

}

vector<int> g[N];
int a[N];

struct qu{
    int v, c, id;
};

vector<qu> cnt[N];

int ans[N];
int n, q, dist[N];

void dfs(int u, int fa, int dep) {
    dist[u] = n - dep;
    for (int to: g[u]) {
        if (to == fa) continue;
        update(n - dep - 1, a[to], 1, n, 1);
        for (qu j: cnt[to]) {
            int l = n - dep - 1;
            int r = dist[j.v];
            if (j.v == to) {
                r = n - dep -1;
            }
      
            if (j.c >= a[to]) {
                update(n - dep - 1, j.c, 1, n, 1);
                ans[j.id] = query(l, r, 1, n, 1).len - 1;
                update(n - dep - 1, a[to], 1, n, 1);
            } else {
    
                ans[j.id] = query(l, r, 1, n, 1).len;
            }

        }
        dfs(to, u, dep + 1);
        update(n - dep - 1, 0, 1, n, 1);
    }
}

int main() {
    
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= q; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        cnt[x].push_back({y, z, i});
    }
    update(n, a[1], 1, n, 1);
    for (qu j: cnt[1]) {
        int l = n;
        int r = n;
        if (j.c >= a[1]) {
            update(n, j.c, 1, n, 1);
            ans[j.id] = query(l, r, 1, n, 1).len - 1;
            update(n, a[1], 1, n, 1);
        } else {
            ans[j.id] = query(l, r, 1, n, 1).len;
        }

    }
    dfs(1, 0, 0);
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << endl;
    }

}

