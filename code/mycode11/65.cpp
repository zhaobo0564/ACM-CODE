#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lcm(ll x, ll y) {
    return x * y / __gcd(x, y);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll a0, a1, b0, b1;
        scanf("%lld %lld %lld %lld", &a0, &a1, &b0, &b1);
        int ans = 0;
        for (ll i = 1; i * i <= b1; i++) {
            if (b1 % i == 0) {
                ll x = b1 / i;
                if (__gcd(x, a0) == a1 && lcm(x, b0) == b1) {
                    ans++;
                }
                if (b1 / i != i) {
                    x = i;
                    if (__gcd(x, a0) == a1 && lcm(x, b0) == b1) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}