#include<bits/stdc++.h>
using namespace std;
const int N = 3007;

typedef long long ll;
const ll mod = 1e9 + 7;
ll dp[N];
int n;
char s[N];




int main() {
    cin >> (s + 1);
    n = strlen(s + 1);
    ll ans = 1;
    for (ll i = 2; i < n; i++) {
        ll sum = 0;
        ll base = 0;
        for (int j = n; j > i; j--) {
            ll cnt = dp[j];
            if (s[i - 1] == s[j]) {
                dp[j] = (dp[j] + 1 + sum) % mod;
            }
            sum = (sum + cnt) % mod;
            base += dp[j];
            base %= mod;
        }
      //  cout << base << endl;
        ans = (ans ^ (((base + 1) % mod * i % mod) % mod));

    }
    if (n > 1)
    ans = ans ^ n;
    cout << ans << endl;
    
}