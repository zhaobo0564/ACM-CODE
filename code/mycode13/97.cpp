#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
const ll mod = 1e9 + 7;

ll n, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[1]) {
            cnt++;
        }
    }
    int f = 0;
    for (int i = 1; i <= n; i++) {
        if ((a[1] & a[i]) != a[1]) {
            cout << 0 << endl;
            return;
        }
    }
    ll ans = cnt * (cnt - 1);
    ans %= mod;
    ll cat = n - 2;
    for (int i = 3; i <= n; i++) {
        ans = ans * cat;
        ans %= mod;
        cat--;
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