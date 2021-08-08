#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

typedef long long ll;

ll n, a, b, m, fn[N];

const ll mod = 1e9 + 7;

ll eular(ll n){
    ll ans = n;
    for(int i=2; i*i <= n; ++i){
        if(n%i == 0){
            ans = ans/i*(i-1);
            while(n%i == 0)
                n/=i;
        }
    }
    if(n > 1) ans = ans/n*(n-1);
    return ans;
}

ll ksm(ll x, ll y) {
    x = x % mod;
    ll base = 1;
    while (y) {
        if (y & 1) {
            base = base * x;
            base %= mod;
        }
        y = y / 2;
        x = x * x;
        x %= mod;
    }
    return base;
}

int main() {
    ll a, b, m, n;
    cin >> a >> b >> m >> n;
    ll er = eular(mod);
    fn[1] = fn[2] = 1;
    for (int i = 3; i <= n; i++) {
        fn[i] = a * fn[i - 1] % er + b * fn[i - 2] % er;
        fn[i] %= er;
    }
    cout << ksm(m, fn[n] + er) % mod << endl;

    
}