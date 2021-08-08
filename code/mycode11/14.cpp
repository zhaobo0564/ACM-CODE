#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fn[70];
const ll mod = 998244353;

ll ksm(ll x, ll y) {
    ll base = 1;
    x =  x % mod;
    while (y) {
        if (y & 1) {
            base = base * x % mod;
        }
        y = y / 2;
        x = x * x % mod;
    }
    return base;
}





ll cal(ll n, ll m) {
    if (n == 1 && m == 0) return 2;
    if (n == 0) return 1;
    if (m == 0) return n + 2;
    if (m == 1) return n * 2;
    return ksm(2, n);
}


int main() {
    fn[0] = 1;
    int t; cin >> t;
    ll n, m;
    while (t--) {
      //  memset(dp, -1, sizeof(dp));
        cin >> n >> m;

        cout << cal(n, m) % mod << endl;
        

    }
}