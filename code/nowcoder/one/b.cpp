#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e6 + 7;

ll fn[N], mod = 998244353;

int n;

ll ksm(ll a, ll x) {
    ll base = 1;
    while (x) {
        if(x & 1) base = (base % mod * a % mod) % mod;
        a = (a % mod * a % mod) % mod;
        x = x / 2;
    }
    return base;
}

int main() {
    fn[0] = 1;
    for(ll i = 1; i < N; i++){
        fn[i] = (fn[i - 1] % mod * i % mod) % mod;
    }
    while (~scanf("%d", &n)) {
        ll ans = (fn[n] % mod * fn[n] % mod) % mod;
        ll cnt = fn[2 * n + 1];
        cnt = ksm(cnt, mod - 2);
        ans = (ans % mod * cnt % mod) % mod;
        printf("%lld\n", ans);

    }
}