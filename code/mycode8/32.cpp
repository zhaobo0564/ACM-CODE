#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 7;

ll n, a[N], q, sum[N], d;

#define m (l + r) / 2


struct hjt {
    ll sum, count;
    int  l, r;
}tree[40 * N];

int rt[N], top = 1;

void update(int pos, int last, int &now, int l, int r) {
    now = top++;
    tree[now] = tree[last];
    tree[now].count++;
    if (l == r) {
        tree[now].sum += l;
        return;
    }
    if (pos <= m) update(pos, tree[last].l, tree[now].l, l, m);
    else update(pos, tree[last].r, tree[now].r, m + 1, r);
    tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum;
}

ll query(int ql, int qr, int l, int r, int now) {

    if (ql <= l && qr >= r) {
        return tree[now].sum;
    }
    ll ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, tree[now].l);
    if (qr > m) ans += query(ql, qr, m + 1, r, tree[now].r);
    return ans;
}

ll queryc(int ql, int qr, int l, int r, int now) {

    if (ql <= l && qr >= r) {
        return tree[now].count;
    }
    ll ans = 0;
    if (ql <= m) ans += queryc(ql, qr, l, m, tree[now].l);
    if (qr > m) ans += queryc(ql, qr, m + 1, r, tree[now].r);
    return ans;
}



int main() {

    cin >> n >> d >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        a[i] = upper_bound(sum, sum + n + 1, sum[i] - d) - sum;
    }

    for (int i = 1; i <= n; i++) {
        update(a[i], rt[i - 1], rt[i], 0, n);
    }

    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", query(l, r, 0, n, rt[r]) - queryc(l, r, 0, n, rt[r]) * 1ll*(l - 1));
    }

}