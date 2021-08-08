#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;

ll a[N], n, q, sum[N];

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    ll res = 0;
    for (ll i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        res += (sum[r] - sum[l - 1]) * i;
    }
    cout << res << endl;

    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}