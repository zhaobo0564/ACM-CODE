#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int N = 3e5 + 7;
vector<pair<ll, ll> > g[N], g1[N];

int n, m;


int dep[N], fa[N], sz[N], son[N], top[N];
ll dist[N];

void dfs(int u, int f) {
    sz[u] = 1;
    fa[u] = f;
    dep[u] = dep[f] + 1;
    for (auto it: g[u]) {
        ll to = it.first;
        ll w = it.second;
        if (to == f) continue;
        dist[to] = dist[u] + w;
        dfs(to, u);
        sz[u] += sz[to];
        if (sz[son[u]] < sz[to]) {
            son[u] = to;
        } 
    }
}

void dfs1(int u, int f, int up) {
    top[u] = up;
    if (son[u]) dfs1(son[u], u, up);
    for (auto it: g[u]) {
        ll to = it.first;
        if (to == f || to == son[u]) continue;
        dfs1(to, u, to);
    }
}

int get_lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            swap(x, y);
        }
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) return y;
    return x;
}


ll get_dist(int x, int y) {
    int lca = get_lca(x, y);
    return dist[x] + dist[y] - 2 * dist[lca];
}

ll dist1[N];

int fa1[N];

ll node , mx, node1;

void dfs_node(int u, int f, ll deep) {
    if (mx < deep) {
        mx = deep;
        node = u;
    }
    for (auto it: g[u]) {
        int to = it.first;
        ll cost = it.second;
        if (to == f) continue;
        dfs_node(to, u, deep + cost);
    }
}

void dfs2(int u, int f) {
    fa1[u] = f;
    for (auto it: g1[u]) {
        ll to = it.first;
        ll w = it.second;
        if (to == f) continue;
        dist1[to] = dist1[u] + w;
        dfs2(to, u);
    }
}

vector<int> dog;

void update(int u, int f, ll v) {
    dog.push_back(u);
    //dist[u + n] += v;
    for (auto it: g1[u]) {
        int to = it.first;
        if (to == f) continue;
        update(to, u, v);
    }
}

int32_t main() {
    scanf("%lld %lld", &n, &m);

    for (int i = 1; i < n; i++) {
       ll u, v, w;
       scanf("%lld %lld %lld", &u, &v, &w);
       g[u].push_back({v, w});
       g[v].push_back({u, w});
    }
    for (int i = 1; i < n; i++) {
        ll u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        g1[u].push_back({v, w});
        g1[v].push_back({u, w});
    }
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        g[i].push_back({i + n, dist1[i]});
        g[i + n].push_back({i, dist1[i]});
    }
    dfs(1, 0);
    dfs1(1, 0, 1);
    mx = -1;
    dfs_node(1, 0, 0);
    node1 = node;
    mx = -1;
    dfs_node(node1, 0, 0);
    ll ans = mx;
    printf("%lld\n", mx);
    while (m--) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        dog.clear();
        update(x, fa1[x], y);
        for (int i: dog) {
            x = i;
            dist[x+ n] += y; 
            ll cn = get_dist(node, x + n);
            ll cnt = get_dist(node1, x + n);
            ll D = max(cn, cnt);

            if (cn > cnt) {
                if (cn > ans) {
                    node1 = x + n;
                    ans = cn;
                } 
            } else {
                if (cnt > ans) {
                    node = x + n;
                    ans = cnt;
                }
            }
        }
        printf("%lld\n", ans);
    }
}