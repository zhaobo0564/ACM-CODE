#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;

ll  sum[N], pre[N], a[N], k[N];

ll n, q, flag[4 * N];
const ll base = 1e15;

struct segment {
    ll value, maxn;
}tree[4 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void push_down(int node, int nl, int nr) {
    if (flag[node] != base) {
        tree[lson].maxn = flag[node];
        tree[rson].maxn = flag[node];
        tree[lson].value = flag[node] * nl;
        tree[rson].value = flag[node] * nr;
        flag[lson] = flag[rson] = flag[node];
        flag[node] = base;
    }
}

void build(int l, int r, int node) {
    flag[node] = base;
    if (l == r) {
        tree[node].value = a[l] - sum[l - 1];
        tree[node].maxn = tree[node].value;
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
    tree[node].value = tree[lson].value + tree[rson].value;
}

ll query(int pos, int l, int r, int node) {
    if (l == r) {
        return tree[node].value;
    }
    push_down(node, m - l + 1, r - m);
    if (pos <= m) return query(pos, l, m, lson);
    return query(pos, m + 1, r, rson);
}

int query_pos(ll v, int l, int r, int node) {
  //  cout << "l = " << l << " r = " << r << endl;
    if (l == r) return l;
    push_down(node, m - l + 1, r - m);
 //   cout << "v " << v  <<  " maxn " << tree[rson].maxn << endl;
    if (tree[lson].maxn >= v) {
        return query_pos(v, l, m, lson);
    } else {
        return query_pos(v, m + 1, r, rson);
    }
}

ll query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {

        return tree[node].value;
    }
    ll ans = 0;
    push_down(node, m - l + 1, r - m);
    if (ql <= m) ans += query(ql, qr, l, m, lson);
    if (qr > m) ans += query(ql, qr, m + 1, r, rson);
    return ans;
}

void update(ll v, int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        tree[node].maxn = v;
        tree[node].value = v * (r - l + 1);
        flag[node] = v;
   //     cout << "LL " << l << "r " << r << " v = " << v << endl;
        return;
    }
    push_down(node, m - l + 1, r - m);
    if (ql <= m) update(v, ql, qr, l, m, lson);
    if (qr > m) update(v, ql, qr, m + 1, r, rson);
    tree[node].maxn = max(tree[lson].maxn, tree[rson].maxn);
    tree[node].value = tree[lson].value + tree[rson].value;
}





int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%lld", &k[i]);
        sum[i] = sum[i - 1] + k[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + sum[i];
        
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] - sum[i - 1] << " ";
    // }
    // cout << endl;
    n++;
    a[n] = 1e15;
    build(1, n, 1);
    scanf("%lld", &q);
    while (q--) {
        char op;
        int l, r;
        scanf(" %c %d %d", &op, &l, &r);
        if (op == '+') {
            ll va = query(l, 1, n, 1);
            va += r;
            int pos = query_pos(va, 1, n, 1);
           // cout << "l = " << l << " r = " << pos << " va = " << va << endl;
            update(va, l, max(l, pos - 1), 1, n, 1);

        } else {
            ll cnt = query(l, r, 1, n, 1);
           // cout << "cnt = " << cnt << endl;
            ll cat = pre[r - 1] - pre[max(l - 2, 0)];
            printf("%lld\n", cnt + cat);

        }
    }

}




