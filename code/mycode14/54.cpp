#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
const ll mod = 998244353;
int a[N], n, sz[N], maxn[N], mx, vis[N];
vector<int> g[N], G;

int get_id(int x) {
    return lower_bound(G.begin(), G.end(), x) - G.begin() + 1;
}

void get_rt(int u, int fa, int &rt) {
    maxn[u] = 0;
    sz[u] = 1;
    for (int to: g[u]) {
        if (to == fa || vis[to]) continue;
        get_rt(to, u, rt);
        sz[u] += sz[to];
        maxn[u] = max(maxn[u], sz[to]);
    }
    maxn[u] = max(maxn[u], n - sz[u]);
    if (mx > maxn[u]) {
        mx = maxn[u];
        rt = u;
    }
}

#define m (l + r >> 1)


struct segment {
    ll count, sum, all, va;
} tree[40 * N];

int ls[40 * N], rs[40 * N], top = 1, rt;

void update(int v, int pos, int l, int r, int &node) {
    if (!node) node = top++;
    tree[node].count++;
    if (l == r) {
        tree[node].sum += 1ll * v;
        if (tree[node].sum >= mod) tree[node].sum %= mod;
        tree[node].all += 1ll * v * 1ll * G[pos - 1] % mod;
        if (tree[node].all >= mod) tree[node].all %= mod;
        tree[node].va += 1ll * G[pos - 1];
        if (tree[node].va >= mod) tree[node].va %= mod;
        return;        
    }
    if (pos <= m) update(v, pos, l, m, ls[node]);
    else update(v, pos, m + 1, r, rs[node]);
    tree[node].sum = (tree[ls[node]].sum + tree[rs[node]].sum);
    if (tree[node].sum >= mod) tree[node].sum %= mod;
    tree[node].all = (tree[ls[node]].all + tree[rs[node]].all);
    if (tree[node].all >= mod) tree[node].all %= mod;
    tree[node].va = (tree[ls[node]].va + tree[rs[node]].va);
    if (tree[node].va >= mod) tree[node].va %= mod;
}

ll sum = 0, cnt = 0, all = 0, va = 0;

void query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        sum += tree[node].sum;
        if (sum >= mod) sum %= mod;
        cnt += tree[node].count;
        all += tree[node].all;
        if (all >= mod) all % mod;
        va += tree[node].va;
        if (va >= mod) va %= mod;
        return;
    }
    if (ql <= m) query(ql, qr, l, m, ls[node]);
    if (qr > m) query(ql, qr, m + 1, r, rs[node]);
}

vector<pair<ll, ll> > cat;

void dfs(int u, int fa, int deep) {
    cat.push_back({a[u], deep});
    for (int to: g[u]) {
        if (to == fa || vis[to]) continue;
        dfs(to, u, deep + 1);
    }
}

ll ans = 0;

void cal(int u) {
    for (auto it: cat) {
        sum = 0, cnt = 0, all = 0, va = 0;
        ll value = G[it.first - 1];
        ll dep = it.second;
        query(it.first, G.size(), 1, G.size(), rt);
        ans = (ans + sum * value % mod);
        if (ans >= mod) ans %= mod;
        ans = ans + ((cnt * dep % mod) * value % mod) % mod;
        all = (tree[rt].all - all + mod) % mod;
        ans = (ans + all) % mod;
        va = (tree[rt].va - va + mod) % mod;
        ans = (ans + va * dep % mod) % mod;
        ans += min(1ll * G[a[u] - 1], value) * dep;
        ans %= mod;
    }
    for (auto it: cat) {
        update(it.second, it.first, 1, G.size(), rt);
    }
    cat.clear();
}

void work(int u) {
    for (int to: g[u]) {
        if (vis[to]) continue;
        dfs(to, u, 1);
        cal(u);
    }
    for (int i = 0; i <= top; i++) {
        ls[i] = rs[i] = 0;
        tree[i].count = tree[i].sum = 0; 
        tree[i].all = tree[i].va = 0;
    }
    rt = 0, top = 1;
}

void gao(int u) {
    mx = 0;
    get_rt(u, 0, u);
    mx = 1e8;
    n = sz[u];
    get_rt(u, 0, u);
    vis[u] = 1;
    work(u);
    for (int to: g[u]) {
        if (vis[to]) continue;
        gao(to);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        G.push_back(a[i]);
    }
    sort(G.begin(), G.end());
    G.erase(unique(G.begin(), G.end()), G.end());
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    gao(1);
    printf("%lld\n", (ans + ans) % mod);
}