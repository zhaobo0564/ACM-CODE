#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10, N = 1024 * 1025;
int cnt[N], a[maxn], b[maxn], block;
ll ans[maxn];
struct node {
    int id, l, r, t;
    bool operator<(const node &tmp) const {
        if (l / block != tmp.l / block)
            return l < tmp.l;
        else if (r / block != tmp.r / block)
            return r < tmp.r;
        return t < tmp.t;
    }
} q[maxn];
struct node2 {
    int pos, t, pre, val;
} d[maxn];
int gao(int x, int opt) {
    cnt[x] += opt;
    if (opt == 1)
        return cnt[x] - 1;
    return cnt[x];
}
int main() {
    int n, m, opt, l, r;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i <= 1024 * 1024; i++)
            cnt[i] = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), b[i] = b[i - 1] ^ a[i];
        int time = 0, ID = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d", &opt);
            if (opt == 1) {
                scanf("%d%d", &l, &r);
                ++ID; --l;
                q[ID] = node{ID, l, r, time};
            }
            else {
                scanf("%d", &l);
                int pre = b[l];
                int val = b[l - 1]  ^ a[l + 1];
                ++time;
                d[time] = node2{l, time, pre, val};
                swap(a[l], a[l + 1]);
                b[l] = val;
            }
        }
        block = pow(n, 2.0 / 3) + 1;
        sort(q + 1, q + 1 + ID);
        l = 1, r = 0;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
        cout << d[time].val << endl;
        for (int i = 1; i <= ID; i++) {
            while (l < q[i].l)
                sum -= gao(b[l++], -1);
            while (l > q[i].l)
                sum += gao(b[--l], 1);
            while (r < q[i].r)
                sum += gao(b[++r], 1);
            while (r > q[i].r)
                sum -= gao(b[r--], -1);
            while (time > q[i].t) {
                if (d[time].pos >= l && d[time].pos <= r) {
                    sum -= gao(d[time].val, -1);
                    sum += gao(d[time].pre, 1);
                }
                b[d[time].pos] = d[time].pre;
                time--;
            }
            while (time < q[i].t) {
                ++time;
                if (d[time].pos >= l && d[time].pos <= r) {
                    sum -= gao(d[time].pre, -1);
                    sum += gao(d[time].val, 1);
                }
                b[d[time].pos] = d[time].val;
            }
            cout << "l =" << l << " r = " << r << " " << sum << endl;
            ans[q[i].id] = 1ll * (r - l + 1) * (r - l) / 2 - sum;
        }
        for (int i = 1; i <= ID; i++)
            printf("%lld\n", ans[i]);
    }
}