#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll mod = 998244353;

ll ksm(ll a, ll x) {
    ll base = 1;
    while (x) {
        if (x & 1) {
            base = base  * a ;
            base %= mod;
        }
        x = x / 2;
        a = (a  * a ) % mod;
    }
    return base % mod;
}

int main() {

    int t; scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        if (n == 0) {
            puts("4");
            continue;
        }
        ll cat = ksm(2, n);

        ll inv = ksm(cat, mod - 2);
        ll cnt = ksm(cat, 2 ) + cat + 6 * (ksm(3, n - 1));
        ll ans = (cnt % mod) * (inv % mod);
        ans %= mod;
        printf("%lld\n", ans);
    }
}