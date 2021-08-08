#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll euler_phi(ll n) {
  ll ans = n;
  for (ll i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        ans = ans / i * (i - 1);
        while (n % i == 0) n /= i;
    }
  }
  if (n > 1) ans = ans / n * (n - 1);
  return ans;
}

ll multi(ll a,ll b,ll mod) { // ¿ìËÙ³Ë·¨
    ll ans = 0;
    while(b) {
        if(b & 1)
            ans = (ans + a) % mod;
        a = (a + a) % mod;
        b = b >> 1;
    }
    return ans;
}

ll ksm(ll x, ll y, ll p) {
    x = x % p;
    ll base = 1;
    while (y) {
        if (y & 1) {
            base = multi(base, x, p);
        }
        x = multi(x, x, p);
        y = y / 2;
    }
    return base % p;
}

int main() {
    ll l;
    int ca = 1;
    while (cin >> l && l) {
        ll d = __gcd(l, 1ll*8);
        ll p = 9 * l / d;
        if (__gcd(1ll*10, p) != 1) {
            printf("Case %d: %lld\n", ca++, 1ll*0);
        } else {
            ll ans = LLONG_MAX;
            ll cnt = euler_phi(p);
            for (ll i = 1; i * i <= cnt; i++) {
                if (cnt % i == 0) {
                    ll res = ksm(10, i, p);
                 
                    if (res == 1) {
                        ans = min(ans, i);
                    }
                    if (cnt / i != i) {
                        res = ksm(10, cnt / i, p);
                        if (res == 1) {
                            ans = min(ans, cnt / i);
                        }
                    }
                }
            }
            printf("Case %d: %lld\n", ca++, ans);
        }
    }
}