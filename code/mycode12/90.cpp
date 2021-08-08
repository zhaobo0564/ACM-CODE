#include<bits/stdc++.h>
using namespace std;
const int mod = 100003;
typedef long long ll;
ll m, n;

ll ksm(ll x, ll y) {
    ll base = 1;
    x = x % mod;
    while (y) {
        if (y & 1) {
            base = base * x % mod;
        }
        y = y / 2;
        x = x * x % mod;
    }
    return base;
}

int main() {
    cin >> m >> n;
    ll ans = ksm(m, n);
    ans = ans - m * ksm(m  - 1, n - 1) % mod;
    ans = (ans + mod) % mod;
    cout << ans << endl;
}