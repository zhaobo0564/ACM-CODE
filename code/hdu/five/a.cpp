#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 6e6 + 7;

ll fn[N];

int t, n;
ll MOD = 998244353;

ll ans = 0;

ll fast_pow(ll a,ll n,ll mod){
  ll base=1;
  a = a % mod;
  while(n){
     // ans++;
    if(n&1) base=(base%mod * a%mod)%mod;
    a=(a % mod * a % mod )%mod;
    n=n/2;
  }
  return base % mod;
}

ll inverse(ll a,ll m){
  return fast_pow(a,m-2,m);
}





int main() {
    init();
    ll cnt;
    for (ll i = 1; i < N; i++) {
        cnt = (inv[i] % MOD * inv[i] % MOD ) % MOD;
        fn[i] = (fn[i - 1] % MOD + cnt % MOD) % MOD;
    }
    for (ll i = 1; i < N; i++) {
        fn[i] = (fn[i] % MOD * (inv[i] % MOD)) % MOD;
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%lld\n", (3 * fn[n]) % MOD);
    }
}