#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mul(ll x, ll y, ll p) {
    ll sum = 0;
    while (y) {
        if (y & 1) {
            sum += x;
            sum %= p;
        }
        x = (x + x) % p;
        y = y / 2;
    }
    return sum;
}


ll ksm(ll x, ll y, ll p ) {
    ll base = 1;
    x = x % p;
    while (y) {
        if (y & 1) {
            base = mul(base, x, p) % p;
        }
        x = mul(x, x, p) % p;
        y = y / 2;
    }
    return base;
} 

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

int main() {
    ll l;
    int top = 1;
    while (~scanf("%lld", &l) && l) {
        ll d = __gcd(1ll*8, l);
        ll p = 9 * l / d;
        if (__gcd(1ll*10, p) != 1) {
            printf("Case %d: 0\n", top++);
        } else {
            ll cnt = euler_phi(p);
            ll ans = LLONG_MAX;
          //  cout << cnt << endl;
            for (ll i = 1; i * i <= cnt; i++) {
                
                if (cnt % i == 0) {
                    ll res = ksm(10, i, p);
                    if (res == 1) {
                        ans = min(ans, i);
                    }
                    res = ksm(10, cnt / i, p);
                    if (res == 1) {
                        ans = min(ans, cnt / i);
                    }
                }
            }
            printf("Case %d: %lld\n", top++, ans);
        }
    }
}