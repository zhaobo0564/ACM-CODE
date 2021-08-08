#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct segment {
    int l, r;
} tree[4 * N];
int n, q;

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void updatel(int pos, int l, int r , int node) {
    if (l == r) {
        tree[node].l += 1;
        return;
    }
    if (pos <= m) updatel(pos, l, m, lson);
    else updatel(pos, m + 1, r, rson);
    tree[node].l = tree[lson].l + tree[rson].r;
}

void updater(int pos, int l, int r, int node) {
    if (l == r) {
        tree[node].r += 1;
        return;
    }
    if (pos <= m) updater(pos, l, m, lson);
    else updater(pos, m + 1, r, rson);
    tree[node].r = tree[rson].r + tree[lson].r;
}

int queryl(int ql, int qr, int l, int r, int node) {
    if (ql > qr) return 0;
    if (ql <= l && qr >= r) {
        return tree[node].l;
    }
    int ans = 0;
    if (ql <= m) ans += queryl(ql, qr, l, m, lson);
    if (qr > m) ans += queryl(ql, qr, m + 1, r, rson);
    return ans;

}

int queryr(int ql, int qr, int l, int r, int node) {
    if (qr < ql) return 0;
    if (ql <= l && qr >= r) {
        return tree[node].r;
    }
    int ans = 0;
    if (ql <= m) ans += queryr(ql, qr, l, m, lson);
    if (qr > m) ans += queryr(ql, qr, m + 1, r, rson);
    return ans;

}

map<int, int>vis[N];


int main() {
    scanf("%d %d", &n, &q);
    while (q--) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) {
            updatel(l, 1, n, 1);
            updater(r, 1, n, 1);
            vis[l][r]++;
        } else {
            int ans = 0;
            for (int i = l; i <= r; i++) {
                for (int j = i; j <= r; j++) {
                    ans += vis[i][j];
                }
            }
            int cat = queryl(1, l - 1, 1, n, 1) - queryr(1, l - 1, 1, n, 1);

            int cn = queryr(l, r, 1, n, 1) - ans;
            printf("%d\n", cat - cn + vis[l][r]);


        }
    }
}