#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;
typedef long long ll;
vector<ll> v;
vector<pair<ll, ll> > g[N];

ll dist[N], tree[30 * N];
int ls[30 * N], rs[30 * N], sum[30 * N];

#define m (l + r) / 2
#define lson ls[node]
#define rson rs[node]
int get_id(ll x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
int top = 1;
void update(ll v, ll pos, ll  l, ll r, int &node) {
    if (!node) node = top++;
    sum[node]++;
    if (l == r) {
        tree[node] += v;
        return;
    }
    if (pos <= m) update(v, pos, l, m, lson);
    else update(v, pos, m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];
}

ll query(ll ql, ll qr, ll l, ll r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node];
    }
    ll ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, lson);
    if (qr > m) ans += query(ql, qr, m + 1, r, rson);
    return ans;  
}

ll qu(ll ql, ll qr, ll l, ll r, int node) {
    if (ql <= l && qr >= r) {
        return sum[node];
    }
    ll ans = 0;
    if (ql <= m) ans += qu(ql, qr, l, m, lson);
    if (qr > m) ans += qu(ql, qr, m + 1, r, rson);
    return ans;  
}


int merge(int x, int y, ll l, ll r) {
    if (!x) return y;
    if (!y) return x;
    if (l == r) {
        tree[x] += tree[y];
        sum[x] += sum[y];
        return x;
    }
    ls[x] = merge(ls[x], ls[y], l, m);
    rs[x] = merge(rs[x], rs[y], m + 1, r);
    tree[x] = tree[ls[x]] + tree[rs[x]];
    sum[x] = sum[ls[x]] + sum[rs[x]];
    return x; 
}

void dfs(int u, int fa) {
    for (auto it: g[u]) {
        int to = it.first;
        ll w = it.second;
        if (to == fa) continue;
        dist[to] = dist[u] + w;
        dfs(to, u);
    }
}

ll maxn = 1e12, ans[N];

struct que{
    int k, id;
};

vector<que> Q[N];

int rt[N];

void dfs1(int u, int fa) {
    update(dist[u], get_id(dist[u]), 0, maxn, rt[u]);
    for (auto it: g[u]) {
        int to = it.first; 
        ll w = it.second;
        if (to == fa) continue;
        dfs1(to, u);
        rt[u] = merge(rt[u], rt[to], 0, maxn);
    }

    for (auto it: Q[u]) {
        ans[it.id] = query(get_id(dist[u] + it.k), maxn, 0, maxn, rt[u]) ;
        ans[it.id] -= dist[u] * qu(get_id(dist[u] + it.k), maxn, 0, maxn, rt[u]);
    }

}






int main() {
    int n, q;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p, w; scanf("%d %d", &p, &w);
        g[p].push_back({i, w});
        g[i].push_back({p, w});
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int u, k; scanf("%d %d", &u, &k);
        Q[u].push_back({k, i});
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        v.push_back(dist[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    maxn = v.size();
    dfs1(1, 0);
    for (int i = 1; i <= q; i++) {
        printf("%lld\n", ans[i]);
    }

}

