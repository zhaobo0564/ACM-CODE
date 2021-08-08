#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 7;

ll n, a[N], x[N];

void solve() {
    int q;
    cin >> n >> q;
    for (int i = 0; i <= n + 1; i++) {
        x[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

    }
    a[n + 1] = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        x[i] = a[i] - a[i + 1];
        if (x[i] > 0) ans += x[i];
    }

    cout << ans << endl;

    while (q--) {
        int l, r; cin >> l >> r;
        swap(a[l], a[r]);
        if (l == r) {
            cout << ans << endl;
            continue;
        }
        if (x[l] > 0) ans -= x[l];
        if (x[r] > 0) ans -= x[r];
        if (x[l - 1] > 0) ans -= x[l - 1];
        if (x[r - 1] > 0 && r - 1 != l) ans -= x[r - 1];

      
        x[l - 1] = a[l - 1] - a[l];
        x[l] = a[l] - a[l + 1];
        x[r] = a[r] - a[r + 1];
        x[r - 1] = a[r - 1] - a[r];
        if (x[l] > 0) {
            ans += x[l];
        } 
        if (x[r] > 0) {
            ans += x[r];
        }
        if (l - 1 && x[l - 1] > 0) {
            ans += x[l - 1];
        }
        if (r - 1 && l != r - 1&& x[r - 1] > 0) {
            ans += x[r - 1];
        }
        cout << ans << endl;  
    }

}



int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}