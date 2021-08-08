#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 7;

int vis[N], prime[N], top = 1;

void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[top++] = i;
        for (int j = 1; j < top && i * prime[j] < N; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;

        }
    }
}

ll fn[N];

ll ksm(ll x, ll y, ll mod) {
   
    ll base = 1;
    x = x % mod;
    while (y) {
        if (y & 1) {
            base = base * x % mod;
        }
        x = x * x % mod;
        y = y / 2;
    }
    return base;
}

int main() {
    int t; cin >> t;
    init();
    ll p = 1e9+7;
    ll cnt = 0;
    for (int i = 2; i < top; i++) {
        if (prime[i] - prime[i - 1] == 2) {
            cnt++;
        }
        fn[prime[i]] = cnt;
    }

    for (int i = 1; i < N; i++) {
        fn[i] = max(fn[i - 1], fn[i]);
    }
    

    while (t--) {
        ll n; cin >> n;
        ll ans = fn[n];
        ll cn = ksm(((n * (n - 1)) / 2) , p - 2, p);
        ans = (ans % p * cn % p) % p;
        cout << ans << endl;

    

    }
}