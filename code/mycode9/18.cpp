#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
struct segmet {
    ll sum;
    int cnt[100];
}tree[4* N];

int id[N], sz[N], cnt = 1, cat[N];
vector<int> g[N];

void dfs(int u, int fa) {
    id[u] = cnt++;
    sz[u] = 1;
    for (int to: g[u]) {
        if (to == fa) continue;
        dfs(to, u);
        sz[u] += sz[to];
    }
}

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1
const ll mod = 1e9 + 7;

vector<int>p;

void update(int pos, ll v, int l, int r, int node) {
    //if (pos < 1) return;
    if (l == r) {
        tree[node].sum = v;
        for (int i: p) {
            tree[node].cnt[i] = 0;
        }

        for (int i: p) {
            if (v % i == 0) {
                while (v % i == 0) {
                    tree[node].cnt[i]++;
                    v = v / i;
                }
            }
            
        }
        if (v > 1) {
            tree[node].cnt[v]++;
        }
        return;
    }
    if (pos <= m) update(pos, v, l, m, lson);
    else update(pos, v, m + 1, r, rson);
    tree[node].sum = (tree[lson].sum % mod * tree[rson].sum % mod) % mod;
    for (int i: p) {
        tree[node].cnt[i] = tree[lson].cnt[i] + tree[rson].cnt[i];
    }
}

void update1(int pos, ll v, int l, int r, int node) {
    //if (pos < 1) return;
    if (l == r) {
        tree[node].sum =(tree[node].sum % mod * v % mod) % mod;


        for (int i: p) {
            if (v % i == 0) {
                while (v % i == 0) {
                    tree[node].cnt[i]++;
                    v = v / i;
                }
            }
            
        }
        if (v > 1) {
            tree[node].cnt[v]++;
        }
        return;
    }
    if (pos <= m) update1(pos, v, l, m, lson);
    else update1(pos, v, m + 1, r, rson);
    tree[node].sum = tree[lson].sum * tree[rson].sum % mod;
    for (int i: p) {
        tree[node].cnt[i] = tree[lson].cnt[i] + tree[rson].cnt[i];
    }
}

int ans[17];

ll query(int ql, int qr, int l, int r, int node) {
    //if (ql > qr || ql < 1 || qr < 1) return 1;
    if (ql <= l && qr >= r) {
        for (int i: p) {
            ans[i] += tree[node].cnt[i];
        }
        return tree[node].sum;
    }
    ll res = 1;
    if (ql <= m) res = res * query(ql, qr, l, m, lson) % mod;
    if (qr > m) res = res * query(ql, qr, m + 1, r, rson) % mod;
    return res % mod;
}

int main() {
    p.push_back(2), p.push_back(3), p.push_back(5), p.push_back(7), p.push_back(11), p.push_back(13);
    int n; scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u++, v++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        update(id[i], x, 1, n, 1);
    }
    int q; scanf("%d", &q);
    while (q--) {
        char s[20];
        scanf("%s", s);
        if (s[0] == 'R') {
            int x; scanf("%d", &x);
            x++;
            for (int i: p) {
                ans[i] = 0;
            }
            ll res = query(id[x], id[x] + sz[x] - 1, 1, n, 1);
            ll dog = 1;
            for (int i: p) {
                dog = dog * (ans[i] + 1);
                dog %= mod;
            }
            printf("%lld %lld\n", res, dog);
        } else {
            ll u, x;
            scanf("%lld %lld", &u, &x);
            u++;
           
            update1(id[u], x, 1, n, 1);
        }
    }
}

