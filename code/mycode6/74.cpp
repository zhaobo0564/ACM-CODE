#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 7;
typedef long long ll;

struct segment {
    ll len, lsum, rsum, msum, maxn, sum;

    segment operator +(const segment &n) {
        segment ans;
        if (this->len == 0) {
            return n;
        }
        ans.lsum = max(this->sum + n.lsum, this->lsum);
        ans.rsum = max(n.sum + this->rsum, n.rsum);
        ans.sum = this->sum + n.sum;
        ans.msum = max(this->msum, n.msum);
        ans.msum = max(ans.msum, this->rsum + n.lsum);
        ans.maxn = max(ans.lsum, ans.rsum);
        ans.maxn = max(ans.maxn, ans.msum);
        ans.maxn = max(ans.maxn , ans.sum);
        ans.len = this->len + n.len;
        return ans;

    }
}tree[4 * N];
#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1
ll a[N];

void build(int l, int r, int node) {
    if (l == r) {
        tree[node].len = 1;
        tree[node].sum = a[l];
        tree[node].maxn = tree[node].lsum = tree[node].rsum = tree[node].msum = a[l];
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];
}


void update(int v, int pos, int l, int r, int node) {
    if (l == r) {
        tree[node].sum = tree[node].maxn = tree[node].lsum = tree[node].rsum = tree[node].msum = v;
         return;
    }
    if (pos <= m) update(v, pos, l, m, lson);
    else update(v, pos, m + 1, r, rson);
    tree[node] = tree[lson] + tree[rson];
}

segment query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        // cout << "L " << l <<  " r = " << r << endl;
        // cout << "node = " << node << endl;
        // cout << tree[node].lsum << " " << tree[node].rsum << " " << tree[node].maxn << endl;
        return tree[node];
    }
    segment ans;
    ans.len =   0;
    ans.sum = ans.maxn = ans.msum = ans.lsum = ans.rsum = -1e13;
    if (ql <= m) ans = ans + query(ql, qr, l ,m, lson);
    if (qr > m) ans= ans + query(ql, qr, m + 1, r, rson);
    return ans;
}

int main() {
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    scanf("%d", &q);
    build(1, n, 1);
    while (q--) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 0) {
            update(r, l, 1, n, 1);
        } else {
            printf("%lld\n", query(l, r, 1, n, 1).maxn);
        }
    }
}

// 18
// 11 6 -13 -14 1 -6 10 -9 16 10 4 -14 -1 8 -4 6 4 10 