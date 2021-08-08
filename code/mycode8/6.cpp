#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 100;

struct segment {
    ll sum, ha, maxn;
}tree[40 * N];

ll fn[N], a[N], flag[40 * N];
const ll mod = 1e9 + 7;

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void build(int l, int r, int node) {
    if (l == r) {
        tree[node].sum = fn[l];
        tree[node].ha = fn[l] * a[l];
        tree[node].maxn = a[l];
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node].sum = tree[lson].sum + tree[rson].sum;
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
    tree[node].ha = (tree[lson].ha + tree[rson].ha) % mod;
}

void push_down(int node) {
    if (flag[node]) {
        tree[lson].maxn += flag[node];
        tree[rson].maxn += flag[node];
        tree[lson].ha = (tree[lson].ha + (flag[node] % mod * tree[lson].sum % mod) % mod) % mod;
        tree[rson].ha = (tree[rson].ha + (flag[node] % mod * tree[rson].sum % mod) % mod) % mod;
        flag[lson] += flag[node];
        flag[rson] += flag[node];
        flag[node] = 0; 
    }
}

void work(int l, int r, int node) {

    if (l == r) {
        tree[node].maxn = tree[node].maxn % 65536;
        tree[node].ha = tree[node].maxn * tree[node].sum % mod;
        return;
    }  
    push_down(node);
    if (tree[lson].maxn >= 65536) {
        work(l, m, lson);
    }

    if (tree[rson].maxn >= 65536) {
        work(m + 1, r, rson);
    }
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
    tree[node].ha = (tree[lson].ha + tree[rson].ha) % mod;
}

void update(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        tree[node].maxn++;
        tree[node].ha = (tree[node].ha + tree[node].sum) % mod; 
        flag[node]++;

        if (tree[node].maxn >= 65536) {
            push_down(node);
            work(l, r, node);
        }
        return;
    }
    push_down(node);
    if (ql <= m) update(ql, qr, l, m, lson);
    if (qr > m) update(ql, qr, m + 1, r, rson);
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
    tree[node].ha = (tree[lson].ha + tree[rson].ha) % mod;
}

ll query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node].ha;
    }
    ll ans = 0;
    push_down(node);
    if (ql <= m) ans = (ans + query(ql, qr, l, m, lson)) % mod;
    if (qr > m) ans = (ans + query(ql, qr, m + 1, r, rson)) % mod;
    return ans;
}


int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    fn[1] = 1; 
    for (int i = 2; i <= n + 10; i++) {
        fn[i] = fn[i - 1] * 27;
        fn[i] %= mod;
    }

    build(1, n, 1);
    while (q--) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) {
            update(l, r, 1, n, 1);
        } else {
            int x; scanf("%d", &x);
            ll ha = query(l, l + x - 1, 1, n, 1);
            ll ha1 = query(r, r + x - 1, 1, n, 1);
            if (l > r) {
                int len = l - r;
                ha1 = ha1 * fn[len + 1] % mod;
            } else {
                int len = r - l;
                ha = ha * fn[len + 1] % mod;
            }
            if (ha == ha1) {
                puts("yes");
            } else {
                puts("no");
            }
        }
    }
}