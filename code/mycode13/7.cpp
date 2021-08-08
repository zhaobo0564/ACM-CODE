#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll ans = 0;
const int N = 1e6 + 7;
ll fn[N];

int main() {
    int t; cin >> t;
    ll base = 1;
    for (int i = 1; i < N; i++) {
        fn[i] = (base % mod * 1ll i % mod) % mod;
        base = base + 2;
        base = base % mod;
        
        
    }
    for (int i = 1; i < N; i++) {
        fn[i] = (fn[i - 1] + fn[i]) % mod;
    }
    while (t--) {
        ll n;
        cin >> n;
        cout << fn[n] << endl;
    }
}