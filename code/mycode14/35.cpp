#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
int n, a[N], q, rt[N];
int tree[40 * N], ls[40 * N], rs[40 * N], top = 1;
ll SUM[40 * N];
#define m (l + r >> 1)

void update(int pos, int l, int r, int last, int &now) {
    now = top++;
    tree[now] = tree[last] + 1;
    SUM[now] = SUM[last] + 1ll*pos;
    ls[now] = ls[last];
    rs[now] = rs[last];
    if (l == r) {
        return;
    }
    if (pos <= m) update(pos, l, m, ls[last], ls[now]);
    else update(pos, m + 1, r, rs[last], rs[now]);
    
}
ll res = 0;

int query(int k, int l, int r, int last, int now) {
    if (l == r){
        
        ll cnt = 1ll*(tree[now] - tree[last]);
        cnt = cnt - 1ll * k + 1;
        res = cnt * 1ll * l;
        return l;
    } 
    int sum = tree[ls[now]] - tree[ls[last]];
    if (sum >= k) return query(k, l, m, ls[last], ls[now]);
    return query(k - sum, m + 1, r, rs[last], rs[now]);
}

ll qu(int ql, int qr, int l, int r, int last, int now) {
    if (ql > qr) return 0;
    if (ql <= l && qr >= r ) {
        return SUM[now] - SUM[last];
    }
    ll ans = 0;
    if (ql <= m) ans += qu(ql, qr, l, m, ls[last], ls[now]);
    if (qr > m) ans += qu(ql, qr, m + 1, r, rs[last], rs[now]);
    return ans; 
}

ll fn[N];


void solve() {
    scanf("%d", &n);
    for (int i = 0; i <= top; i++) {
        tree[i] = SUM[i] = ls[i] = rs[i] = 0;
    }
    top = 1;
    for (int i = 0; i <= n; i++) {
        rt[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        update(a[i], 1, 1000000, rt[i - 1], rt[i]);
    }
    scanf("%d", &q);
    while (q--) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        int cnt = r - l + 1;
        k = cnt - k + 1;
        res = 0;
        k = query(k, 1, 1000000, rt[l - 1], rt[r]);
       
        ll ans = qu(k + 1, 1000000, 1, 1000000, rt[l - 1], rt[r]);
        //cout << "ans = " << ans << endl;
        ans += fn[cnt] + res;
        printf("%lld\n", ans);


    }

}

int main() {
    for (ll i = 1; i < N; i++) {
        fn[i] = fn[i - 1] + i * i;
    }
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}