#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
#define m  (l + r) / 2
struct segment {
    int l, r, sum;
}tree[50 * N];

int top = 1;

void up(int v, int pos, int l, int r, int &node) {
    if (!node) node = top++;
    tree[node].sum += v;
    if (l == r) {
        return;
    }
    if (pos <= m) up(v, pos, l, m, tree[node].l);
    else up(v, pos, m + 1, r, tree[node].r);
}

int query(int k, int l, int r, int node) {
    if (l == r) return l;
    if (k <= tree[tree[node].l].sum) return query(k, l, m, tree[node].l);
    return query(k - tree[tree[node].l].sum, m + 1, r, tree[node].r);
}

int n, a[N], k, q;

int main() {
    scanf("%d %d %d", &n, &q, &k);
    int maxn = 1e9 + 7, rt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i]++;
        up(1, a[i], 1, maxn, rt);
    }
    while (q--) {
        int op; scanf("%d", &op);
        if (op == 2) {
            if (tree[rt].sum < k) {
                puts("-1");
            } else {
                printf("%d\n", query(k, 1, maxn, rt) - 1);
            }
        } else {
            int x; scanf("%d", &x);
            x++;
            up(1, x, 1, maxn, rt);
        }
    }

}