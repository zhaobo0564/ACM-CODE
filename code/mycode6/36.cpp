#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int n, like[N], cnt[N];

int sum[4 * N], sum1[4 * N];
#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void update(int v, int pos, int l, int r, int node) {
    if (l == r) {
        sum[node] += v;
        return;
    }
    if (pos <= m) update(v, pos, l, m, lson);
    else update(v, pos, m + 1, r, rson);
    sum[node] = sum[lson] + sum[rson];
}

void update1(int v, int pos, int l, int r, int node) {
    if (l == r) {
        sum1[node] += v;
        return;
    }
    if (pos <= m) update1(v, pos, l, m, lson);
    else update1(v, pos, m + 1, r, rson);
    sum1[node] = sum1[lson] + sum1[rson];
}

int query(int ql, int qr, int l, int r, int node) {
    if (ql > qr) return 0;
    if (ql <= l && qr >= r) {
        return sum[node];
    }
    int ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, lson);
    if (qr > m) ans += query(ql, qr, m + 1, r, rson);
    return ans;

}

int query1(int ql, int qr, int l, int r, int node) {
    if (ql > qr) return 0;
      if (ql <= l && qr >= r) {
        return sum1[node];
    }
    int ans = 0;
    if (ql <= m) ans += query1(ql, qr, l, m, lson);
    if (qr > m) ans += query1(ql, qr, m + 1, r, rson);
    return ans;
}


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
      //  girl[i] = u;
        like[i] = v;
        cnt[u] = i;
    }

    for (int i = 1; i <= n; i++) {
        update(1, cnt[like[i]], 1, n, 1);
    }
    for (int i = 1; i <= n; i++) {
        update(-1, cnt[like[i]], 1, n, 1);
       // cout << "l " << 1 << " r = " << cnt[like[i]] << endl;
        int ans = query(1, cnt[like[i]], 1, n, 1);
        //cout << "ans = " << ans << endl;
        ans += query1(cnt[like[i]], n, 1, n, 1);
        //cout << "ans1 = " << query1(cnt[like[i]], n, 1, n, 1) << endl;
        update1(1, cnt[like[i]], 1, n, 1);
        printf("%d\n", ans);
    }

}