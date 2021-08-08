#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

struct segment {
    double sinx, cosx;
} tree[4 * N];

#define lson 2 * node
#define rson 2 * node + 1
#define m (l + r) / 2
#define int long long

int a[N], q, n;

int flag[4 * N];

void build(int l, int r, int node) {
    if (l == r) {
        tree[node].cosx = cos((double)a[l]);
        tree[node].sinx = sin((double)a[l]);
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node].cosx = tree[lson].cosx + tree[rson].cosx;
    tree[node].sinx = tree[lson].sinx + tree[rson].sinx;   
}

void push_up(int node) {
    if (flag[node]) {
        double lp = tree[lson].sinx, rp = tree[rson].sinx;
        tree[lson].sinx = tree[lson].sinx * cos((double) flag[node]) + tree[lson].cosx * sin((double)flag[node]);
        tree[rson].sinx = tree[rson].sinx * cos((double) flag[node]) + tree[rson].cosx * sin((double)flag[node]);
        tree[lson].cosx = tree[lson].cosx * cos((double)flag[node]) - lp * sin((double)flag[node]);
        tree[rson].cosx = tree[rson].cosx *  cos((double)flag[node]) - rp * sin((double)flag[node]);
        flag[lson] += flag[node];
        flag[rson] += flag[node];
        flag[node] = 0;
    }
}

void update(int v, int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        double temp = tree[node].sinx;
        tree[node].sinx = tree[node].sinx * cos((double)v) + tree[node].cosx * sin((double)v);
        tree[node].cosx = tree[node].cosx * cos((double)v) - temp * sin((double(v)));
        flag[node] += v;
        return;
    }
    push_up(node);
    if (ql <= m) update(v, ql, qr, l, m, lson);
    if (qr > m) update(v, ql, qr, m + 1, r, rson);
    tree[node].cosx = tree[lson].cosx + tree[rson].cosx;
    tree[node].sinx = tree[lson].sinx + tree[rson].sinx; 

}

double query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node].sinx;
    }
    double ans = 0.0;
    push_up(node);
    if (ql <= m) ans += query(ql, qr, l, m, lson);
    if (qr > m) ans += query(ql, qr, m + 1, r, rson);
    return ans;
}

int32_t main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    build(1, n, 1);
    scanf("%lld", &q);
    while (q--) {
        int op;
        scanf("%lld", &op);
        if (op == 2) {
            int l, r;
            scanf("%lld %lld", &l, &r);
            printf("%.1lf\n", query(l, r, 1, n, 1)); 
        } else {
            int l, r, v;
            scanf("%lld %lld %lld", &l, &r, &v);
            update(v, l, r, 1, n, 1);
        }
    
    }
}