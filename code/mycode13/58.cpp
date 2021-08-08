#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;

int work(ll x) {
    ll sum = 0, cnt = x;
    while (cnt) {
        sum += cnt % 10;
        cnt /= 10;
    }
    if (__gcd(sum, x) != 1) return 1;
    return 0;
}

void solve() {
    ll n; cin >> n;
    for (ll i = n; i; i++) {
        if (work(i)) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}