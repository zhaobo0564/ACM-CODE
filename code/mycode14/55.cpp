#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;

int a[N], fa[N], tree[40 * N], ls[40 * N], rs[40 * N], n, q;

#define m (l + r >> 1)

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

int rt[N], top = 1, cat[N];

void update(int pos, int l, int r, int &node) {
    if (!node) node = top++;
    tree[node]++;
    if (l == r) return;
    if (pos <= m) update(pos, l, m, ls[node]);
    else update(pos, m + 1, r, rs[node]); 
}

int merge(int x, int y, int l, int r) {
    if (!x) return y;
    if (!y) return x;
    if (l == r) {
        tree[x] += tree[y];
        return x;
    }
    ls[x] = merge(ls[x], ls[y], l, m);
    rs[x] = merge(rs[x], rs[y], m + 1, r);
    tree[x] = tree[ls[x]] + tree[rs[x]];
    return x;
}


int query(int k, int l, int r, int node) {
    if (l == r) return cat[l];
    if (k <= tree[ls[node]]) return query(k, l, m, ls[node]);
    return query(k - tree[ls[node]], m + 1, r, rs[node]);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cat[a[i]] = i;
        fa[i] = i;
        update(a[i], 1, n, rt[i]);
    }
    for (int i = 1; i <= q; i++) {
        int u, v; scanf("%d %d", &u, &v);
        int fx = find(u);
        int fy = find(v);
        if (fx == fy) continue;
        fa[fx] = fy;
        rt[fy] = merge(rt[fy], rt[fx], 1, n);
    }
    scanf("%d", &q);
    while (q--) {
        char op;
        int x, y;
        scanf(" %c %d %d", &op, &x, &y);
        if (op == 'Q') {
            int fx = find(x);
            if (y > tree[rt[fx]]) {
                puts("-1");
            } else {
                printf("%d\n", query(y, 1, n, rt[fx]));
            }
        } else {
            int fx = find(x);
            int fy = find(y);
            if (fx == fy) continue;
            fa[fx] = fy;
            rt[fy] = merge(rt[fy], rt[fx], 1, n);
        }
    }

}