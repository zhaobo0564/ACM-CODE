#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

typedef long long ll;

ll n, q, a[N];

ll read() {
    ll x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return x;
}

struct segment {
    ll odd, even;
    segment() {
        odd = even = 0;
    }
} tree[4 * N];

int dep[N], son[N], sz[N], fa[N], top[N];
int id[N], cat[N], o = 1;

vector<int> g[N];

void dfs(int u, int f) {

    sz[u] = 1;
    dep[u] = dep[f] + 1;
    fa[u] = f;
    for (int to: g[u]) {
        if (to == f) continue;
        dfs(to, u);
        sz[u] += sz[to];
        if (sz[son[u]] < sz[to]) {
            son[u] = to;
        }
    }
}

void dfs1(int u, int up) {
    id[u] = o++;
    cat[o - 1] = u;
    top[u] = up;
    if (son[u]) dfs1(son[u], up);
    for (int to: g[u]) {
        if (to == fa[u] || to == son[u]) continue;
        dfs1(to, to);
    }
}

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void build(int l, int r, int node) {
    if (l == r) {
        if (dep[cat[l]] % 2) {
            tree[node].odd = a[cat[l]];
            tree[node].even = 0;
        } else {
            tree[node].even = a[cat[l]];
            tree[node].odd = 0;
        }
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node].even = tree[lson].even ^ tree[rson].even;
    tree[node].odd = tree[lson].odd ^ tree[rson].odd;
}

void update(int pos, ll v, int l, int r, int node) {
    if (l == r) {
        if (dep[cat[l]] % 2) {
            tree[node].odd = v;
            tree[node].even - 0;
        } else {
            tree[node].even = v;
            tree[node].odd =0;
        }
        return;
    }
    if (pos <= m) update(pos, v, l, m, lson);
    else update(pos, v, m + 1, r, rson);
    tree[node].even = tree[lson].even ^ tree[rson].even;
    tree[node].odd = tree[lson].odd ^ tree[rson].odd;
}

segment merge(segment x, segment y) {
    segment ans;
    ans.even = x.even ^ y.even;
    ans.odd = x.odd ^ y.odd;
    return ans;
}

segment query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    segment ans;
    if (ql <= m) ans = merge(ans, query(ql, qr, l, m, lson));
    if (qr > m) ans = merge(ans, query(ql, qr, m + 1, r, rson));
    return ans;
}

segment qu(int x, int y) {
    segment ans;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) { 
            swap(x, y);
        }
        ans = merge(ans, query(id[top[x]], id[x], 1, n, 1));
        x = fa[top[x]];     
    }
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    ans = merge(ans, query(id[y], id[x], 1, n, 1));
    return ans;
}
  
int get_lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            swap(x, y);
        }
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    return x;
}

int dist(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[get_lca(x, y)];
}

int main() {
     n = read(), q = read();
     for (int i = 1; i <= n; i++) {
         a[i] = read();
     }
     for (int i = 1; i < n; i++) {
        int u, v;
        u = read(), v = read();
        g[u].push_back(v);
        g[v].push_back(u);
     }
     dfs(1, 0);
     dfs1(1, 1);
     build(1, n, 1);
     while (q--) {
         ll op, u, v;
         op = read(), u = read(), v = read();
         if (op == 1) {
             update(id[u], v, 1, n, 1);
         } else {
             segment ans = qu(u, v);
             int len = dist(u, v);
             if (len % 2) {
                printf("%lld\n", ans.even ^ ans.odd);
             } else {
                 if (dep[u] % 2) {
                     printf("%lld\n", ans.even);
                 } else {
                     printf("%lld\n", ans.odd);
                 }
             }
         }
     }

 } 