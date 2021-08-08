#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

struct segment{
    int l, r;
    vector<int> id;
} tree[4 * N];
int n, q, fa[N], sz[N];

struct node {
    int u, v, l, r;
}Q[N];

vector<int> g;

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int find(int x) {
    if (x != fa[x]) {
        return find(fa[x]);
    }
    return x;
}

#define m (l + r >> 1)
#define lson (node << 1)
#define rson (node << 1 | 1)

void build(int l, int r, int node) {
    tree[node].l = g[l - 1];
    tree[node].r = g[r - 1];
    if (r - l == 1) {
        return;
    }
    build(l, m, lson);
    build(m, r, rson);
}

int Stack[N], top = 0;

void merge(int x, int y) {
  //  cout << "x = " << x << " y = " << y << endl; 
    int fx = find(x);
    int fy = find(y);
   // cout << "fx = " << fx << " fy = " << fy << endl;
    if (fx == fy) return;
    if (sz[fx] > sz[fy]) swap(fx, fy);
    fa[fx] = fy;
    Stack[top++] = fx;
    sz[fy] += sz[fx];
}

void del(int x) {
    while (top > x) {
        int y = Stack[top - 1];
        sz[fa[y]] -= sz[y];
        fa[y] = y;
        top--; 
    }
}

void add(int node) {
    for (int i: tree[node].id) {
        merge(Q[i].u, Q[i].v);
    }
}

void update(int v, int ql, int qr, int node) {
    if (ql <= tree[node].l && qr >= tree[node].r) {
        tree[node].id.push_back(v);
        return;
    }
    if (ql >= tree[node].r || qr <= tree[node].l) return;
    update(v, ql, qr, lson);
    update(v, ql, qr, rson);
}

int ans = 0;

void query(int l, int r, int node) {
    int cnt = top;
    add(node);
   // cout << find(1) << " " << find(n) << endl;
    if (find(1) == find(n)) {
        ans += tree[node].r - tree[node].l;
        del(cnt);
        return;
    } else if (r - l == 1) {
        del(cnt);
        return;
    }
    query(l, m, lson);
    query(m, r, rson);
    del(cnt);
}



int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= q; i++) {
        int u, v, l, r;
        scanf("%d %d %d %d", &u, &v, &l, &r);
        g.push_back(l);
        g.push_back(r + 1);
        Q[i] = {u, v, l, r};
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    build(1, g.size(), 1);
    for (int i = 1; i <= q; i++) {
        update(i, Q[i].l, Q[i].r + 1, 1);
    }
    query(1, g.size(), 1);
    cout << ans << endl;

}