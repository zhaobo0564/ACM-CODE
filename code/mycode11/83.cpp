#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, fn[10007];

void solve() {
    cin >> x;

    for (ll i = 1; i <= 10000; i++) {
        ll b = i * i * i;
        ll a = x - b;
        if (a <= 0) continue;
        int p = lower_bound(fn + 1, fn + 10001, a) - fn;
        if (fn[p] == a) {
            cout << "YES\n";
            return;
        }

    }
    cout << "NO\n";
    
}


int main() {
    for (ll i = 1; i <= 10000; i++) {
        fn[i] = i * i * i;
    }
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }    
}