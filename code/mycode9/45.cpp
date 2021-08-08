#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
#define int long long
int a[N], n, q;

#define m (l + r) / 2
struct segment {
    int l, r, sum;
}tree[50 * N];

int top = 1;
void update (int v, int pos, int l, int r, int &node) {
    if (!node) node = top++;
    if (l == r) {
        tree[node].sum = min(tree[node].sum, v);
        return;
    } 
    if (pos <= m) update(v, pos, l, m, tree[node].l);
    else update (v, pos, m + 1, r, tree[node].r);
    tree[node].sum = min(tree[tree[node].l].sum, tree[tree[node].r].sum);
}

int query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        return tree[node].sum;
    }
    int ans = 1e8;
    if (ql <= m) ans = min(ans, query(ql, qr, l, m, tree[node].l));
    if (qr > m) ans = min(ans, query(ql, qr, m + 1, r, tree[node].r));
    return ans;
}


int32_t main() {
    for (int i = 0; i < 40 * N; i++) {
        tree[i].sum = 1e8;
        tree[i].l = tree[i].r = 0;
    }
    scanf("%lld %lld", &n, &q);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        mx = max(mx, a[i]);
    }
    int maxn = 1e10, rt = 0;

    for (int i = 1; i <= n; i++) {
        int cnt = 1, ans = a[i];
        if (a[i] > mx)
            update(cnt, a[i], 1, maxn, rt);
        for (int j = i + 1; j <= n; j++) {
            cnt++;
            ans = ans ^ a[j];
            if (ans > mx)
                update(cnt, ans, 1, maxn, rt);
        }
    }
   // cout <<"mx = " <<mx << endl;

    while (q--) {
        int x; scanf("%lld", &x);
        if (x <= mx) {
            puts("1");
            continue;
        }
        int ans = query(x, maxn, 1, maxn, rt);
        if (ans > n) {
            ans = -1;
        }
        printf("%lld\n", ans);
    }







    


}