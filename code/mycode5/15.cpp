#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;

vector<pair<int, int> > g[N];
int n, q, rt[N], id[N], top = 1, cnt = 1, sizes[N];
#define m (l + r) / 2

ll deep[N], maxn;

struct hjt {
    int l, r;
    ll sum;
    ll count;
} tree[40 * N];

void update(ll pos, int last, int &now, ll l, ll r) {
    now = top++;
    tree[now] = tree[last];
    tree[now].count++;
    if (l == r) {
        tree[now].sum += l;
        return;
    }
    if (pos <= m) update(pos, tree[last].l, tree[now].l, l, m);
    else update(pos, tree[last].r, tree[now].r, m + 1, r);
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum;
}

void dfs(int u, int fa, ll dp) {
    deep[u] = dp;
    id[u] = cnt++;
    if (deep[u]) {
        update(deep[u], rt[id[u] - 1], rt[id[u]], 1, maxn);
    }
    sizes[u] = 1;
    for (auto it: g[u]) {
        int to = it.first;
        int cost= it.second;
        if (to == fa) continue;
        dfs(to, u, dp + cost);
        sizes[u] += sizes[to];
    }
}

ll query(ll v,int now, ll ql, ll qr, ll l, ll r) {
    if (ql <= l && qr >= r) {
        return tree[now].sum - 1ll * tree[now].count * v;
    }
    ll ans = 0;
    if (ql <= m) ans += query(v, tree[now].l, ql, qr, l, m);
    if(qr > m) ans += query(v, tree[now].r, ql, qr, m + 1, r);
    return ans;
}



int main() {
    maxn = 100000000000;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        g[u].push_back({i + 1, w});
        g[i + 1].push_back({u, w});
    }
    scanf("%d", &q);
    dfs(1, 0, 0);
    while (q--) {
        ll u, k;
        scanf("%lld %lld", &u, &k);
        k += deep[u];
        int l = id[u];
        int r = id[u] + sizes[u] - 1;
        ll ans = query(deep[u], rt[r], k, maxn, 1, maxn) - query(deep[u], rt[l], k, maxn,1, maxn);

        printf("%lld\n", ans);
    }
  

}

