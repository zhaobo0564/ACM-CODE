#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 27;
ll n, m, a[N];

ll fpow(ll a, ll x) {
    ll base = 1;
    while(x){
        if(x & 1){
            base = base * a % mod;
        }
        a = a * a %mod;
        x = x / 2;
    }
    return base;
}

ll C(int n, int m) {  // Çóc[n][m]
    if (m > n) return 0;
    ll res = 1;
    for(int i = n; i > n - m; i--){
        res = res * i % mod;
    }
    ll res1 = 1;
    for(int i = 1; i <= m; i++){
        res1 = res1 * i % mod;
    }
    res = res * fpow(res1, mod - 2)%mod;
    return res ;
}

ll Lucas(ll x, ll y) {
    if (y == 0) return 1;
    if (y <= x && x < mod) {
        return C(x, y);
    }
    return C(x % mod, y % mod) * Lucas(x / mod, y / mod) % mod;
}

ll ans = 0;

void dfs(int p, int sum, ll value) {
    if (sum > n) return;
    if (sum % 2 == 0) {
        ans += Lucas(m + n - value - sum - 1, n - 1);
        ans = ans % mod;
    } else {
        ans -= Lucas(m + n - value - sum - 1, n - 1);
        ans = (ans + mod) % mod;
    }

    for (int i = p; i <= n; i++) {
        dfs(i + 1, sum + 1, value + a[i]);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0, 0);
    cout << ans << endl;

}