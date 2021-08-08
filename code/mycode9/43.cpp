#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
#define int long long

int a[N], n, q;

int maxn[4 * N];
#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void build(int l, int r, int node) {
    if (l == r) {
        maxn[node] = a[l];
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    maxn[node] = max(maxn[lson], maxn[rson]);
}

void update(int v, int pos, int l, int r, int node) {
    if (l ==  r) {
        maxn[node] = v;
        return;
    }
    if (pos <= m) update(v, pos, l, m, lson);
    else update(v, pos, m + 1, r, rson);
    maxn[node] = max(maxn[lson], maxn[rson]);
}

int query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return maxn[node];
    }
    int ans = -1;
    if (ql <= m) ans = max(ans, query(ql, qr, l, m, lson));
    if (qr > m) ans = max(ans, query(ql, qr, m + 1, r, rson));
    return ans;
}

struct segment {
    int l, r, sum;
}tree[50 * N];

int top = 1;
map<int,int> rt;

void up(int v, int pos, int l, int r, int &node) {
    if (!node) node = top++;
    tree[node].sum += v;
    if (l == r) {
        return;
    }
    if (pos <= m) up(v, pos, l, m, tree[node].l);
    else up(v, pos, m + 1, r, tree[node].r);
}

int qu(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node].sum;
    }
    int ans = 0;
    if (ql <= m) ans += qu(ql, qr, l, m, tree[node].l);
    if (qr > m) ans += qu(ql, qr, m + 1, r, tree[node].r);
    return ans;
}

int32_t main() {
    scanf("%lld %lld", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        up(1, i, 1, n, rt[a[i]]);
    }
    build(1, n, 1);

    while (q--) {
        char op[10];
        scanf("%s", op);
        if (op[0] == 'A') {
            int l, r;
            scanf("%lld %lld", &l, &r);
            int mx = query(l, r, 1, n, 1);
            int cnt = qu(l, r, 1, n, rt[mx]);
            printf("%lld %lld\n",mx, cnt);
        } else  {
            int l, r; scanf("%lld %lld", &l, &r);
            int mx = query(l, l, 1, n, 1);
            update(r, l, 1, n, 1);
            up(-1, l, 1, n, rt[mx]);
            up(1, l, 1, n, rt[r]);

        }
    }
    

}