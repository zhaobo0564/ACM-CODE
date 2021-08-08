#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
typedef long long ll;
vector<int> g[N];

struct segment {
    ll l, r, ans;
} tree[40 * N];

int ls[40 * N], rs[40 * N];

int n;

#define m (l + r) / 2
#define lson ls[node]
#define rson rs[node]

int top = 1;

segment push_up(segment x, segment y) {
    if (x.l == 0) return y;
    if (y.l == 0) return x;
    segment z;
    z.l = x.l;
    z.r = y.r;
    z.ans = x.ans + y.ans + (x.r - y.l) * (x.r - y.l);
    return z;
}

void update(int pos, int l, int r, int &node) {
    if (!node) node = top++;
    if (l == r) {
        tree[node].l = tree[node].r = l;
        tree[node].ans = 0;
        return;
    }
    if (pos <= m) update(pos, l, m, lson);
    else update(pos, m + 1, r, rson);
    tree[node] = push_up(tree[lson], tree[rson]);

}

int merge(int x, int y, int l, int r) {
    if (!x) return y;
    if (!y) return x;
    if (l == r) {
        return x;
    }
    ls[x] = merge(ls[x], ls[y], l, m);
    rs[x] = merge(rs[x], rs[y], m + 1, r);
    tree[x] = push_up(tree[ls[x]], tree[rs[x]]);
    return x;
}

ll ans[N];
int rt[N];

void dfs(int u) {
    update(u, 1, n, rt[u]);
    for (int to: g[u]) {
        dfs(to);
        rt[u] = merge(rt[u], rt[to], 1, n);
    }
    ans[u] = tree[rt[u]].ans;
}

int main() {
    scanf("%d", &n);
    for (int i =  2; i <= n; i++) {
        int u; scanf("%d", &u);
        g[u].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", ans[i]);
    }
}