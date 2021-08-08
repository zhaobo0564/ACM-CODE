#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

vector<ll > v;



void solve() {
    ll n; cin >> n;
    int ans = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (n >= v[i]) {
            n -= v[i];
            ans++;
            i++;
        }
    }
    if (n == 0) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ll base = 2050;
    ll cnt = 1;
    for (int i = 0; i <= 15; i++) {
        v.push_back(base * cnt);
        cnt = cnt * 10;
    }

    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}