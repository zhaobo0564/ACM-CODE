#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
const ll mod = 1e9 + 7;
ll n, k;

ll ksm(ll x, ll y) {
    ll base = 1;
    x %= mod;
    while (y) {
        if (y & 1) {
            base = base * x;
            base %= mod;
        }
        y = y / 2;
        x = x * x;
        x %= mod;
    }
    return base;
}

void solve() {
    cin >> n >> k;
    cout << ksm(n, k) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}