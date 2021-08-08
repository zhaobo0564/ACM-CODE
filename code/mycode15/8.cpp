#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 7;

int a[N], b[N], n, q, c[N];

#define m (l + r >> 1)


int rt[2], top = 1, tree[40 * N], ls[40 * N], rs[40 * N];
int vis[N];

void update(int pos, int v, int l, int r, int &node) {
    if (!node) node = top++;
    if (l == r) {
        tree[node] = v;
        return;
    }
    if (pos <= m) update(pos, v, l, m, ls[node]);
    else update(pos, v, m + 1, r, rs[node]);
    tree[node] = max(tree[ls[node]], tree[rs[node]]);
}

int query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    int ans = -1e9;
    if (ql <= m) ans = max(ans, query(ql, qr, l, m, ls[node]));
    if (qr > m) ans = max(ans, query(ql, qr, m + 1, r, rs[node]));
    return ans;
}
void init() {
    for (int i = 0; i <= top; i++) {
        tree[i] = ls[i] = rs[i] = 0;
    }
    rt[0] = rt[1] = 0;
    top = 1;
    memset(vis, 0, sizeof(vis));
}

void solve() {
    init();
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    for (int i = 1; i <= q; i++) {
        int x;
        scanf("%d", &x);
        vis[x + 1]++;
    }
    for (int i = 1; i <= n + 1; i++) {
        vis[i] += vis[i - 1];
    }
    tree[0] = -1e9;
    for (int i = 1; i <= n; i++) {
        update(i, b[i] - vis[i], 1, n, rt[a[i]]);
    }
    int res = n;
    for (int i = 1; i < n; i++) {
        b[i] -= vis[i];
        int ans = query(i + 1, n, 1, n, rt[a[i] ^ 1]);
        if (ans > b[i]) {
            res--;
        }
    }
    cout << res << endl;
    
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}