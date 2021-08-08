#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 10007;

ll a, b, k, n, m;

ll ksm(ll x, ll y) {
    ll base  = 1;
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

ll work(ll x, ll y) {
    ll ans = 1;
    for (ll i = y; i > y - x; i--) {
        ans = ans * i % mod;
    }
    ll cnt = 1;
    for (ll i = 1; i <= x; i++) {
        cnt = cnt * i % mod;
    }
    ans = ans * (ksm(cnt, mod - 2) % mod) % mod;
    return ans;
}

int main() {
    cin >> a >> b >> k >> n >> m;
    ll ans = work(n, k);
   // cout << ans << endl;
    ans = ans * (ksm(a, n)) % mod;
    ans = ans * ksm(b, m) % mod;
    cout << ans << endl;
    
}