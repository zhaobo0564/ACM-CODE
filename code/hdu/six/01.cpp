#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 7;

const ll mod = 1e9 + 7;

int t;
ll s[N], sum[N], sum1[N], n;

ll fast_pow(ll a,ll n,ll mo){
  ll base=1;
  a = a % mo;
  while(n){
    if(n&1) base=base*a%mo;
    a=a*a%mo;
    n=n/2;
  }
  return base % mo;;
}

ll inverse(ll a,ll m){
  return fast_pow(a,m-2,m);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        sum[0] = sum1[0] = 0;
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &s[i]);
            sum[i] = (sum[i - 1] + s[i]) % mod;
        }
        for (int i = 1; i <= n; i++) {
            sum1[i] = (sum1[i - 1] + sum[i]) % mod;
        }
        ll base = (n + 1) * n;
        base = base / 2;
        ll ans = 0;
        for (ll i = 1; i <= n; i++) {
            ll cnt = (sum1[n] - sum1[n - i] + mod) % mod;
            cnt = (cnt - sum1[i - 1] + mod) % mod;
          //  cout << cnt << endl;
            ll inv = inverse(base * i, mod);
            cnt = (cnt * inv) % mod;
           // cout <<"cnt " << cnt << endl;
            ans = (ans + cnt) % mod;
        }
        printf("%lld\n", ans);

    }
}