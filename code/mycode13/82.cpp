#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
ll a[N], fn[N], sum[N];
const ll mod = 998244353;

ll ksm(ll x, ll y) {
    ll base = 1;
    while (y) {
        if (y & 1) {
            base = base * x % mod;
        }
        y = y / 2;
        x = x * x % mod;
    }
    return  base;
}

int main() {
    fn[0] = 1;
    for (int i = 1; i < N; i++) {
        fn[i] = fn[i - 1] * 2;
        fn[i] %= mod;
    }
    ll n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll all = 0;
    for (int i = n; i >= 1; i--) {
        sum[i] = sum[i + 1] + fn[i - 1] * a[i] % mod;
        sum[i] %= mod;
       
    }

    ll ans = 0, base = 0;

    for (int i = 1; i <= n; i++) {
        ll cnt = sum[i + 1] * ksm(fn[i], mod - 2) % mod;
       // cout << "cnt " << cnt << endl;
        ans += cnt * a[i] % mod;
        ans += a[i] * a[i] % mod;
        ans %= mod; 
    }
    cout << ans << endl;


    return 0;
}