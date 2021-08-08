#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 2e5 + 7;

ll n, a[N], b[N], suma[N], sumb[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= mod;
        suma[i] = suma[i - 1] + a[i];
        suma[i] %= mod;
    }
    for (int j = 1; j <= n; j++) {
        cin >> b[j];
        b[j] %= mod;
        sumb[j] = sumb[j - 1] + b[j];
        sumb[j] %= mod;
    }
    ll ans =((suma[n] - suma[1] + mod) % mod)  * ((sumb[n] - sumb[1] + mod)) % mod;

    cout << ans % mod << " ";
    ans = ((suma[n] - suma[2] + mod) % mod) * b[1] % mod;
    ans += ((sumb[n] - sumb[2] + mod) % mod) * a[1] % mod;
    ans += (a[1] % mod * b[1] % mod) % mod;
    ans %= mod;
    cout << ans << " ";
    ans = a[1] * b[2] % mod;
    ans += a[2] * b[1] % mod;
    cout << ans % mod << " ";
    for (int i = n - 3; i; i--) {
        cout << 0 << " ";
    }
    cout << endl;

    
}