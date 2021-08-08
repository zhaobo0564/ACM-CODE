#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

int main() {
  ll n, k; scanf("%lld %lld", &n, &k);
  ll ans = 0;
  ll l = 2;
  while (l <= k) {
    if (n / l == 0) break;
    ll r = (n / (n / l));
    ans = ((ans + ((min(k, r) - l + 1) % mod) * (n / l) % mod) % mod) % mod;
    l = r + 1;
  }
  l = 2;
  n--;
  while (l <= k) {
    if (n / l == 0) break;
    ll r = (n / (n / l));
    ans = (ans + ((min(k, r) - l + 1) % mod * (n / l) % mod) % mod) % mod;
    l = r + 1;
  }
  ans = (ans + k + n) % mod;
  printf("%lld\n", ans);

 



}