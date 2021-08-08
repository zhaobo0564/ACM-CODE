#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;
int top = 1, n, vis[N];

struct hjt{
    int l, r, sum;
}tree[150 * N];
int a[N];
#define m (l + r) / 2

void update(int v, int pos, int last, int &now, int l, int r) {
    now = top++;
    tree[now] = tree[last];
    if (l == r) {
        tree[now].sum += v;
        return;
    }
    if (pos <= m) update(v, pos, tree[last].l, tree[now].l, l, m);
    else update(v, pos, tree[last].r, tree[now].r, m + 1, r);
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum;
}

int query(int ql, int qr, int now, int l, int r) {
    if (ql  <= l && qr >= r) {
        return tree[now].sum;
    }
    int ans = 0;
    if (ql <= m) ans += query(ql, qr, tree[now].l, l, m);
    if (qr > m) ans += query(ql, qr, tree[now].r, m + 1, r);
    return ans;
}
int rt[N];

int main() {
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[a[i]] == 0) {
            update(1, i, rt[i - 1], rt[i], 1, n);
        } else {
            update(-1, vis[a[i]], rt[i - 1], rt[i], 1, n);
            update(1, i, rt[i], rt[i], 1, n);

        }
        vis[a[i]] = i;
    }
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", query(l, r, rt[r], 1, n));
    }

}