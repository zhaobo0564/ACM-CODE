#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef long long ll;

const ll mod = 998244353;

ll tree[4 * N], n, q, a[N], fn[N], flag[4 * N];
ll ksm(ll x, ll y) {
    ll base = 1;
    x = x % mod;
    while (y) {
        if (y & 1) {
            base = base * x;
            base %= mod;
        }
        x = x * x;
        x %= mod;
        y = y / 2;
    }
    return base;
}

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void build(int l, int r, int node) {
    flag[node] = -1;
    if (l == r) {
        tree[node] =  ksm(10, n - l);
        tree[node] %= mod;
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node] = (tree[lson] + tree[rson]) % mod;
}

void push_down(int node, int l, int r) {
    if (flag[node] != -1) {
        int r1 = n - l;
        int l1 = n - m;
        ll cnt = (fn[r1] - fn[l1 - 1] + mod) % mod;
        tree[lson] = cnt * flag[node] % mod;
        r1 = n - (m + 1);
        l1 = n - r;
        cnt = (fn[r1] - fn[l1 - 1] + mod) % mod;
        tree[rson] = cnt * flag[node] % mod;
        flag[lson] = flag[rson] = flag[node];
        flag[node] = -1;
    }
}

void update(ll v, int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        int r1 = n - l;
        int l1 = n - r;
        ll cnt = (fn[r1] - fn[l1 - 1] + mod) % mod;
        tree[node] = cnt * v;
        tree[node] %= mod;
        flag[node] = v;
        return;
    }
    push_down(node, l, r);
    if (ql <= m) update(v, ql, qr, l, m, lson);
    if (qr > m) update(v, ql, qr, m + 1, r, rson);
    tree[node] = (tree[lson] + tree[rson]) % mod;
}


int main() {
    scanf("%lld %lld", &n, &q);
    fn[0] = 1;
    for (int i = 1; i <= n; i++) {
        fn[i] = ksm(10, i);
        fn[i] = fn[i - 1] + fn[i];
        fn[i] %= mod;
    }
    build(1, n, 1);
    while (q--) {
        ll l, r, v;
        scanf("%lld %lld %lld", &l, &r, &v);
        update(v, l, r, 1, n, 1);
        printf("%lld\n", tree[1]);
    }

}