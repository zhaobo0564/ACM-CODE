#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;

int n, m, a[N];

struct hjt {
    int l, r, sum;
} tree[40 * N];

int top = 1;


void update(int pos, int v, int l, int r, int last, int &now) {
    now = top++;
    tree[now] = tree[last];
    if (l == r) {
        tree[now].sum = v;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(pos, v, l, m, tree[last].l, tree[now].l);
    else update(pos, v, m + 1, r, tree[last].r, tree[now].r);
    tree[now].sum = min(tree[tree[now].l].sum, tree[tree[now].r].sum);
}

int query(int k, int l, int r, int now) {
    if (l == r) {
        return l;
    }
    int m = (l + r) / 2;
    if (k > tree[tree[now].l].sum) {
        return query(k, l, m, tree[now].l);
    } else {
        return query(k, m + 1, r, tree[now].r);
    }
}

int rt[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = N;
    for (int i = 1; i <= n; i++) {
        update(a[i], i, 0, n, rt[i - 1], rt[i]);
    }
    for (int i = 1; i <= n; i++) {
        int l = i, r = i + m - 1;
        if (r > n) break;
        ans = min(ans, query(l, 0, n, rt[r]));
    }
    cout << ans << endl;

}

