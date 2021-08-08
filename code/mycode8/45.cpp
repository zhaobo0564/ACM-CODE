#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;

int n, tree[4 * N][32], a[N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void push_up(int node) {
    for (int i = 0; i <= 30; i++) {
        tree[node][i] = tree[lson][i] + tree[rson][i];
    }
}

void update(int pos, int v, int l, int r, int node) {
    if (l == r) {
        for (int i = 0; i <= 30; i++) {
            tree[node][i] = 0;
        }
        int cnt = 0;
        while (v) {
            if (v & 1) {
                tree[node][cnt]++;
            }
            cnt++;
            v = v / 2;
        }
        return;
    }
    if (pos <= m) update(pos, v, l, m, lson);
    else update(pos, v, m + 1, r, rson);
    push_up(node);
}

int ans[40];

void query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        for (int i = 0; i <= 30; i++) {
            ans[i] += tree[node][i];
        }
        return;
    }
    if (ql <= m) query(ql, qr, l, m, lson);
    if (qr > m) query(ql, qr, m + 1, r, rson);

}

ll fn[N];
const ll mod = 1e9 + 7;

int main() {

    fn[0] = 1;
    for (int i = 1; i < N; i++) {
        fn[i] = fn[i - 1] * 2;
        fn[i] %= mod;
    }

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        update(i, a[i], 1, n, 1);
    }
    int q; scanf("%d", &q);
    while (q--) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) {
            update(l, r, 1, n, 1);
        } else {
            for (int i = 0; i <= 30; i++) {
                ans[i] = 0;
            }
            query(l, r, 1, n, 1);
            ll res = 0;
            for (int i = 0; i <= 30; i++) {
                if (ans[i]) {
                    res = res + (fn[i] % mod * (fn[ans[i]] - 1 + mod) % mod) % mod;
                    res = res % mod;
                }
            }
            printf("%lld\n", res);
        }
    }

}