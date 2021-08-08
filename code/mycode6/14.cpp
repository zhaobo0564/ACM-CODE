#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;

ll x[N], y[N], n, k;
vector<ll> g;
ll sum[N], tree[ 4 * N];
void build(int l, int r, int node) {
    if (l == r) {
        tree[node] = sum[l];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, 2 * node);
    build(m + 1, r, 2 * node + 1);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

ll query(int ql, int qr, int l, int r, int node) {
    if (l > r) return 0;
    if (ql <= l && qr >= r) return tree[node];
    ll ans = 0;
    int m = (l + r) / 2;
    if (ql <= m) ans = max(ans, query(ql, qr, l, m, 2 *  node));
    if (qr > m) ans = max(ans, query(ql, qr, m + 1, r, 2 * node + 1));
    return ans;
}

int main() {
     ios::sync_with_stdio(0);
     int t; cin >> t;
     while (t--) {
         g.clear();
         cin >> n >> k;
         for (int i = 1; i <= n; i++) {
             cin >> x[i];
             g.push_back(x[i]);
         }
         for (int i = 1; i <= n; i++) {
             cin >> y[i];
         }
         sort(g.begin(), g.end());
         for (int i = 0; i < n; i++) {
             int p = upper_bound(g.begin(), g.end(), g[i] + k) - g.begin();
             sum[i + 1] = p - i;
         }
         build(1, n, 1);
         ll ans = 0;
         for (int i = 1; i <= n; i++) {
             cout << sum[i] + i << endl;
             ll cnt = sum[i] + query(sum[i] + i, n, 1, n, 1);
             ans = max(ans, cnt);
         }
         cout << ans << endl;

     }
}