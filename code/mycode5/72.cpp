#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll work(ll x) {
    x = x * (x - 1) * (x - 2);
    x = x / 3;
    return (x % mod);
}

int main() {
    ll n;
    scanf("%lld", &n);
    ll fn = 1;
    for (ll i = 1; i <= n ; i++) {
        fn = fn * i % mod; 
    }
    ll cnt = 1;
    for (int i = 1; i < n; i++) {
        cnt = cnt * 2;
        cnt %= mod;
    }
    fn = (fn - cnt + mod) % mod;
    
    printf("%lld\n", fn);
    

}