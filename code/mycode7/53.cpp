#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 7;

struct hjt {
    int l, r, sum;
}tree[40 * N];

int top = 1;

#define m (l + r) / 2

void update(int pos, int v, int l, int r, int last, int &now) {
    now = top++;
    tree[now] = tree[last];
    if (l == r) {
        tree[now].sum = v;
        return;
    }
    if (pos <= m) update(pos, v, l, m, tree[last].l, tree[now].l);
    else update(pos, v, m + 1, r, tree[last].r, tree[now].r);
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum;
}

int query(int ql, int qr, int l, int r, int now) {
    if (ql <= l && qr >= r) {
        return tree[now].sum;
    }
    int ans = 0;
    if (ql <= m) ans += query(ql,qr, l, m, tree[now].l);
    if (qr > m) ans += query(ql, qr, m + 1, r, tree[now].r);
    return ans;
}

int a[N], n, t, q, vis[N], rt[N];

int main() {
    scanf("%d", &t);
    int ca = 1;
    while (t--) {
        scanf("%d %d", &n, &q);
        memset(vis, 0, sizeof(vis));
        top = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        
        for (int i = 1; i <= n; i++) {
            if (vis[a[i]] == 0) {
                update(i, 1, 1, n, rt[i - 1], rt[i]);
            } else {
                int temp;
                update(vis[a[i]], 0, 1, n, rt[i - 1], temp);
                update(i, 1, 1, n, temp, rt[i]);
            }
            vis[a[i]] = i;
        }
        printf("Case %d:\n", ca++);
        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", query(l, r, 1, n, rt[r]));
        }
    }
}
