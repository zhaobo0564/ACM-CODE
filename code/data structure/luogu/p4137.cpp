#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

struct segment {
    int l, r, sum;
} tree[40 * N];

int top = 1;
#define m  (l + r) / 2

void build(int l, int r, int &now) {
    now = top++;
    if (l == r) {
        tree[now].sum = 0;
        return;
    }
    build(l, m, tree[now].l);
    build(m + 1, r, tree[now].r);
    tree[now].sum = min(tree[tree[now].l].sum, tree[tree[now].r].sum);
}

void update(int v, int pos, int l, int r, int last, int &now) {
    now = top++;
    tree[now] = tree[last];
    if (l == r) {
        tree[now].sum = v;
        return;
    }
    if (pos <= m) {
        update(v, pos, l, m, tree[last].l, tree[now].l);
    } else {
        update(v, pos, m + 1, r, tree[last].r, tree[now].r);
    }
    tree[now].sum = min(tree[tree[now].l].sum, tree[tree[now].r].sum);
}

int query(int v, int now, int l, int r) {
    if (l == r) {
        return l;
    }

    if (tree[tree[now].l].sum < v) {
        return query(v, tree[now].l, l, m);
    } else {
        return query(v, tree[now].r, m + 1, r);
    }
}
int a[N], n, q, rt[N];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    build(0, n, rt[0]);
    for (int i = 1; i <= n; i++) {
        if (a[i] <= n) {
            update(i, a[i], 0, n, rt[i - 1], rt[i]);
        } else {
            rt[i] = rt[i - 1];
        }
    }
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", query(l, rt[r], 0, n));
    }
}