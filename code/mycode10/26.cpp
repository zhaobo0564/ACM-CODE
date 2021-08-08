#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;

ll ksm(ll x, ll y, ll mod) {
    x = x % mod;
    ll base = 1;
    while (y) {
        if (y & 1) {
            base = base * x;
            base = base % mod;
        }
        x = x * x % mod;
        y = y / 2;
    }
    return base;
}

int main() {
    cin >> n >> m;
    ll ans = ksm(10, n, m * m);
    ll cnt =ksm(10, n, m);
    cout << (ans - cnt) / m << endl; 

}