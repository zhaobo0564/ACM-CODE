#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
const int N = 2e5 + 7;

void solve() {
    ll n;
    cin >> n;
    ll ans = 1ll*1 << n;
    for (int i = 1; i < n / 2; i++) {
        ans += 1ll * 1 << i;
    }
    for (int i = n / 2; i < n; i++) {
        ans -= 1ll * 1 << i;
    }
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}